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
 		int ans = 2;

 		for(int i = 1; i + 1 <= n; i++){
 			if(a[n] == a[i]){
 				maxs(ans,n - i + 1);
 				break;
 			}
 			int last = upper_bound(all(a),a[i]) - a.begin();
 			int cnt = last - i + 1;
 			int prev_idx = last;
 			last = a[last];
 			while(prev_idx < n){
 				int reqd = last + (last - a[i]);
 				if(reqd > a[n])break;
 				int j = lower_bound(all(a),reqd) - a.begin();
 				j = max(j,prev_idx + 1);
 				cnt++;	
 				last = a[j];
 				prev_idx = j;
 			}
 			maxs(ans,cnt);
 		}
 		cout << n - ans << endl;

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