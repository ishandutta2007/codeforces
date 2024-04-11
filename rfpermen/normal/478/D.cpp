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
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 5e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;
 
int r,g,h,ttl,dp[2][200005],ans;
bool ls,nw,st[2][200005],bis;
 
int main(){
//	cout<<fixed<<setprecision(6);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>r>>g;
    nw = 1, st[0][0] = 1;
    do{
    	bis = 0;
    	rep(i,0,r){
    		if(!st[ls][i])continue;
    		if(i+h+1<=r)st[nw][i+h+1] = bis = true;
    		if(g + i - ttl>h)st[nw][i] = bis = true;
    		st[ls][i] = false;
		}
		if(bis)++h;
		ttl+=h;
		nw^=1, ls^=1;
	}while(bis);
	nw = 1, ls = 0, dp[0][0] = 1;
	ttl = 0;
	rep(i,1,h){
		rep(j,0,r){
			if(!dp[ls][j])continue;
			if(i+j<=r){
				dp[nw][i+j]+= dp[ls][j];
				if(dp[nw][i+j]>MOD)dp[nw][i+j]-=MOD;
			}
			if(g + j - ttl>=i){
				dp[nw][j]+= dp[ls][j];
				if(dp[nw][j]>MOD)dp[nw][j]-=MOD;
			}
			dp[ls][j] = 0;
		}
		ttl+=i;
		nw^=1, ls^=1;
	}
	rep(i,0,r){
		ans+= dp[ls][i];
		if(ans>MOD)ans-=MOD;
	}
	cout<<ans<<endl;
    return 0;
}