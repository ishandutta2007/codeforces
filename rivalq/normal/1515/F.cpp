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

const int maxn = 300005;
int p[maxn];
int sz[maxn];
int a[maxn];
vector<pii>vec[maxn];
int w;
void clear(int n=maxn){
    rep(i,0,maxn)p[i]=i,sz[i]=1;
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
   
    if(sz[p1]>=sz[p2]){
        p[p2]=p1;
        sz[p1]+=sz[p2];
        a[p1] += a[p2];
        a[p1] -= w;
        for(auto i:vec[p2])vec[p1].push_back(i);
        vec[p2].clear();	
    }
    else{
        p[p1]=p2;
        sz[p2]+=sz[p1];
        a[p2] += a[p1];
        a[p2] -= w;
        for(auto i:vec[p1])vec[p2].push_back(i);
        vec[p1].clear();
    }
}


int solve(){
 		int n,m; cin >> n >> m >> w;
 		clear();
 		int s = 0;
 		rep(i,1,n+1){
 			cin >> a[i];
 			s += a[i];
 		} 
 		if((n-1)*w > s){
 			cout << "NO" << endl;
 			return 0;
 		}
 		cout << "YES" << endl;
 		vector<vector<pii>>g(n+1);
 		vector<int>edges;
 		vector<int>vis(n+1);

 		rep(i,1,m+1){
 			int a,b; cin >> a >> b;
 			g[a].push_back({b,i});
 			g[b].push_back({a,i});
 		}
 		set<pii>st;
 		for(int i = 1; i <= n; i++){
 			st.insert({a[i],i});
 			vec[i] = g[i];
 		}
 		while(!st.empty()){
 			auto itr = st.rbegin();
 			int p = itr -> y;
 			st.erase(*itr);
 			assert(root(p) == p);
 			while(!vec[p].empty() and root(vec[p].back().x) == root(p))vec[p].pop_back();
 			if(vec[p].size() > 0){
 				edges.push_back(vec[p].back().y);
 				int j = vec[p].back().x;
 				st.erase({a[root(j)],root(j)});
 				merge(vec[p].back().x,p);
 				st.insert({a[root(p)],root(p)});
 			}
 		}
 		for(auto i:edges)cout << i << endl;
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