#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
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
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

ll n,m,r,a,b,c,f[MAX*10],pre[MAX*10],x[MAX][MAX],ans,k,sems;
vector<pair<ll,pii> > v;

inline ll pw(ll x,ll y){
	ll ret = 1;
	while(y){
		if(y&1)ret = ret*x%MOD;
		x = x*x%MOD;
		y>>=1;
	}
	return ret;
}

inline ll h(int a,int b){
	ll x1,x2,y1,y2;
	x1 = max(1ll,a-r), y1 = max(1ll,b-r);
	x2 = min(1000ll,a+r), y2 = min(1000ll,b+r);
	return x[x2][y2] - x[x1-1][y2] - x[x2][y1-1] + x[x1-1][y1-1];
}

inline ll g(int a,int b,int c,int d){
	ll x1,x2,x3,x4,y1,y2,y3,y4;
	x1 = max(1ll,a-r), y1 = max(1ll,b-r);
	x2 = min(1000ll,a+r), y2 = min(1000ll,b+r);
	
	x3 = max(1ll,c-r), y3 = max(1ll,d-r);
	x4 = min(1000ll,c+r), y4 = min(1000ll,d+r);
	
	if(x2<x3||x4<x1||y2<y3||y4<y1)return 0;
	a = max(x1,x3), b = max(y1,y3), c = min(x2,x4), d = min(y2,y4);
	return x[c][d] - x[a-1][d] - x[c][b-1] + x[a-1][b-1];
}

inline ll get(int k){
	if(k<m)return sems;
	return sems - f[k] * pre[m] % MOD * pre[k-m] % MOD;
}

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    f[0] = pre[0] = 1;
    rep(i,1,10000)f[i] = f[i-1]*i%MOD, pre[i] = pw(f[i],MOD-2);
    cin>>n>>m>>r;
    rep(i,1,n){
    	cin>>a>>b>>c;
    	x[a][b]++;
    	v.pb({c,{a,b}});
	}
	rep(i,1,1000)rep(j,1,1000)x[i][j]+= x[i][j-1]+x[i-1][j]-x[i-1][j-1];
	sems = f[n] * pre[m] % MOD * pre[n-m] % MOD;
	for(pair<ll,pii> i:v){
		k = h(i.sf,i.ss);
		k = get(n-k);
		
		ans+= i.fi*i.fi%MOD * k % MOD;
	}
	
	
	asd(i,0,n)asd(j,i+1,n){
		a = h(v[i].sf,v[i].ss);
		b = h(v[j].sf,v[j].ss);
		k = a + b - g(v[i].sf,v[i].ss,v[j].sf,v[j].ss);
		
		k = get(n-k);
		a = get(n-a), b = get(n-b);
		
//		cout<<i<<" "<<j<<" = "<<b-(k-a)<<endl;
		k = b-(k-a);
		ans+= 2ll*v[i].fi*v[j].fi%MOD * k % MOD;
	}
	ans%= MOD;
	if(ans<0)ans+= MOD;
	
	cout<<ans<<endl;
    return 0;
}