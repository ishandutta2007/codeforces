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
 		int n,m; cin >> n >> m;
 		vector<vector<int>>g(n + 1);
 		vector<int> mp(n + 1);
 		for(int i = 1; i <= m; i++){
 			int u,v; cin >> u >> v;
 			g[v].push_back(u);
 			mp[u]++;
 		}

 		priority_queue<pii> pq;
 		vector<int> dis(n + 1,LLONG_MAX),vis(n + 1);
 		dis[n] = 0;
 		pq.push({0,n});
 		while(!pq.empty()){
 			auto [w,u] = pq.top();
 			pq.pop();
 			w *= -1;
 			if(vis[u])continue;
 			vis[u] = 1;
 			for(auto i:g[u]){
 				int dd = w + mp[i];mp[i]--;
 				if(dis[i] > dd){
 					dis[i] = dd;
 					pq.push({-dis[i],i});
 				}

 			}
 		}
 		cout << dis[1] << endl;
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