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

const int N = 1007;

int n, ile;

bitset<N> g[N];
//int f[N];
int gdzie_f[N];
int ans[N];

ll x[N];
ll y[N];

map<ll, vector<PII> > M;

bitset<N> curr;

ll dist(int a, int b)
{
	return (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);
}

void add(int a, int b, int c, int d)
{
	debug(a, b, c, d);

	curr[a] = !curr[a];
	curr[b] = !curr[b];
	curr[c] = !curr[c];
	curr[d] = !curr[d];
	
	for(int i = 1; i <= n; ++i)
	{
		if(gdzie_f[i] && curr[i])
			curr ^= g[gdzie_f[i]];
	}

	if(!curr.count())
		return;

	++ile;
	gdzie_f[curr._Find_first()] = ile;
	swap(g[ile], curr);
	curr.reset();
}

void check(int x)
{
	curr.reset();
	curr[1] = 1;
	curr[x] = 1;
	curr[n+1] = 1;

	for(int i = 1; i <= n; ++i)
	{
		if(gdzie_f[i] && curr[i])
			curr ^= g[gdzie_f[i]];
	}

	if(curr.count()==1)
		return;

	++ile;
	gdzie_f[curr._Find_first()] = ile;
	swap(g[ile], curr);

	for(int i = 1; i <= n; ++i)
	{
		ans[i] = -1;
	}

	/*for(int i = 1; i <= ile; ++i)
	{
		for(int j = 1; j <= n+1; ++j)
		{
			cerr << g[i][j] << " ";
		}

		cerr << endl;
	}*/

	for(int i = ile; i >= 1; --i)
	{
		int curr = g[i][n+1];

		for(int j = n; j >= 1; --j)
		{
			if(g[i][j])
			{
				if(ans[j]!=-1)
					curr ^= ans[j];
				else
				{
					ans[j] = curr;
					curr ^= ans[j];
				}
			}
		}
	}

	int cnt = 0;

	for(int i = 1; i <= n; ++i)
	{
		if(ans[i]==ans[1])
			++cnt;
	}

	cout << cnt << endl;

	for(int i = 1; i <= n; ++i)
	{
		if(ans[i]==ans[1])
			cout << i << " ";
	}

	cout << endl;
	exit(0);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> x[i] >> y[i];

		for(int j = 1; j < i; ++j)
		{
			M[dist(i, j)].eb(i, j);
		}
	}

	srand(12312);

	vector<pair<PII, PII> > vec;

	for(auto it:M)
	{
		for(int i = 0; i+1 < siz(it.nd); ++i)
		{
			vec.eb(mp(it.nd[i].st, it.nd[i].nd), mp(it.nd[i+1].st, it.nd[i+1].nd));
		}
	}

	random_shuffle(ALL(vec));

	int cnt = 0;

	for(auto it:vec)
	{
		if(ile==n-1 || (cnt%100==0 && clock() > 0.9 * CLOCKS_PER_SEC))
			break;

		add(it.st.st, it.st.nd, it.nd.st, it.nd.nd);
	}	

	for(int i = 2; i <= n; ++i)
	{
		check(i);
	}

	assert(0);
}