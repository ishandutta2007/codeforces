#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
//#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
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
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 9e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 500;

int n,a,b,sz[MAX],fib[30],x[MAX];
vector<pii> v[MAX];
bool vis[MAX];

void dfs(int nw,int par){
	sz[nw] = 1;
	for(pii i:v[nw])if(i.fi!=par && !vis[i.se])dfs(i.fi,nw), sz[nw]+= sz[i.fi];
	return;
}

bool f(int nw,int par,int at,int a,int b);

bool solve(int nw,int sz){
	if(sz<4)return true;
	if(!x[sz])return false;
	dfs(nw,0);
	return f(nw,0,nw,fib[x[sz]-1],fib[x[sz]-2]);
}

bool f(int nw,int par,int at,int a,int b){
	for(pii i:v[nw])if(i.fi!=par && !vis[i.se]){
		if(sz[i.fi]==a || sz[i.fi]==b){
			vis[i.se] = 1;
			if(solve(nw,a+b-sz[i.fi]) && solve(i.fi,sz[i.fi]))return true;
			vis[i.se] = 0;
			dfs(at,0);
		}
		if(f(i.fi,nw,at,a,b))return true;
	}
	return false;
}

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    fib[0] = fib[1] = 1;
    rep(i,2,26){
    	fib[i] = fib[i-1] + fib[i-2];
    	x[fib[i]] = i;
	}
	
    cin>>n;
    rep(i,2,n){
    	cin>>a>>b;
    	v[a].pb({b,i});
    	v[b].pb({a,i});
	}
	cout<<(solve(1,n) ? "YES\n" : "NO\n");
    return 0;
}