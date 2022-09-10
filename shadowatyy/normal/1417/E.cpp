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

const int N = 3e5+7;

int n;

int a[N];

pair<ll, ll> calc(int bit, int mask) //z zerem, z jedynka
{
	unordered_map<int, VI> M;

	for(int i = 1; i <= n; ++i)
	{
		M[a[i]&mask].pb(a[i]);
	}

	ll zero = 0;
	ll jeden = 0;

	for(auto it:M)
	{
		VI vec = it.nd;
		int cnt[2] = {0, 0};

		for(auto e:vec)
		{
			if(e&(1<<bit))
			{
				jeden += cnt[0];
				++cnt[1];
			}
			else
			{
				zero += cnt[1];
				++cnt[0];
			}
		}
	}

	return mp(zero, jeden);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	int mask = 0;
	ll cnt = 0;
	int ans = 0;

	for(int b = 29; b >= 0; --b)
	{
		auto para = calc(b, mask);

		if(para.st)
			debug(b, para.st, para.nd);

		if(para.st <= para.nd)
			cnt += para.st;
		else
		{
			cnt += para.nd;
			ans |= 1<<b;
		}

		mask |= 1<<b;
	}

	cout << cnt << " " << ans << endl;
}