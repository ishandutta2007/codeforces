#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define ll long long
#define VI vector<int>
#define VLL vector<ll>
#define PII pair<int, int>
#define VPII vector<PII>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
const int inf = 1e9L+7;
const ll INF = 1e18L+7;

#define Sim template <class n
Sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{ return p << "<" << x.first << ", " << x.second << ">"; }
Sim> auto operator << (ostream &p, n y) -> 
typename enable_if <!is_same<n, string>::value, decltype(y.begin(), p)>::type 
{ int o = 0; p << "{"; for(auto c: y) { if(o++) p << ", "; p << c; } return p << "}"; }
void dor() { cerr << endl; }
Sim, class...s> void dor(n p, s...y) { cerr << p; dor(y...); }
Sim, class s> void mini(n &p, s y) { if(p > y) p = y; }
Sim, class s> void maxi(n &p, s y) { if(p < y) p = y; }
#ifdef DEB
#define debug(...) dor(__FUNCTION__, ":", __LINE__, ": ", __VA_ARGS__)
#else
#define debug(...)
#endif 

#define I(x) #x " = ", (x), " "
#define A(a, i) #a "[" #i " = ", i, "] = ", a[i], " "

const int N = 3e5+7;
#define int ll

int n, m, k;

VPII G[N];

int w[N];

int dist[N];
int ok[N];

struct comp
{
	bool operator()(int a, int b)
	{
		return mp(dist[a], a)<mp(dist[b], b);
	}
};

set<int, comp> S;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> k;

	for(int i = 1; i <= m; ++i)
	{
		int x, y;
		cin >> x >> y >> w[i];
		G[x].eb(y, i);
		G[y].eb(x, i);
	}

	for(int i = 2; i <= n; ++i)
	{
		dist[i] = INF;
	}

	S.insert(1);

	while(!S.empty())
	{
		int v = *S.begin();
		S.erase(S.begin());

		for(auto it:G[v])
		{
			if(dist[v]+w[it.nd]<dist[it.st])
			{
				S.erase(it.st);
				dist[it.st] = dist[v]+w[it.nd];
				S.insert(it.st);
			}
		}
	}

	VI vec;

	for(int i = 1; i <= n; ++i)
	{
		vec.pb(i);
	}

	sort(ALL(vec), [](int a, int b)
	{
		return dist[a]<dist[b];
	});

	VI ans;
	ok[1] = 1;

	for(int i = 0; i < n && ans.size()<k; ++i)
	{
		int v = vec[i];

		for(auto it:G[v])
		{
			if(ok[it.st] && dist[v]==dist[it.st]+w[it.nd])
			{
				ans.pb(it.nd);
				break;
			}
		}

		ok[v] = 1;
	}

	cout << ans.size() << endl;

	for(auto it:ans)
		cout << it << " ";

	cout << endl;
}