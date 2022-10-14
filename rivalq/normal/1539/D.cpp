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
 		vector<pii>vec(n);
 		int ans = 0;
 		int sum = 0;
 		rep(i,0,n){
 			cin >> vec[i];
 			sum += vec[i].x;
 		}
 		sort(vec.begin(),vec.end(),[&](pii p1,pii p2){
 			if(p1.y == p2.y){
 				return p1.x < p2.x;
 			}
 			return p1.y > p2.y;
 		});
 		int buy = 0;
 		int i = 0, j = n - 1;
 		while(i <= j){
 			if(i == j){
 				int a = vec[i].x;
 				int b = vec[j].y;
 				if(buy >= b)ans += a;
 				else if(buy + a >= b){
 					ans += a + b - buy;
 				}else{
 					ans += 2*a;
 				}
 				break;
 			}else{
 				if(buy >= vec[j].y){
 					ans += vec[j].x;
 					buy += vec[j].x;
 					j--;
 				}else{
 					int a = vec[i].x;
 					int b = vec[i].y;
 					if(buy + a >= vec[j].y){
 						int bought = vec[j].y - buy;
 						ans += 2*bought;
 						vec[i].x -= bought;
 						buy += bought;
 					}else{
 						ans += 2*a;
 						buy += a;
 						i++;
 					}
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