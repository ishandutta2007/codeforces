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


const int N = 2e5+5;

vector<int>g[N];
int vis[N];
int id[N];
int t=0;

bool dfs(int u){
	vis[u]=1;
	for(auto i:g[u]){
		if(vis[i]==1){
			return 0;
		}
		else if(!vis[i]){
			bool f=dfs(i);
			if(f==0)return 0;
		}
	}
	id[u]=t--;
	vis[u]=2;
	return 1;
}

int solve(){
 		int n,m;cin>>n>>m;t=n;
 		rep(i,1,n+1){
 			id[i]=0,g[i].clear();vis[i]=0;
 		}
 		vector<pii>edges;
 		vector<pii>ans;
 		rep(i,0,m){
 			int t,a,b;cin>>t>>a>>b;
 			if(t){
 				g[a].push_back(b);
 				ans.push_back({a,b});
 			}
 			else{
 				edges.push_back({a,b});
 			}
 		}

 		rep(i,1,n+1){
 			if(!vis[i]){
 				bool f=dfs(i);
 				if(!f){
 					cout<<"NO"<<endl;return 0;
 				}
 			}
 		}
 		cout<<"YES"<<endl;
 		for(auto i:edges){
 			int u=i.x,v=i.y;
 			if(id[u]>id[v])swap(u,v);
 			ans.push_back({u,v});
 		}
 		for(auto i:ans)cout<<i<<endl;
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