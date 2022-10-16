#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
const int MAX = 1e4+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;
 
int dp[1<<20],ans,msk,x[1<<20],sz,en;
bool vis[1<<20];
string s;
 
int main(){
//	cout<<fixed<<setprecision(4);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
	sz = s.size()-1;
	en = (1<<20)-1;
    rep(i,0,sz)x[i] = 1<<(s[i]-'a');
    rep(i,0,sz){
    	msk = 0;
    	rep(j,i,sz){
    		if(msk&x[j])break;
    		msk|=x[j];
    		if(!vis[msk]){
    			vis[msk] = 1;
    			dp[msk] = __builtin_popcount(msk);
			}
		}
	}
	for(int i = 1<<19; i; i>>=1){
		rap(j,en,1)if(j&i)dp[j] = max(dp[j],dp[j^i]);
	}
	rep(i,1,en){
		if(!vis[i])continue;
		ans = max(ans,dp[i]+dp[en^i]);
	}
	cout<<ans<<endl;
    return 0;
}