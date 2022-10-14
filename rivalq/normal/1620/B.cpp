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
 		int w,h; cin >> w >> h;
 		vector<vector<int>> a(4);
 		vector<int> mx(4),m1(4),m2(4);
 		for(int i = 0; i < 4; i++){
 			int k; cin >> k;
 			a[i].resize(k);
 			for(auto &j:a[i])cin >> j;
 			sort(all(a[i]));
 			mx[i] = a[i][k - 1] - a[i][0];
 			m1[i] = a[i][k - 1];
 			m2[i] = a[i][0];
 		}
 		int ans = max({mx[0]*h,mx[1]*h,mx[2]*w,mx[3]*w});
 		ans = max(ans,mx[0]*m1[2]);
 		ans = max(ans,mx[0]*m1[3]);
 		ans = max(ans,mx[1]*(h - m2[2]));
 		ans = max(ans,mx[1]*(h - m2[3]));
 		ans = max(ans,mx[2]*m1[0]);
 		ans = max(ans,mx[2]*m1[1]);
 		ans = max(ans,mx[3]*(w - m2[0]));
 		ans = max(ans,mx[3]*(w - m2[1]));
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