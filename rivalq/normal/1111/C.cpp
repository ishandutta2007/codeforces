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
 		int n,k,A,B;
 		cin >> n >> k >> A >> B;
 		vector<int>v;
 		for(int i = 0; i < k ; i++){
 			int x; cin >> x;
 			v.push_back(x);
 		}
 		sort(all(v));
 		auto q = [&](int l,int r){
 			return upper_bound(all(v),r) - lower_bound(all(v),l);
 		};
 		function<int(int,int)> dfs = [&](int l,int r){
 			if(l == r){
 				auto s = q(l,l);
 				if(s == 0)return A;
 				return B*s;
 			}else{
 				auto s = q(l,r);
 				if(s == 0){
 					return A;
 				}
 				auto dp = s*(r - l + 1)*B;
 				int mid = (l + r)/2;
 				mins(dp,dfs(l,mid)+dfs(mid+1,r));
 				return dp;
 			}
 		};
 		cout << dfs(1, (1LL << n)) << endl;

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