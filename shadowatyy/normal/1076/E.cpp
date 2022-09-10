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

#define int ll
const int N = 1<<19;

int n, m, c;

VI G[N];

int v[N];
int d[N];
int x[N];

int pre[N];
int post[N];
int dep[N];

int load[2*N];

VI dodaj[2*N];
VI pytaj[2*N];

int ans[N];

void insert(int a, int b, int x)
{
	a += N-1;
	b += N+1;

	while(a<b-1)
	{
		if(a%2==0)
			load[a+1] += x;

		if(b%2==1)
			load[b-1] += x;

		a /= 2;
		b /= 2;
	}
}

int query(int a)
{
	int res = 0;
	a += N;

	while(a)
	{
		res += load[a];
		a /= 2;
	}

	return res;
}

void dfs(int v)
{
	pre[v] = ++c;

	for(auto it:G[v])
	{
		if(!pre[it])
		{
			dep[it] = dep[v]+1;
			dfs(it);
		}
	}

	post[v] = c;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;
		G[x].pb(y);
		G[y].pb(x);
	}

	cin >> m;

	for(int i = 1; i <= m; ++i)
	{
		cin >> v[i] >> d[i] >> x[i];
		d[i] = min(d[i], n);
	}

	dfs(1);

	for(int i = 1; i <= n; ++i)
	{
		pytaj[dep[i]].pb(i);
	}

	for(int i = 1; i <= m; ++i)
	{
		dodaj[dep[v[i]]+d[i]].pb(i);
	}

	for(int i = 2*N-1; i >= 0; --i)
	{
		for(auto it:dodaj[i])
		{
			insert(pre[v[it]], post[v[it]], x[it]);
		}

		for(auto it:pytaj[i])  
		{
			ans[it] = query(pre[it]);
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		cout << ans[i] << " ";
	}

	cout << endl;
}