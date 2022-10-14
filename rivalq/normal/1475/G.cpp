// Jai Shree Ram  
  
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
#define int            long long
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


const int N = 2e5+5;

vector<int>d[N];

int solve(){
 		int n;cin>>n;
 		vector<int>a(n+1);
 		vector<int>f(N);
 		rep(i,1,n+1){
 			cin>>a[i];
 			f[a[i]]++;
 		}
 		vector<int>dp(N,0);
 		int ans=0;
 		for(int i=1;i<=2e5;i++){
 			if(f[i]==0)continue;
 			dp[i]=f[i];
 			for(auto j:d[i]){
 				maxs(dp[i],dp[j]+f[i]); 
 			}
 			maxs(ans,dp[i]); 
 		}
 		cout<<n-ans<<endl;
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for(int i=1;i<=2e5;i++){
    	for(int j=2*i;j<=2e5;j+=i){
    		d[j].push_back(i);
    	}
    }
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}