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
 
/* DINIC O(n^2*m) lub O(MAXFLOW*(n+m)).                                       */
/* Dla grafw z krawdziami jednostykowymi dziaa w O(m*sqrt(n)).             */
 
//using ll=long long;
 
#define int ll

struct flow
{
	int n, zr, uj;
	vector<vector<pair<int,pair<ll*,ll*>>>> graf;
	vector<vector<pair<int,pair<ll*,ll*>>>> dgraf;
	vector<vector<ll>> ori;//do odzyskiwania flowu
	vector<int> odl;
	flow(){}
	flow(int vertex_limit) {
		graf.resize(vertex_limit + 1);
		dgraf.resize(vertex_limit + 1);
		odl.resize(vertex_limit + 1, 0);
		ori.resize(vertex_limit + 1);//do odzyskiwania flowu
	}
	bool iszero(ll v) {
		return (!v);//zmienic dla dabli
	}
	void add_edge(int v, int u, ll lim, bool bi_dir=false) {
		ll *a=new ll(lim);
		ll *b=new ll(lim*bi_dir);
		graf[v].push_back({u,{a, b}});
		graf[u].push_back({v,{b, a}});
		ori[v].push_back(lim);//do odzyskiwania flowu
		ori[u].push_back(lim*bi_dir);//do odzyskiwania flowu
	}
	void bfs() {
		for (int i=1; i<=n; i++) {
			odl[i]=0;
			dgraf[i].clear();
		}
		queue <int> kol;
		kol.push(zr);
		odl[zr]=1;
		while(!kol.empty()) {
			int v=kol.front();
			kol.pop();
			for (auto i : graf[v]) {
				if (!odl[i.first] && !iszero(*i.second.first)) {
					odl[i.first]=odl[v]+1;
					kol.push(i.first);
				}
				if (odl[i.first]==odl[v]+1 && !iszero(*i.second.first))
					dgraf[v].push_back(i);
			}
		}
	}
	ll dfs(int v, ll lim) {
		if (v==uj)
			return lim;
		ll ret=0;
		for (int i=0; i<(int)dgraf[v].size() && !iszero(lim); i++) {
			auto &j=dgraf[v][i];
			ll wez=0;
			if (!iszero(*j.second.first))
				wez=dfs(j.first, min(*j.second.first, lim));
			if (iszero(wez)) {
				swap(dgraf[v][i], dgraf[v].back());
				dgraf[v].pop_back();
				i--;
				continue;
			}
			ret+=wez;
			(*j.second.first)-=wez;
			(*j.second.second)+=wez;
			lim-=wez;
		}
		return ret;
	}
	ll dinic(int nn, int zrzr, int ujuj) {
		n=nn;
		zr=zrzr;
		uj=ujuj;
		ll ret=0;
		while(1) {
			bfs();
			ll sta=ret;
			if (iszero(sta-(ret+=dfs(zr, 1e18))))//cos wiekszego niz maxflow, uwaga na overflow
				break;
		}
		return ret;
	}
	//ponizszych nie trzeba przepisywac
	void clear_memory() {
		for (int i=1; i<=n; i++)
			for (auto j : graf[i])
				delete(j.second.first);
	}
	//do ponizszych najpierw uzyc dinic()
	vector <int> cut() {
		vector <int> ret;
		bfs();
		for (int i=1; i<=n; i++)
			if (odl[i])
				ret.push_back(i);
		return ret;
	}
	map<pair<int,int>,ll> get_flowing() {//tam gdzie plynie 0 moze nie byc zainicjowane
		map<pair<int,int>,ll> ret;
		for (int i=1; i<=n; i++)
			for (int j=0; j<(int)graf[i].size(); j++)
				if ((*graf[i][j].second.first)<ori[i][j])
					ret[{i,graf[i][j].first}]+=ori[i][j]-(*graf[i][j].second.first);
		for (auto i : ret) {
			ll x=min(i.second, ret[{i.first.second,i.first.first}]);
			ret[i.first]-=x;
			ret[{i.first.second,i.first.first}]-=x;
		}
		return ret;
	}
};
 
#define y1 ababbaba
const int N = 507;
 
int n, m;
 
int x1[N];
int x2[N];
int y1[N];
int y2[N];

int jaki[2*N][2*N];

VI X, Y;
 
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
 
	cin >> n >> m;
 
	for(int i = 1; i <= m; ++i)
	{
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
		--x1[i];
		--y1[i];
		X.pb(x1[i]);
		X.pb(x2[i]);
		Y.pb(y1[i]);
		Y.pb(y2[i]);
	}	
 
	sort(ALL(X));
	sort(ALL(Y));
 	X.erase(unique(ALL(X)), X.end());
 	Y.erase(unique(ALL(Y)), Y.end());

	int vx = siz(X)-1;
	int vy = siz(Y)-1;
 
	flow F(vx+vy+5);
 
	for(int i = 1; i <= m; ++i)
	{
		for(int j = 0; j+1 < siz(X); ++j)
		{
			for(int k = 0; k+1 < siz(Y); ++k)
			{
				if(x1[i]<=X[j] && X[j+1]<=x2[i] && y1[i]<=Y[k] && Y[k+1]<=y2[i])
					//F.add_edge(2+j, vx+2+k, inf);
					jaki[j][k] = 1;
			}
		}
	}

	for(int j = 0; j+1 < siz(X); ++j)
	{
		for(int k = 0; k+1 < siz(Y); ++k)
		{
			if(jaki[j][k])
				F.add_edge(2+j, vx+2+k, inf);
		}
	}
 
	for(int i = 0; i < vx; ++i)
	{
		F.add_edge(1, 2+i, X[i+1]-X[i]);
	}
 
	for(int i = 0; i < vy; ++i)
	{
		F.add_edge(vx+2+i, vx+vy+2, Y[i+1]-Y[i]);
	}
 
	cout << F.dinic(vx+vy+2, 1, vx+vy+2) << endl;
}