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


int solve(){
 		int n,c; cin >> n >> c;
 		vector<int>a(n+1);
 		vector<int>b(n);
 		rep(i,1,n+1){
 			cin >> a[i];
 		}
 		rep(i,1,n){
 			cin >> b[i];
 		}
 		int ans = c/a[1] + (c%a[1] != 0);
 		int d = b[1]/a[1] + (b[1]%a[1] != 0);
 		int cost_rem = d*a[1] - b[1];
 		for(int i = 2; i <= n; i++){
 			int reqd = c - cost_rem;
 			if(reqd >= 0){
 				int nd = reqd/a[i] + (reqd%a[i]!=0);
 				mins(ans,d+nd + i-1);
 			}
 			reqd = b[i] - cost_rem;
 			if(reqd < 0){
 				cost_rem -= b[i];
 			}
 			else{
 				int nd = reqd/a[i] + (reqd%a[i] != 0);
 				d += nd;
 				cost_rem = nd*a[i] + cost_rem - b[i];
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
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}