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
 		vector<int>a(n+1);
 		vector<int>b(n+1);
 		vector<pii>seg1,seg2;
 		rep(i,1,n+1){
 			cin >> a[i];
 		}
 		int ans = 0;
 		rep(i,1,n+1){
 			cin >> b[i];
 			ans += abs(a[i]-b[i]);
 			if(a[i] >= b[i]){
 				seg1.push_back({b[i],a[i]});
 			}
 			else{
 				seg2.push_back({a[i],b[i]});
 			}
 		}
 		sort(seg1.begin(),seg1.end());
 		sort(seg2.begin(),seg2.end());
 		auto solve = [&](vector<pii>a,vector<pii>b){
 			int j = 0;
 			int m = a.size();
 			int mx = -1e9;
 			int res = 0;
 			for(int i = 0; i < b.size(); i++){
 				while(j < m and a[j].x <= b[i].x){
 					maxs(mx,a[j++].y);
 				}
 				if(mx >= b[i].x){
 					int val = min(mx,b[i].y) - b[i].x;
 					maxs(res,val);
 				}
 			}
 			return res;
 		};
 		cout << ans - 2*max(solve(seg1,seg2),solve(seg2,seg1)) << endl;
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