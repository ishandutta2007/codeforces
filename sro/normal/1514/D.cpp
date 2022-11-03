#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define parse(it, x) for (auto &it : (x))
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

mt19937_64 Rand(chrono::steady_clock::now().time_since_epoch().count());
ll inline rand(ll L, ll R) { return uniform_int_distribution<ll>(L, R)(Rand); }

int n, q;
int a[300005];
vector<int> occ[300005];

int main() {
	scanf("%d%d", &n, &q);
	cont(i, n) scanf("%d", a + i), occ[a[i]].pub(i);
	while (q--) {
		int l, r; scanf("%d%d", &l, &r);
		vector<int> nums;
		loop(i, 40) nums.pub(a[rand(l, r)]);
		sort(all(nums)); nums.erase(unique(all(nums)), nums.end());
		int ans = 0;
		parse(v, nums) {
			ans = max(ans, (int)(upper_bound(all(occ[v]), r) - lower_bound(all(occ[v]), l)));
		}
		int fans = r - l + 1 - ans;
		if (ans > fans) ans -= fans;
		else ans = 1;
		printf("%d\n", ans);
	}
	return 0;
}