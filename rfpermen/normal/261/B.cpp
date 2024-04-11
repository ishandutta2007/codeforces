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
#define rng() (rand()<<16)|rand()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 47+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,x[MAX],sm,k,tmp;
ll dp[MAX][MAX][MAX],fr[MAX];
double ans,res;

ll f(int nw,int rem,int cnt){
	if(rem==0)return cnt==0;
	if(cnt<0 || nw>n)return 0;
	ll &ret = dp[nw][rem][cnt];
	if(ret!=-1)return ret;
	ret = f(nw+1,rem,cnt);
	if(x[nw]<=rem)ret+= f(nw+1,rem-x[nw],cnt-1);
	return ret;
}

int main(){
 cout<<fixed<<setprecision(10);
// freopen("input.txt", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i], sm+= x[i];
    cin>>k;
    if(k>=sm)return cout<<n<<endl,0;
    rep(i,1,n){
    	tmp = x[i];
    	x[i] = 100;
    	mems(dp,-1);
    	rep(j,max(1,k-tmp+1),k)rep(o,1,n)fr[o]+= f(1,j,o);
    	x[i] = tmp;
	}
//	rep(i,1,n)cout<<i<<" = "<<fr[i]<<endl;
	rep(i,1,n){
		res = fr[i]*i;
		asd(j,i+1,n)res/= j, res*= n-j;
		res/= n;
		ans+= res;
	}
	cout<<ans<<endl;
    return 0;
}