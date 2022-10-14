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

 		map<int,vector<array<int,3>>> vec;
 		vector<pii> org(n + 1);
 		vector<int> temp(n + 1);
 		for(int i = 1; i <= n; i++){
 			int a,b,m; cin >> a >> b >> m;
 			org[i] = {a,b};
 			temp[i] = m;
 			int l = max(0LL,a - m);
 			int min_eat = max(0LL,-(b - m));
 			int r = a - min_eat;
 			vec[a + b - m].push_back({l,r,i});
 		}
 		int ans = 0;
 		vector<pii> res(n + 1);
 		auto find_union = [&](auto segs){
 			sort(segs.begin(),segs.end(),[&](auto &a,auto &b){
 				return a[1] < b[1];
 			});
 			int t = -1;
 			for(auto i:segs){
 				int l = i[0],r = i[1],j = i[2];
 				if(l > t){
 					ans++;
 					t = r;
 				}
 				res[j].x = org[j].x - t;
 				res[j].y = temp[j] - res[j].x;
 			}
 		};
 		for(auto i:vec)find_union(i.y);
 		cout << ans << endl;
 		for(int i = 1; i <= n; i++){
 			cout << res[i] << endl;
 		}

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