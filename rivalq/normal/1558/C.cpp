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
 		for(int i = 1; i <= n; i++){
 			cin >> a[i];
 		}
 		for(int i = 1; i <= n; i++){
 			if(a[i] % 2 != i % 2){
 				cout << -1 << endl;
 				return 0;
 			}
 		}
 		vector<int> res;
 		auto op = [&](int i){
 			res.push_back(i);
 			reverse(a.begin() + 1,a.begin() + 1 + i);
 		};

 		auto find = [&](int i){
 			for(int k = 1; k <= n; k++){
 				if(a[k] == i)return k;
 			}
 			return i;
 		};

 		for(int i = n; i > 1; i -= 2){
 			int j1 = find(i);
 			op(j1);
 			int j2 = find(i - 1);
 			op(j2 - 1);
 			op(j2 + 1);
 			op(3);
 			op(i);
 		}
 		//for(int i = 1; i <= n; i++)cout << a[i] << " ";cout << endl;
 		cout << sz(res) << endl;
 		for(auto i:res)cout << i << " ";
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
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}