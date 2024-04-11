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

const int N = 1e6 + 5;

vector<int> d[N];
int dp[N],g[N];

int solve(){

            int n; cin >> n;
            for(int i = 1; i <= n; i++){
                int x; cin >> x;
                dp[x] = 1;
            }

            for(int i = 1; i < N; i++){
            	for(int j = i; j < N; j += i){
            		d[j].push_back(i);
            	}
            }

            int ans = 0;

            for(int i = 1e6; i >= 1; i--){
            	int temp = g[i];
            	g[i] = g[i]*(g[i] - 1)/2;
            	for(int j = 2*i; j <= 1e6; j += i){
                		g[i] -= g[j];
                }
                if(!dp[i]){
                	
                	if(g[i] > 0){
                		dp[i] = 1;
                	}
                } 
                if(dp[i]){
                	for(auto j:d[i]){
                		if(j != i){
                			g[j]++;
                		}else{
                			g[j] += temp;
                		}
                	}
                }
                ans += dp[i];  
            }
            cout << ans - n << endl;


 	
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