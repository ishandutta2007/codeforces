#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>>" << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX=1e3+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);
const double EPS = 1e-9;

int n,m,a,b,p[MAX],res,tmp,vis[MAX],cen[MAX],cnt[MAX],ct,st;
vector<pii> ans;
vector<int> v[MAX],u[MAX];
int par(int z){
	return p[z] = (p[z]==z) ? z : par(p[z]);
}
void clr(int nw){
	vis[nw] = 0;
	for(auto i:v[nw])if(vis[i])clr(i);
	return;
}
void dfs(int nw){
	if(vis[nw]>ct)ct = vis[nw], st = nw;
	for(auto i:v[nw]){
		if(vis[i])continue;
		vis[i] = 1+vis[nw];
		dfs(i);
	}
	for(auto i:u[nw]){
		if(vis[i])continue;
		vis[i] = 1+vis[nw];
		dfs(i);
	}
	return;
}

int main(){
//	cout<<fixed<<setprecision(1);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)cnt[i] = 1e9, p[i] = i;
    rep(i,1,m){
    	cin>>a>>b;
    	v[a].pb(b);
    	v[b].pb(a);
    	p[par(a)] = par(b);
	}
//	cout<<"TESS\n";
//	rep(i,1,n)cout<<par(i)<<' '; cout<<"\n\n\n";
	rep(i,1,n){
		clr(i);
		ct = 0;
		vis[i] = 1;
		dfs(i);
//		rep(j,1,n)cout<<vis[j]<<' '; cout<<endl;
//		cout<<ct<<" "<<par(i)<<endl;
		if(cnt[par(i)]>ct)cnt[par(i)] = ct, cen[par(i)] = i;
	}
	res = 1e9;
	rep(i,1,n){
//		cout<<cen[i]<<endl;
		if(cen[i]){
			rep(j,1,n)u[j].clear();
			rep(j,1,n)if(cen[j]&&i!=j)u[cen[i]].pb(cen[j]), u[cen[j]].pb(cen[i]);
			memset(vis,0,sizeof vis);
			ct = 0;
			vis[cen[i]] = 1;
			dfs(cen[i]);
			memset(vis,0,sizeof vis);
			ct = 0;
			vis[st] = 1;
			dfs(st);
			ct--;
			if(ct<res){
				res = ct;
				ans.clear();
				for(auto j:u[cen[i]])ans.pb({cen[i],j});
			}
		}
	}
	cout<<res<<endl;
	for(auto i:ans)cout<<i.fi<<' '<<i.se<<endl;
    return 0;
}