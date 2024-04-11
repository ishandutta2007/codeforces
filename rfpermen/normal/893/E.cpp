#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
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
#define rng() (rand()<<16)|rand()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e6+500;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

ll tc,n,f[MAX],pre[MAX],dua[MAX],x,ans;
map<int,int> cnt;

inline ll pw(ll x, ll y){
	ll ret = 1;
	while(y){
		if(y&1)ret = ret*x%MOD;
		x = x*x%MOD;
		y>>=1;
	}
	return ret;
}

int main(){
//  cout<<fixed<<setprecision(10);
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    f[0] = dua[0] = 1;
    rep(i,1,1000100)f[i] = f[i-1]*i%MOD, dua[i] = (dua[i-1]<<1)%MOD;
	pre[1000100] = pw(f[1000100],MOD-2);
    rap(i,1000099,0)pre[i] = pre[i+1]*(i+1)%MOD;
    
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>x>>n;
    	cnt.clear();
    	for(int i = 2; i*i<=x; ++i)if(x%i==0){
    		while(x%i==0)x/=i, ++cnt[i];
		}
		if(x!=1)++cnt[x];
		--n; ans = dua[n];
		for(auto i:cnt){
			ans = ans * f[i.se + n] % MOD * pre[i.se] % MOD * pre[n] % MOD;
		}
		cout<<ans<<endl;
	}
    return 0;
}