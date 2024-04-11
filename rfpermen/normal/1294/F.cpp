#include <bits/stdc++.h>
 
#pragma GCC optimize("O2", "unroll-loops")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define plll pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,a,b,c,x[MAX],ans;
vector<int> v[MAX];

void dfs(int nw,int par){
	for(auto i:v[nw])if(i!=par){
		x[i] = x[nw]+1;
		dfs(i,nw);
	}
	return;
}
void f(int nw,int par){
	for(auto i:v[nw])if(i!=par){
		if(x[i]==x[nw]-1)f(i,nw);
		else x[i] = 1, dfs(i,nw);
	}
	x[nw] = 0;
	return;
}

int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,2,n){
    	cin>>a>>b;
    	v[a].pb(b), v[b].pb(a);
	}
	dfs(1,0);
	rep(i,1,n)if(x[i]>x[a])a = i;
	x[a] = 0;
	dfs(a,0);
	rep(i,1,n)if(x[i]>x[b])b = i;
	ans = x[b];
	f(b,0);
	rep(i,1,n)if(x[i]>=x[c]&&i!=a&&i!=b)c = i;
	cout<<ans+x[c]<<endl<<a<<' '<<b<<' '<<c<<endl;
	return 0;
}