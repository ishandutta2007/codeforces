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
 		int n,r,k; cin >> n >> r >> k;
 		vector<int>pre(n+2);
 		rep(i,1,n+1){
 			int t; cin >> t;
 			int L = max(1LL,i - r);
 			int R = min(n,i + r);
 			pre[L] += t;
 			pre[R + 1] -= t; 
 		}

 		

 		auto f = [&](int x){
 			int s = 0;
 			int cnt = 0;
 			vector<int> p = pre;
 			for(int i = 1; i <= n; i++){
 				s += p[i];
 				if(s < x){
 					int need = x - s;
 					int L = i;
 					int R = min(n,i + 2*r);
 					s += need;
 					p[L] += need;
 					p[R + 1] -= need;
 					if(cnt + need > k)return false;
 					cnt += need;
 				}
 			}
 			return cnt <= k;
 		};
 		int L = 0,R = 2e18;
 		int ans = 0;
 		while(L <= R){
 			int M = (L+R)/2;
 			if(f(M)){
 				ans = M;
 				L = M+1;
 			}
 			else{
 				R = M - 1;
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