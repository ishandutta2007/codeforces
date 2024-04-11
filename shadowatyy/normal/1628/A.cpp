#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define VI vector<int>
#define VPII vector<PII>
#define LL long long
#define LD long double
#define f first
#define s second
#define MP make_pair
#define PB push_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for(int i = (b); i <= (int)(e); ++i)
#define FORD(i, b, e) for(int i = (b); i >= (int)(e); --i)
#define ll LL
#define st f
#define nd s
#define pb PB
#define mp MP
#define eb emplace_back
#define siz(c) SIZ(c)
const int inf = 1e9+7;
const ll INF = 1e18L+7;

#define sim template<class n
sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.f << ", " << x.s << ">";}
sim> auto operator << (ostream &p, n y) ->
typename enable_if<!is_same<n, string>::value, decltype(y.begin(), p)>::type 
{int o = 0; p << "{"; for(auto c: y) {if(o++) p << ", "; p << c;} return p << "}";}
void dor() {cerr << endl;}
sim, class...s> void dor(n p, s...y) {cerr << p << " "; dor(y...);}
sim, class s> void mini(n &p, s y) {if(p>y) p = y;}
sim, class s> void maxi(n &p, s y) {if(p<y) p = y;}
#ifdef DEB
#define debug(...) dor(__FUNCTION__, ":", __LINE__, ": ", __VA_ARGS__)
#else
#define debug(...)
#endif 

#define I(x) #x " =", (x), " "

#ifndef LOCAL
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <typename T>
using ordered_set =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#else
#include</Users/dawid/algo/mac/ordered_set>
#endif

const int N = 2e5 + 7;

int n;

int a[N];
int cnt[N];
int rem[N];

void clear() {
	for (int i = 0; i <= n; ++i) {
		a[i] = cnt[i] = rem[i];
	}
}

void solve() {
	debug("s1");
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		++cnt[a[i]];
	}

	debug("s2");

	VI ans;
	int l = 1;

	while (l <= n) {
		int mex = 0;
		while (cnt[mex])
			++mex;

		ans.pb(mex);

		debug(I(mex));

		int r = l - 1;
		int sat = 0;
		while (sat < mex) {
			++r;
			int val = a[r];
			if (val < mex) {
				if (rem[val] == 0)
					++sat;
				++rem[val];
			}
		}

		if (r < l)
			r = l;

		debug(l, r);

		for (int i = l; i <= r; ++i) {
			cnt[a[i]]--;
			rem[a[i]] = 0;
		}

		l = r + 1;
	}

	debug("s3");

	cout << ans.size() << endl;

	for (auto it : ans)
		cout << it << " ";

	cout << endl;

	clear();
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--)
		solve();
}