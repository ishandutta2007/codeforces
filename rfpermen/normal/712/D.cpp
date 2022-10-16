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
#define Size(n) ((int)(n).size())
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
const int MAX = 9e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 600;

int a,b,k,t,le,ri,x,y,dp[2][MAX];
ll ans;
bool ls,nw;

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>a>>b>>k>>t; t<<=1;
    le = ri = 450000 + a-b;
    dp[1][le] = 1;
    ls = 1;
    rep(iter,1,t){
    	mems(dp[nw],0);
    	rep(i,le,ri)dp[nw][i-k]+= dp[ls][i], dp[nw][i+k+1]-= dp[ls][i];
    	le-= k, ri+= k;
    	rep(i,le+1,ri){
    		dp[nw][i]+= dp[nw][i-1];
    		if(dp[nw][i]<0)dp[nw][i]+= MOD;
    		else if(dp[nw][i]>=MOD)dp[nw][i]-= MOD;
		}
		nw^= 1, ls^= 1;
	}
	rep(i,450001,ri)ans+= dp[ls][i];
	cout<<ans%MOD<<endl;
    return 0;
}