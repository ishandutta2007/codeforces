#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
//#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=(n);i<=(N);++i)
#define FOR(i,n,N) for(int i=(n);i< (N);++i)
#define rap(i,n,N) for(int i=(n);i>=(N);--i)
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
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define PQ(T) priority_queue<T>
#define PQr(T) priority_queue<T, vector<T>, greater<T>>
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 9e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 500;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

int n,a,b,id,pos[MAX],z[MAX],cl[MAX];
bool vis[MAX];
ll dp[MAX];

ll f(int nw){
	if(vis[nw])return dp[nw];
	vis[nw] = 1, dp[nw] = INF;
	if(!pos[nw])return dp[nw];
	return dp[nw] = f(pos[nw]) + abs(pos[nw]-nw);
}

int main(){
//	cout<<fixed<<setprecision(5);
// freopen("input.txt", "r", stdin);
// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>a>>b;
	FOR(i,1,n)cin>>z[i];
	rep(i,1,n)cin>>cl[i];
	
	id = a;
	FOR(i,a,n){
		vis[cl[i]] = 1;
		while(!vis[z[i]] && id>1)--id, vis[cl[id]] = 1;
		if(!vis[z[i]])break;
		pos[i+1] = id;
	}
	mems(vis,0);
	id = a;
	rap(i,a-1,1){
		vis[cl[i+1]] = 1;
		while(!vis[z[i]] && id<n)++id, vis[cl[id]] = 1;
		if(!vis[z[i]])break;
		pos[i] = id;
	}
	mems(vis,0);
	mems(dp,-1);
	dp[a] = 0, vis[a] = 1;
	if(f(b)>=INF)cout<<"-1\n";
	else cout<<f(b)<<endl;
	return 0;
}