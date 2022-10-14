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
 		vector<int>cost(n+1);
 		rep(i,1,n+1){
 			int x,y; cin >> x >> y;
 			int c = 0;
 			if(x > y){
 				c = 1;
 				swap(x,y);
 			}
 			if(x > n){
 				cout << -1 << endl;
 				return 0;
 			}
 			cost[x] = c;
 			a[x] = y;
 		}
 		vector<int>suf(n+2,-1);
 		vector<int>pre(n+1,2*n+1);
 		for(int i = n; i >= 1; i--){
 			suf[i] = suf[i+1];
 			maxs(suf[i],a[i]);
 		}
 		for(int i = 1; i <= n; i++){
 			pre[i] = pre[i-1];
 			mins(pre[i],a[i]);
 		}
 		int ans = 0;
 		int head_1 = 2*n+1;
 		int head_2 = 2*n+1;
 		int len1 = 0;
 		int len2 = 0;
 		int cost1 = 0;
 		int cost2 = 0;
 		for(int i = 1; i <= n; i++){
 			if(a[i] < head_1){
 				head_1 = a[i];
 				len1++;
 				cost1 += cost[i];
 			}
 			else if(a[i] < head_2){
 				head_2 = a[i];
 				len2++;
 				cost2 += cost[i];
 			}
 			else{
 				cout << -1 << endl;
 				return 0;
 			}
 			if(pre[i] > suf[i+1]){
 				int val1 = len1 - cost1 + cost2;
 				int val2 = len2 - cost2 + cost1;
 				ans += min(val1,val2);
 				len1 = len2 = cost1 = cost2 = 0;
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