#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MOD 1000000007
#define BAS 3571
#define MAXN 1000010

typedef long long LL;
LL h1[MAXN], h2[MAXN];
LL b1[MAXN], b2[MAXN];
int l;

int check(int d) {
	//printf("%d\n", d);
	if (d <= 0) return 1;
	if (h1[d] - h1[0] * b1[d] != h1[l] - h1[l-d] * b1[d]) return 0;
	return ((h2[d] + h2[l-d] * b2[d]) %MOD == (h2[l] + h2[0] * b2[d]) % MOD) ? 1 : 0;
}

int n, m;
char inp[MAXN];
int chk[MAXN];

int main() {
	scanf("%d%d%s", &n, &m, inp);
	for (int i=0; i<m; i++) scanf("%d", &chk[i]);
	b1[0] = b2[0] = 1;
	for (int i=0; i<MAXN-1; i++) {
		b1[i+1] = b1[i] * BAS;
		b2[i+1] = b2[i] * BAS % MOD;
	}
	l = strlen(inp);
	for (int i=0; i<l; i++) {
		h1[i+1] = h1[i] * BAS + inp[i];
		h2[i+1] = (h2[i] * BAS + inp[i]) % MOD;
	}	
	LL ans = 1;
	int free = 0;
	for (int i=1; i<m; i++) {
		ans = ans * check(l - (chk[i] - chk[i-1]));
		free += max(0, (chk[i] - chk[i-1]) - l);
	}
	if (m) {
		free += chk[0];
		free += n - l - chk[m-1];
	} else free = n;
	for (int i=0; i<free; i++) ans = ans * 26 % MOD;
	printf("%d\n", (int)ans);
	return 0;

	
}