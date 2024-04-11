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
//#define ff fi.fi
//#define fs fi.se
//#define sf se.fi
//#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const long double EPS = 1e-18;
const int block = 2000;

ll n,m,p[MAX],sz[MAX],a,b,ans,cnt;
pll x[MAX];
vector<int> v[MAX];

int par(int z){
	if(p[z]==z)return z;
	return p[z] = par(p[z]);
}

int main(){
	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)cin>>x[i].fi, x[i].se = p[i] = i, sz[i] = 1;
    rep(i,1,m){
    	cin>>a>>b;
    	if(x[a].fi<x[b].fi || (x[a].fi==x[b].fi && a<b))v[a].pb(b);
    	else v[b].pb(a);
	}
	sort(x+1,x+1+n);
	reverse(x+1,x+1+n);
	rep(i,1,n){
		a = x[i].se;
		for(int j:v[a]){
			assert(p[a]==a);
			b = par(j);
			if(a==b)continue;
			ans+= sz[a]*sz[b]*x[i].fi;
			sz[a]+= sz[b];
			p[b] = a;
			sz[b] = 0;
		}
	}
	cout<<(double)ans*2.0/n/(n-1)<<endl;
    return 0;
}