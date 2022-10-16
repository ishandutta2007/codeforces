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
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl
//#define size(n) ((int)(n).size())
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
const int MAX = 1e6+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 9e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 600;

int dp[360369],k;
ll a,b,ans,x,y;

int f(int rem){
	if(!rem)return 0;
	if(dp[rem]!=-1)return dp[rem];
	int ret = f(rem-1);
	rep(i,3,k)if(rem%i!=0)ret = min(ret,f(rem-rem%i));
	return dp[rem] = ret+1;
}

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>a>>b>>k;
    mems(dp,-1);
    x = a/360360, y = b/360360;
    if(x!=y){
    	ans = f(a%360360);
    	ans+= (x-y-1)*f(360360);
    	a = 360360*(y+1);
	}
	
	while(a!=b){
		x = a-1;
		rep(i,3,k){
			y = a - a%i;
			if(y>=b && y<x)x = y;
		}
		a = x;
		++ans;
	}
	cout<<ans<<endl;
    return 0;
}