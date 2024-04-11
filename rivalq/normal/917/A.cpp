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

bool dp[5005][5005];

int solve(){
 		int n;
 		string s; cin >> s;
 		n = s.length();
 		int ans = 0;
 		for(int i = 0; i < n; i++){
 			int open = 0, close = 0,bal = 0;
 			for(int j = i; j < n; j++){
 				if(s[j] == '(')open++,bal++;
 				else if(s[j] == '?')bal++;
 				else bal--,close++;
 				if(bal < 0)break;
 				int len = (j - i + 1);
 				if(len % 2 == 0 and open <= len/2){
 					dp[i][j] = 1;
 				}
 				
 			}
 		}
 		for(int i = n - 1; i >= 0; i--){
 			int open = 0, close = 0,bal = 0;
 			for(int j = i; j >= 0; j--){
 				if(s[j] == ')')open++,bal++;
 				else if(s[j] == '?')bal++;
 				else bal--,close++;
 				if(bal < 0)break;
 				int len = (i - j + 1);
 				if(len % 2 == 0 and open <= len/2){
 					ans += dp[j][i];
 				}
 			}
 		}

 		cout << ans << endl;
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