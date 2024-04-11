#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
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
const int MAX = 5e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,m,a,b,x,y,z,vis[MAX],id,cl[MAX],dp[MAX][MAX],sz[2][MAX];
bool res[MAX];
vector<int> v[MAX];

void dfs(int nw,bool st){
	sz[st][id]++, cl[nw] = id, vis[nw] = st;
	for(auto i:v[nw]){
		if(vis[i]==-1)dfs(i,st^1);
		else if(st==vis[i]){cout<<"NO\n"; exit(0);}
	}
	return;
}

bool f(int nw,int rem){
	if(rem<0)return 0;
	if(nw>id)return rem==0;
	if(dp[nw][rem]!=-1)return dp[nw][rem];
	return dp[nw][rem] = f(nw+1,rem-sz[0][nw])|f(nw+1,rem-sz[1][nw]);
}

void bt(int nw,int rem){
	if(nw>id)return;
	if(f(nw+1,rem-sz[0][nw]))res[nw] = 1, bt(nw+1,rem-sz[0][nw]);
	else bt(nw+1,rem-sz[1][nw]);
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("input.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>x>>y>>z;
    while(m--){
    	cin>>a>>b;
    	v[a].pb(b), v[b].pb(a);
	}
	memset(vis,-1,sizeof vis);
	rep(i,1,n)if(vis[i]==-1){
		++id;
		dfs(i,0);
	}
	memset(dp,-1,sizeof dp);
	if(!f(1,y))return cout<<"NO\n",0;
	bt(1,y);
	cout<<"YES\n";
	rep(i,1,n){
		if(res[cl[i]]^vis[i])cout<<2;
		else if(x)cout<<1, --x;
		else cout<<3;
	}
	cout<<endl;
    return 0;
}