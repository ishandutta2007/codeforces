#include <cstdio>
#include <algorithm>

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1E5 + 10, MAXA = 1 << 20;
const int N = 512;

int n, m, k;
int a[MAXN];
int l[MAXN], r[MAXN];
ll c[MAXN];
pair<PII, int> b[MAXN];

int cl, cr;
int cnt[MAXA];
ll tot;

int add(int x){
	tot += cnt[a[x] ^ k];
	++cnt[a[x]];
}

int del(int x){
	--cnt[a[x]];
	tot -= cnt[a[x] ^ k];
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		a[i] ^= a[i - 1];
	}
	for (int i = 0; i < m; ++i){
		scanf("%d%d", &l[i], &r[i]);
		--l[i];
		b[i] = make_pair(PII(l[i] >> 9, r[i]), i);
	}
	sort(b, b + m);
	cl = 1, cr = 0;
	for (int i = 0; i < m; ++i){
		int u = b[i].nd;
		for (; l[u] < cl; add(--cl));
		for (; cr < r[u]; add(++cr));
		for (; cl < l[u]; del(cl++));
		for (; r[u] < cr; del(cr--));
		c[u] = tot;
	}
	for (int i = 0; i < m; ++i)
		printf("%I64d\n", c[i]);
	return 0;
}