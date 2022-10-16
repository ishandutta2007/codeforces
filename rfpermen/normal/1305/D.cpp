#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
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
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
//#define endl '\n'
const int MAX = 1e3+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;
 
int n,a,b,p[MAX][MAX],pos,mx,x,vis[MAX];
set<int> v[MAX];
 
void d(int nw,int st,int par){
	for(auto i:v[nw])if(i!=par){
		p[i][st] = nw;
		d(i,st,nw);
	}
}
 
void dfs(int nw,int par){
	for(auto i:v[nw])if(i!=par){
		vis[i] = vis[nw]+1;
		dfs(i,nw);
	}
}
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	rep(i,2,n){
		cin>>a>>b;
		v[a].insert(b);
		v[b].insert(a);
	}
	rep(i,1,n)d(i,i,0);
	pos = 1;
	while(1){
		memset(vis,0,sizeof vis);
		vis[pos] = 1;
		dfs(pos,0);
		rep(i,1,n)if(vis[i]>vis[pos])pos = i;
		if(vis[pos]==1)break;
		
		memset(vis,0,sizeof vis);
		vis[pos] = 1;
		dfs(pos,0);
		mx = 0;
		rep(i,1,n)if(vis[i]>vis[mx])mx = i;
		cout<<"? "<<pos<<' '<<mx<<endl;
		cin>>x;
		if(p[x][pos])v[x].erase(p[x][pos]);
		if(p[x][mx])v[x].erase(p[x][mx]);
		pos = x;
	}
	cout<<"! "<<pos<<endl;
    return 0;
}