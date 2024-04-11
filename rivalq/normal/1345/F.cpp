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
 		int n,k; cin >> n >> k;
 		vector<int> a(n + 1);

 		for(int i = 1; i <= n; i++)cin >> a[i];

 		auto f = [&](int i, int x){
 			return a[i] - 1 - 3*x - 3*x*x;
 		};

 		auto get = [&](int i,int delta){
 			// minimum x such that, x <= a[i] 
 			// and a[i] - 1 - 3x - 3x^2 < delta
 			int L = 0, R = a[i];
 			int res = a[i];
 			while(L <= R){
 				int M = (L + R)/2;
 				if(f(i,M) < delta){
 					res = M;
 					R = M - 1;
 				}else{
 					L = M + 1;
 				}
 			} 
 			return res;
 		};

 		auto check = [&](int delta){
 			int cnt = 0;
 			for(int i = 1; i <= n; i++){
 				cnt += get(i,delta);
 			}
 			return cnt;
 		};
 		int L = -4e18, R = 1e9;
 		int delta = 0;
 		while(L <= R){
 			int M = (L + R)/2;
 			if(check(M) > k){
 				L = M + 1;
 			}else{
 				delta = M;
 				R = M - 1;
 			}
 		}
 		vector<int> ans(n + 1);
 		int cnt = 0;
 		set<pair<int,int>>st;
 		for(int i = 1; i <= n; i++){
 			ans[i] = get(i,delta);
 			cnt += ans[i];
 			if(ans[i] < a[i])st.insert({f(i,ans[i]),i});
 		}
 		k -= cnt;
 		while(k > 0){
 			k--;
 			auto itr = *st.rbegin();
 			st.erase(itr);
 			int i = itr.y;
 			ans[i]++;
 			if(ans[i] < a[i]){
 				st.insert({f(i,ans[i]),i});
 			}
 		}
 		int func = 0;
 		for(int i = 1; i <= n; i++){
 			func += ans[i]*(a[i] - ans[i]*ans[i]);
 			cout << ans[i] << " ";
 		}
 		cout << endl;
 		//cout << func << endl;

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