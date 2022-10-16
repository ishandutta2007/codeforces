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
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define out(x,y) cout << ">> " << x << " " << y << endl
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
const int MAX = 1e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 600;

int n,x,cnt[MAX],ls;
ll ans,ttl;
vector<int> v;

inline ll pw(ll x,ll y){
	ll ret = 1;
	while(y){
		if(y&1)ret = ret*x%MOD;
		x = x*x%MOD;
		y>>=1;
	}
	return ret;
}

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x, ++cnt[x];
    rap(i,100000,1)cnt[i]+= cnt[i+1];
    rep(mx,1,100000){
    	if(!cnt[mx])break;
    	v.clear();
    	for(int i = 1; i*i<=mx; ++i)if(mx%i==0){
    		x = mx/i;
    		v.pb(i);
    		if(i!=x)v.pb(x);
		}
		sort(all(v));
		ls = 0, ttl = 1;
		rap(i,v.size()-1,0){
			ttl = ttl*pw(i+1,cnt[v[i]]-ls)%MOD;
			ls = cnt[v[i]];
		}
		ttl = ttl - ttl*pw(pw(v.size(),cnt[v.back()]),MOD-2)%MOD*pw(v.size()-1,cnt[v.back()])%MOD;
		ans+= ttl;
	}
	ans%= MOD;
	if(ans<0)ans+= MOD;
	cout<<ans<<endl;
    return 0;
}