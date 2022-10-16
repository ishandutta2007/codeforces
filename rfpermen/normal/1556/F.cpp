#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=(n);i<=(N);++i)
#define For(i,n,N) for(int i=(n);i< (N);++i)
#define rap(i,n,N) for(int i=(n);i>=(N);--i)
#define rip(i,n,N,V) for(int i=(n);i<=(N);i+=V)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
//#define le left
//#define ri right
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
#define ou3(x,y,z) cout << ">> " << (x) << " " << (y) << " " << (z) << endl
#define mems(x,y) memset(&x,y,sizeof x)
#define memsv(x,y) memset(&x[0], y, sizeof(x[0]) * x.size())
#define popcount __builtin_popcountll
#define all(x) x.begin(),x.end()
#define PQ(T) priority_queue<T>
#define PQr(T) priority_queue<T, vector<T>, greater<T>>
#define vi vector<int>
#define vii vector<pii>
#define vl vector<ll>
#define vll vector<pll>
#define ari(x) array<int,x>
#define arll(x) array<ll,x>
#define ard(x) array<double,x>
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
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
const int block = 315;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

ll n,x[15],y[15][15],dp[1<<14],z[15][1<<14],Z[15][1<<14],en,inv,val,ans;

ll ret;
inline ll g(int x,int y){
	ret = 1;
	rep(i,0,n)if(x&(1<<i))ret = ret*z[i][y]%MOD;
	return ret%MOD;
}
inline ll G(int x,int y){
	ret = 1;
	rep(i,0,n)if(x&(1<<i))ret = ret*Z[i][y]%MOD;
	return ret%MOD;
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    if(n==1)return cout<<"1\n",0;
    en = (1<<n)-1;
    --n;
    rep(i,0,n)cin>>x[i];
    rep(i,0,n)rep(j,i+1,n){
    	inv = pw(x[i]+x[j],MOD-2);
    	y[i][j] = x[i]*inv%MOD;
    	y[j][i] = x[j]*inv%MOD;
	}
	rep(i,0,n)rep(mask,0,en)if(!(mask&(1<<i))){
		val = 1;
		rep(k,0,n)if(mask&(1<<k))val = val*y[i][k]%MOD;
		z[i][mask] = val;
		Z[i][mask] = pw(z[i][mask],MOD-2);
	}
	rep(mask,1,en){
		val = 0;
		for(int sub = (mask-1)&mask; sub>0; --sub, sub&= mask)val+= dp[sub]*G(sub,en^mask)%MOD;
		dp[mask] = g(mask,en^mask)*(1-val%MOD)%MOD;
		ans+= dp[mask]*popcount(mask);
	}
	ans%= MOD;
	if(ans<0)ans+= MOD;
	cout<<ans<<endl;
	return 0;
}