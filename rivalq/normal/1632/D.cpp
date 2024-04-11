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
 		vector<int> a(n + 1);
 		vector<vector<int>>st(21,vector<int>(n + 1));
 		vector<int>LOG(n + 1);
 		for(int i = 1; i <= n; i++){
 			cin >> a[i];
 			st[0][i] = a[i];
 		}
 		for(int x = 1; x <= 20; x++){
 			for(int j = 1; j + (1 << (x - 1))<= n; j++){
 				st[x][j] = gcd(st[x - 1][j],st[x - 1][j + (1 << (x-1))]);
 			}
 		}
 		for(int i = 2; i <= n; i++){
 			LOG[i] = 1 + LOG[i/2];
 		}
 		auto query = [&](int l,int r){
 			int j = LOG[r - l + 1];
 			return gcd(st[j][l],st[j][r - (1 << j) + 1]);
 		};
 		int ans = 0;
 		int last = 0;
 		for(int i = 1; i <= n; i++){
 			int L = last + 1;
 			int R = i;
 			bool found = 0;
 			while(L <= R){
 				int M = (L + R)/2;
 				int g = (i - M + 1) - query(M,i);
 				if(g == 0){
 					found = 1;
 					break;
 				}else if(g > 0){
 					L = M + 1;
 				}else{
 					R = M -  1;
 				}
 			} 
 			if(found){
 				ans++;
 				last = i;
 			}
 			cout << ans << " ";
 		}
 		cout << endl;


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