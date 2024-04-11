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

 		vector<int> a(n + 1);
 		for(int i = 1; i <= n; i++){
 			cin >> a[i];
 		}
 		for(int i = 1; i <= n; i++){
 			int x; cin >> x;
 			a[i] -= x;
 			a[i] += a[i - 1];
 		}

 		vector<vector<int>> g(n + 1);
 		vector<pii> segs(m);
 		vector<int> deg(m,2);
 		for(int i = 0; i < m; i++){
 			cin >> segs[i];
 			segs[i].x--;
 			g[segs[i].x].push_back(i);
 			g[segs[i].y].push_back(i);
 		}
 		vector<int> q;
 		set<int> st;
 		for(int i = 0; i <= n; i++){
 			st.insert(i);
 			if(a[i] == 0){
 				q.push_back(i);
 				st.erase(i);
 			}
 		}	
 		for(int i = 0; i < q.size(); i++){
 			auto u = q[i];
 			for(auto j: g[u]){
 				deg[j]--;
 				if(deg[j] == 0){
 					auto [l,r] = segs[j];
 					auto itl = st.lower_bound(l);
 					auto itr = st.upper_bound(r);
 					auto save = itl;
 					while(itl != itr)q.push_back(*itl),itl++;
 					st.erase(save,itr);
 				}
 			} 
 		}
 		if(st.size() > 0){
 			cout << "NO" << endl;
 			return 0;
 		}else{
 			cout << "YES" << endl;
 			return 0;
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