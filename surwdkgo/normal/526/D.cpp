#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;
#define BAS  2791
#define MOD 1000000009
#define MAXN 1000010

typedef long long LL;
struct Hash{
	LL h1, h2;
	Hash():h1(0), h2(0) {
	}
	Hash(LL _h1, LL _h2) : h1(_h1), h2(_h2) {

	}
	Hash nex(char x) {
		return Hash(h1 * BAS + x, (h2 * BAS + x) % MOD);
	}
} has[MAXN];

LL pob[MAXN], pom[MAXN];
char inp[MAXN];

bool cmp(int a, int b, int l) {
	if (has[a+l].h1 - has[a].h1 * pob[l] != has[b+l].h1 - has[b].h1 * pob[l]) return 0;
	return (has[a+l].h2 - has[a].h2 * pom[l] % MOD + MOD) % MOD == (has[b+l].h2 - has[b].h2 * pom[l] % MOD + MOD) % MOD;
}

int n, k;
int maxL(int a) {
	int L = 0, R = n-a+1, M;
	while (L+1 < R) {
		M = (L+R)/2;
		if (cmp(0, a, M)) L = M;
		else R = M;
	}
	return L;
}

char ans[MAXN];
int len[MAXN];

typedef pair<int, int> P;
P que[MAXN];
int pus, pop;
int main() {
	pob[0] = 1;
	pom[0] = 1;
	for (int i=1; i<MAXN; i++) {
		pob[i] = pob[i-1] * BAS;
		pom[i] = pom[i-1] * BAS % MOD;
	}
	scanf("%d%d", &n, &k);
	scanf("%s", inp);
	for (int i=0; i<n; i++) {
		has[i+1] = has[i].nex(inp[i]);
	}
	for (int i=0; i<n; i++) {
		len[i] = i > 0 ? maxL(i) : 0;
	}
	int rb = 0;
	for (int i=0; i<n; i++) {
		int nlb = (i+1+k) / (k+1), nrb = (i+1) / k;
		while (pus > pop && que[pop].first < nlb) pop++;
		while (rb < nrb) {
			int in = rb+1;
			int ln = len[in];
			while (pus > pop && que[pus-1].second <= in+ln) {
				pus--;
			}
			que[pus++] = P(in, in+ln);
			rb++;
		}
		if (pus > pop) {
			ans[i] = que[pop].second > i ? '1' : '0';
		} else {
			ans[i] = k > 1 ? '0' : '1';
		}
	}
	puts(ans);
	return 0;
}