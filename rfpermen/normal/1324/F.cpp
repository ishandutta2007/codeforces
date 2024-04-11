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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000009;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int n,x[MAX],par[MAX],a,b;
vector<int> v[MAX];

void dfs(int nw){
	for(auto i:v[nw])if(i!=par[nw]){
		par[i] = nw;
		dfs(i);
		x[nw]+= max(x[i],0);
	}
	return;
}

void f(int nw){
	x[nw] = x[nw] + max(0,x[par[nw]]-max(0,x[nw]));
	for(auto i:v[nw])if(i!=par[nw])f(i);
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>x[i];
    	if(!x[i])x[i] = -1;
	}
	rep(i,2,n){
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1);
	f(1);
	rep(i,1,n)cout<<x[i]<<' '; cout<<endl;
	return 0;
}