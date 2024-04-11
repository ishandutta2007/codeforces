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


#define SIEVE

const int N = 10000050;

int lp[N+1];
int pr[N];int t=0;

void sieve(){
    for (int i=2; i<N; ++i) {
            if (lp[i] == 0) {
                lp[i] = i;
                pr[t++]=i;
            }
        for (int j=0; j<t && pr[j]<=lp[i] && i*pr[j]<N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}


int dp[N];
int ans[N];

int solve(){
 		dp[1] = 1;
 		for(int i = 1; i <= 1e7; i++){
 			ans[i] = 1e9;
 		}
 		ans[1] = 1;
 		for(int i = 2; i <= 1e7; i++){
 			int temp = lp[i];
 			int x = i;
 			int cnt = 0;
 			int val = 1;
 			while(temp == lp[x]){
 				cnt++;
 				x /= temp;
 				val *= temp;
 			}

 			dp[i] = dp[x]*(val*temp-1)/(temp-1);

 			if(dp[i]<=1e7){
 				mins(ans[dp[i]],i);
 			}	
 		}	
 		int t;cin >> t;
 		while(t--){
 			int n; cin >> n;
 			if(ans[n] == 1e9){
 				cout << -1 << endl;
 			}
 			else{
 				cout << ans[n] << endl;
 			}
 		}	
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