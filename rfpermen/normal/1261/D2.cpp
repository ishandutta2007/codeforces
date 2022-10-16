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
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const long double EPS = 1e-18;
const int block = 2000;

ll n,k,ans,hit,x[MAX],cnt,fc[MAX],pre[MAX];

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
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    fc[0] = pre[0] = 1;
    rep(i,1,200000)fc[i] = (fc[i-1]*i)%MOD, pre[i] = pw(fc[i],MOD-2);
    cin>>n>>k;
    if(k==1)return cout<<"0\n",0;
    rep(i,1,n)cin>>x[i];
    rep(i,1,n)if(x[i]!=x[i==n ? 1 : i+1])++cnt;
    rep(i,0,cnt>>1){
    	hit = (hit + fc[cnt] * pre[i] % MOD * pre[i] % MOD * 
				pre[cnt-i-i] % MOD * pw(k-2,cnt-i-i))%MOD;
	}
	ans = (pw(k,cnt) - hit + MOD) * pw(2,MOD-2) % MOD * pw(k,n-cnt) % MOD;
	cout<<ans<<endl;
    return 0;
}