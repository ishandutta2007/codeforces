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
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, b, e) for (int i = (b); i <= (int)(e); i++)
#define FORD(i, b, e) for (int i = (b); i >= (int)(e); i--)
#define ll long long
#define st f
#define nd s
#define pb PB
#define eb emplace_back
#define mp make_pair				
#define siz(c) SIZ(c)
const int inf = 1e9 + 7;
const LL INF = 1e18L + 7;
 
#define sim template<class n
sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.f << ", " << x.s << ">";}
sim> auto operator << (ostream &p, n y) ->
typename enable_if<!is_same<n, string>::value, decltype(y.begin(), p)>::type
{int o = 0; p << "{"; for (auto c : y) {if (o++) p << ", "; p << c;} return p << "}";}
void dor() {cerr << endl;}
sim, class...s> void dor(n p, s...y) {cerr << p << " "; dor(y...);}
sim, class s> void mini(n &p, s y) {if (p > y) p = y;}
sim, class s> void maxi(n &p, s y) {if (p < y) p = y;}

#ifdef DEB
#define debug(...) dor(__FUNCTION__, ":", __LINE__, ": ", __VA_ARGS__)
#else
#define debug(...)
#endif

#define I(x) #x " = ", (x), " "
#define A(a, i) #a "[" #i " = ", i, "] = ", a[i], " "

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

const int N = 1<<18;

int n;

int p[N];
int gdzie[N];

struct tree
{
	int ban[2*N];
	int load[2*N];
	ll sub[2*N];

	void merge(int v, int l, int r)
	{
		ban[v] = ban[2*v] + ban[2*v+1];
		sub[v] = sub[2*v] + sub[2*v+1] + (ll)load[v] * (r-l+1-ban[v]);
	}

	void insert(int a, int b, int c, int v = 1, int l = 0, int r = N-1)
	{
		if(a>r || l>b)
			return;

		if(a<=l && r<=b)
		{
			load[v] += c;
			sub[v] += (ll)c*(r-l+1-ban[v]);
			return;
		}

		insert(a, b, c, 2*v, l, (l+r)/2);
		insert(a, b, c, 2*v+1, (l+r)/2+1, r);
		merge(v, l, r);
	}

	ll query(int a, int b, int path = 0, int v = 1, int l = 0, int r = N-1)
	{
		if(a>r || l>b)
			return 0;

		if(a<=l && r<=b)
			return sub[v] + (ll)path * (r-l+1-ban[v]);

		return query(a, b, path+load[v], 2*v, l, (l+r)/2) + query(a, b, path+load[v], 2*v+1, (l+r)/2+1, r);
	}

	int jeden(int v)
	{
		int ans = 0;
		v += N;

		while(v)
		{
			ans += load[v];
			v /= 2;
		}

		return ans;
	}

	int query_ban(int a, int b, int v = 1, int l = 0, int r = N-1)
	{
		if(a>r || l>b)
			return 0;

		if(a<=l && r<=b)
			return ban[v];

		return query_ban(a, b, 2*v, l, (l+r)/2) + query_ban(a, b, 2*v+1, (l+r)/2+1, r);
	}

	void make_ban(int x, int v = 1, int l = 0, int r = N-1)
	{
		if(l==r)
		{
			ban[v] = 1;
			sub[v] = 0;
			return;
		}

		if(x<=(l+r)/2)
			make_ban(x, 2*v, l, (l+r)/2);
		else
			make_ban(x, 2*v+1, (l+r)/2+1, r);

		merge(v, l, r);
	}

}lewo, prawo;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> p[i];
		gdzie[p[i]] = i;
	}

	ll ins = 0;

	for(int i = 1; i <= n; ++i)
	{
		ins += lewo.query_ban(gdzie[i]+1, n);
		lewo.insert(gdzie[i]+1, n, 1);
		prawo.insert(1, gdzie[i]-1, 1);
		lewo.make_ban(gdzie[i]);
		prawo.make_ban(gdzie[i]);

		int l = 1, r = n;

		while(l<r)
		{
			int m = (l+r)/2;
			int x = lewo.jeden(m) - prawo.jeden(m);

			if(x < 0)
				l = m+1;
			else
				r = m;
		}

		ll ans = ins + lewo.query(1, l) + prawo.query(l+1, n);

		cout << ans << " ";
	}

	cout << endl;
}