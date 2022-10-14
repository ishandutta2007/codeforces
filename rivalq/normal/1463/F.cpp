#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
//#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC



template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}


const int M = 23;
const int N = 1<<M;
int solve(){
 	int n,x,y;cin>>n>>x>>y;
 	vector<int>a(x+y);
 	rep(i,0,x+y){
 		a[i]=n/(x+y);
 		if(i<n%(x+y))a[i]++;
 	}
 	vector<vector<int>>dp(2,vector<int>(N));
 	int cur=1;
 	int last=0;
 	int ans=0;
 	rep(i,0,x+y){
 		// for i it does not matter if we take j<i st i-j>22
 		rep(mask,0,N){
 			int new_mask=(mask<<1)&(N-1); // left cyclic shift by period of 23
 			maxs(dp[cur][new_mask],dp[last][mask]);
 			if(((new_mask)&(1<<x))==0 && ((new_mask)&(1<<y))==0){
 				maxs(dp[cur][new_mask+1],dp[last][mask]+a[i]);
 			}
 			maxs(ans,dp[cur][mask]);
 		}
 		swap(cur,last);
 	}
 	cout<<ans<<endl;
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}