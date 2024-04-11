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
 		vector<int> a(n);
 		for(auto &i:a)cin >> i;

 		auto func = [&](int m){
 			int th = m/2 + (m%2);
 			vector<int> pre(n),suf(n);
 			pre[0] = a[0] < th;
 			for(int i = 1; i < n; i++)pre[i] = pre[i - 1] + (a[i] < th);
 			suf[n - 1] = a[n - 1] < th;
 			for(int i = n - 2; i >= 0; i--)suf[i] = suf[i + 1] + (a[i] < th);

 			for(int i = 0; i + 1 < n; i++){
 				int cnt = 0;
 				if(i > 0)cnt += pre[i - 1];
 				if(i + 2 < n)cnt += suf[i + 2];
 				cnt += (a[i] < m) + (a[i + 1] < m);
 				if(cnt <= k)return true;
 			}	
 			return false;

 		};

 		int L = 1, R = 1e9;	
 		int ans = 1;
 		while(L <= R){
 			int M = (L + R)/2;
 			if(func(M)){
 				ans = M;
 				L = M + 1;
 			}else{
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
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}