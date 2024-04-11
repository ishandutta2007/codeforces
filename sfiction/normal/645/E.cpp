#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1E6 + 10, SIGMA = 26;
const ll MOD = 1E9 + 7;

int n, k;
char s[MAXN];
ll a[SIGMA], tot;
PII occ[SIGMA];

int main(){
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	tot = 1;
	for (int i = 0; i < k; ++i)
		a[i] = 0, occ[i] = PII(-1, i);
	for (int i = 0; s[i]; ++i){
		int u = s[i] - 'a';
		occ[u].st = i;
		ll t = (tot - a[u] + MOD) % MOD;
		a[u] = (a[u] + t) % MOD;
		tot = (tot + t) % MOD;
	}
	sort(occ, occ + k);

	for (int i = 0; i < n; ++i){
		int u = occ[i % k].nd;
		ll t = (tot - a[u] + MOD) % MOD;
		a[u] = (a[u] + t) % MOD;
		tot = (tot + t) % MOD;
	}
	printf("%I64d\n", tot);
	return 0;
}