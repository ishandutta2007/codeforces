#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
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
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 5e5+10;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

ll n,a,b,x[MAX],mx[MAX],ans;
vector<int> v[MAX];

void dfs(int nw,int par){
	mx[nw] = -INF;
	for(auto i:v[nw]){
		if(i==par)continue;
		dfs(i,nw);
		x[nw]+= x[i];
		mx[nw] = max(mx[nw],mx[i]);
	}
	mx[nw] = max(mx[nw],x[nw]);
	return;
}

void f(int nw,int par,ll at){
	ans = max(ans,mx[nw]+at);
	vector<pll> z;
	z.pb({-INF,0});
	for(auto i:v[nw])if(i!=par)z.pb({mx[i],i});
	sort(all(z)), reverse(all(z));
	for(auto i:v[nw]){
		if(i==par)continue;
		if(i==z[0].se)f(i,nw,max(at,z[1].fi));
		else f(i,nw,max(at,z[0].fi));
	}
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i];
    rep(i,2,n){
    	cin>>a>>b;
    	v[a].pb(b), v[b].pb(a);
	}
	dfs(1,0);
	ans = -INF;
	f(1,0,-INF);
	if(ans<-1e17)cout<<"Impossible\n";
	else cout<<ans<<endl;
    return 0;
}