#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 2E5 + 10;
const ll MOD = 1E9 + 7;

ll inv[MAXN];
ll com[MAXN], cominv[MAXN];

void modInv(int n = MAXN, ll m = MOD){
	inv[0] = 0, inv[1] = 1;
	com[0] = com[1] = 1;
	cominv[0] = cominv[1] = 1;
	for (int i = 2; i < MAXN; ++i){
		inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
		com[i] = com[i - 1] * i % MOD;
		cominv[i] = cominv[i - 1] * inv[i] % MOD;
	}
}

ll C(int n, int m){
	return n < m ? 0 : com[n] * cominv[m] % MOD * cominv[n - m] % MOD;
}

int main(){
	modInv();

	int n, K;
	scanf("%d%d", &n, &K);
	vector<PII> a;
	for (int l, r, i = 0; i < n; ++i){
		scanf("%d%d", &l, &r);
		a.push_back(PII(l, 1));
		a.push_back(PII(r + 1, -1));
	}
	sort(a.begin(), a.end());
	int ans = 0, cnt = 0;
	for (int i = 0; i + 1 < a.size(); ++i){
		cnt += a[i].nd;
		ans = (ans + C(cnt, K) * (a[i + 1].st - a[i].st)) % MOD;
	}
	printf("%d\n", ans);

	return 0;
}