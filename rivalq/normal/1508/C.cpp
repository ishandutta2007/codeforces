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

const int INF = 1LL << 30;

const int maxn=200005;
int p[maxn];
int sz[maxn];
vector<int>vec[maxn];


void clear(int n=maxn){
    rep(i,0,maxn)p[i]=i,sz[i]=1,vec[i].push_back(i);
}
int root(int x){
   while(x!=p[x]){
       p[x]=p[p[x]];
       x=p[x];
   }
   return x;  
}
void merge(int x,int y){
    int p1=root(x);
    int p2=root(y);
    if(p1==p2)return;
    if(sz[p1] < sz[p2]){
    	swap(p1,p2);
    }
    p[p2]=p1;
    sz[p1]+=sz[p2];

}

int solve(){
 		int n,m ; cin >> n >> m;
 		vector<pair<int,pii>>edges;
 		vector<vector<int>>g(n+1);
 		int x = 0;
 		for(int i = 0; i < m ; i++){
 			int u,v,w; cin >> u >> v >> w;
 			edges.push_back({w,{u,v}});
 			g[u].push_back(v);
 			g[v].push_back(u);
 			x ^= w;
 		}
 		int rem = n*(n-1)/2 - m;
 		clear();
 		sort(all(edges));
 		if(rem <= n- 1){
 			vector<vector<int>>adj(n+1,vector<int>(n+1,0));
 			vector<pii>reqd;
 			vector<pair<int,pii>>check;
 			for(auto i:edges){
 				adj[i.y.x][i.y.y] = i.x;
 				adj[i.y.y][i.y.x] = i.x;
 			}
 			bool found = 0;
 			for(int i = 1; i <= n; i++){
 				for(int j = i + 1; j <= n; j++){
 					if(adj[i][j] == 0){
 						if(root(i) == root(j)){
 							found = 1;
 							continue;
 						}
 						merge(i,j);
 					}
 				}
 			}
 			int ans = 0;
			for(auto i:edges){
				int u = i.y.x;
				int v = i.y.y;
				if(root(u) != root(v)){
					merge(u,v);
					reqd.push_back({u,v});
					ans += i.x;
				}
				else{
					if(i.x < x){
						check.push_back(i);
					}
				}
			}
 			if(found){
 				cout << ans << endl;
 				return 0;
 			}
 			else{
 				//forest
 				ans += x;
 				clear();
 				for(auto [i,j]:reqd){
 					merge(i,j);
 				}
 				int t = ans;
 				for(auto [i,j]:check){
 					if(root(j.x) != root(j.y)){
 						mins(ans,t - x + i);
 					}
 				}
 				cout << ans << endl;
 				return 0;
 			}
 		}
 		set<int>st;
 		st.insert(1);
 		for(int i = 2; i <= n; i++){
 			map<int,int>mp;
 			for(auto j:g[i]){
 				if(j < i){
 					mp[root(j)]++;
 				}
 			}
 			bool found = 0;
 			vector<int>t;
 			for(auto j:st){
  				if(sz[j] > mp[j]){
 					t.push_back(j);
 				}
 			}
 			for(auto j:t){
 				st.erase(j);
 				merge(i,j);
 			}
 			st.insert(root(i));
 			if(t.size() == 0){
 				st.insert(i);
 			}
 		}

 		int ans = 0;
 		for(auto i:edges){
 			int u = i.y.x;
 			int v = i.y.y;
 			if(root(u) != root(v)){
 				ans += i.x;
 				merge(u,v);
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