#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n" 
const int MAX = 1e5+5;

int n,m,c[MAX],a,b,sz[MAX],ans[MAX],cnt[MAX],res[MAX],ls;
vector<int> v[MAX],tmp[MAX];
piii q[MAX];
vector<pii> que[MAX];

inline bool cmp(int x,int y){
	if(sz[x]==sz[y])return x > y;
	return sz[x] > sz[y];
}

void dfs(int nw,int par){
	sz[nw] = 1;
	for(auto i:tmp[nw]){
		if(i==par)continue;
		v[nw].pb(i);
		dfs(i,nw);
		sz[nw]+=sz[i];
	}
	sort(all(v[nw]),cmp);
	return;
}
void fill(int nw){
	++res[++cnt[c[nw]]];
	for(auto i:v[nw])fill(i);
	return;
}
void cl(int nw){
	--res[cnt[c[nw]]--];
	for(auto i:v[nw])cl(i);
	return;
}
void f(int nw){
	if(v[nw].empty()){
		++res[++cnt[c[nw]]];
		for(auto i:que[nw])ans[i.se] = res[i.fi];
		return;
	}
	int bt = v[nw].size()-1;
	rep(i,1,bt){
		f(v[nw][i]);
		cl(v[nw][i]);
	}
	f(v[nw][0]);
	rep(i,1,bt)fill(v[nw][i]);
	++res[++cnt[c[nw]]];
	for(auto i:que[nw])ans[i.se] = res[i.fi];
	return;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)cin>>c[i];
    rep(i,2,n){
    	cin>>a>>b;
    	tmp[a].pb(b);
    	tmp[b].pb(a);
	}
    dfs(1,0);
    rep(i,1,m)cin>>a>>b, que[a].pb({b,i});
    f(1);
	rep(i,1,m)cout<<ans[i]<<endl;
	return 0;
}