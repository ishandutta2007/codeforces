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
 		int n; cin >> n;
 		vector<int>b(n+3);
 		int s = 0;
 		rep(i,1,n+3){
 			cin >> b[i];
 			s += b[i];
 		}
 		sort(b.begin(),b.end());
 		s -= b[n+2];
 		for(int i = 1; i <= n + 1; i++){
 			if(s - b[i] == b[n+2]){
 				for(int j = 1; j <= n+1; j++){
 					if(i!=j){
 						cout << b[j] <<" ";
 					}
 				}
 				cout << endl;
 				return 0;
 			}
 		}
 		int t = 0;
 		for(int i = 1; i <= n; i++){
 			t += b[i];
 		}
 		if(b[n+1] == t){
 			for(int i = 1; i <= n; i++){
 				cout << b[i] << " ";
 			}
 			cout << endl;
 			return 0;
 		}
 		cout << -1 << endl;
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