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
 		int n;cin>>n;
 		vector<int>a(n+1);
 		rep(i,1,n+1){
 			cin>>a[i];
 		}
 		if(n == 1){
 			cout << a[1] << endl; return 0;
 		}
 		vector<int>mx;

 		for(int i = 1; i <= n; i += 2){
 			mx.push_back(a[i]);
 		}

 		int m = (n+1)/2;

 		for(int i = 2; i <= n ; i += 2){
 			mx.push_back(a[i]);
 		}

 		vector<int>res = mx;

 		for(auto i:mx){
 			res.push_back(i);
 		}

 		int t = 0;

 		for(int i=0;i<m;i++){
 			t += res[i];
 		}

 		int ans = t;


 		for(int i = m; i < res.size(); i++){
 			t -= res[i-m];
 			t += res[i];
 			maxs(ans,t);
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