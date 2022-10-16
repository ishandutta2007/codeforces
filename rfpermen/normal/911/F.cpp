#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
//#pragma GCC target("sse4.2")
//#pragma GCC optimize("unroll-loops")
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
#define endl '\n'
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,a,b,dep[MAX],sp[18][MAX],bt = 17,vis[MAX],cnt[MAX],resa,resb;
ll res;
vector<int> v[MAX];
vector<pii> ans;
queue<int> q;

void f(int nw,int par){
	for(auto i:v[nw])if(i!=par){
		sp[0][i] = nw;
		dep[i] = dep[nw]+1;
		f(i,nw);
	}
	return;
}

inline int lca(int x,int y){
	if(dep[x]<dep[y])x^=y^=x^=y;
	rap(i,bt,0)if(dep[x]-(1<<i)>=dep[y])x = sp[i][x];
	if(x==y)return x;
	rap(i,bt,0){
		if(sp[i][x]!=sp[i][y]){
			x = sp[i][x];
			y = sp[i][y];
		}
	}
	return sp[0][x];
}

inline int dist(int a,int b){
	return dep[a] + dep[b] - (dep[lca(a,b)]<<1);
}

void dfs(int nw){
	for(auto i:v[nw])if(!vis[i]){
		vis[i] = vis[nw]+1;
		dfs(i);
	}
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,2,n){
    	cin>>a>>b;
    	v[a].pb(b), v[b].pb(a);
	}
	dep[1] = 1;
	f(1,0);
	rep(j,1,bt)rep(i,1,n)sp[j][i] = sp[j-1][sp[j-1][i]];
	
	vis[1] = 1;
	dfs(1);
	int mx = 1,nw;
	rep(i,1,n)if(vis[i]>vis[mx])mx = i;
	memset(vis,0,sizeof vis);
	vis[mx] = 1;
	dfs(mx);
	rep(i,1,n)if(vis[i]>vis[mx])mx = i;
	a = mx;
	while(1){
		nw = vis[mx];
		vis[mx] = -nw;
		if(nw==1){b = mx; break;}
		for(auto i:v[mx])if(vis[i]==nw-1){
			mx = i; break;
		}
	}
	
	rep(i,1,n)if(vis[i]>0){
		cnt[i] = v[i].size();
		if(cnt[i]==1)q.push(i);
	}
	
	while(!q.empty()){
		nw = q.front(); q.pop();
		resa = dist(a,nw), resb = dist(b,nw);
		if(resa>resb)ans.pb({a,nw}), res+= resa;
		else ans.pb({b,nw}), res+= resb;
		
		for(auto i:v[nw]){
			--cnt[i];
			if(cnt[i]==1)q.push(i);
		}
	}
	
	res+= (ll)(vis[b]-vis[a])*(vis[b]-vis[a]+1)>>1;
	while(a!=b){
		ans.pb({b,a});
		for(auto i:v[a])if(vis[i]==vis[a]+1){
			a = i; break;
		}
	}
	cout<<res<<endl;
	for(auto i:ans)cout<<i.fi<<' '<<i.se<<' '<<i.se<<endl;
	return 0;
}