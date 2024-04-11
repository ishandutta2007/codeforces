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
 		set<pii>odd;
 		set<pii>even;
 		rep(i,1,n+1){
 			rep(j,1,n+1){
 				if(i%2 == j%2)even.insert({i,j});
 				else odd.insert({i,j});
 			}
 		}
 		int k = n*n;
 		while(k--){
 			int x; cin >> x;
 			if(x == 1){
 				if(odd.size() > 0){
 					pii p = *odd.begin();
 					cout << 2 << " " << p << endl << flush;
 					odd.erase(p); 
 				}
 				else{
 					pii p = *even.begin();
 					cout << 3 << " " << p << endl << flush;
 					even.erase(p);
 				}
 			}
 			else if(x == 2){
 				if(even.size() > 0){
 					pii p = *even.begin();
 					cout << 1 << " " << p << endl << flush;
 					even.erase(p); 
 				}
 				else{
 					pii p = *odd.begin();
 					cout << 3 << " " << p << endl << flush;
 					odd.erase(p);
 				}
 			}
 			else{
 				if(odd.size() > 0){
 					pii p = *odd.begin();
 					cout << 2 << " " << p << endl << flush;
 					odd.erase(p);
 				}
 				else{
 					pii p = *even.begin();
 					cout << 1 << " " << p << endl << flush;
 					even.erase(p);
 				}
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