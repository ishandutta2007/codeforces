#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}


const int N=2e5+5;

vector<int>g[N],sg[N];
int dp[N];
int vis[N];
int dep[N];
set<pii>bridges;

void dfs(int u,int p){
		vis[u]=1;
 		for(auto i:g[u]){
 			if(i!=p){
 				if(vis[i]){
 					if(dep[i]<dep[u]){
 						dp[u]++;
 						
 					}
 					else{
 						dp[u]--;
 					}
 				}
 				else{	
 					dep[i]=dep[u]+1;
 					dfs(i,u);
 					dp[u]+=dp[i];
 				}
 			}
 		}
 		if(u!=1 && dp[u]==0){
 			bridges.insert({min(p,u),max(p,u)});
 		}
}

const int maxn=200005;
int p[maxn];
int sz[maxn];
void clear(int n){
    rep(i,0,n+1)p[i]=i,sz[i]=1;
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
    }
    else{
        p[p1]=p2;
        sz[p2]+=sz[p1];
    }
}
int solve(){
 	int n;cin>>n;
 	vector<pii>edges(n+1);
 	rep(i,1,n+1){
 		vis[i]=0,dp[i]=0,dep[i]=0;g[i].clear();
 	}
 	bridges.clear();
 	rep(i,1,n+1){
 		cin>>edges[i];
 		if(edges[i].x>edges[i].y)swap(edges[i].x,edges[i].y);
 		g[edges[i].x].pb(edges[i].y);
 		g[edges[i].y].pb(edges[i].x);
 	}
 	dfs(1,0);
 	clear(n+1);
 	int ans=0;
 	rep(i,1,n+1){
 		if(bridges.count(edges[i])){
 			int u=edges[i].x;
 			int v=edges[i].y;
 			ans+=sz[root(u)]*sz[root(v)];
 			merge(u,v);
 		}	
 	}
 	vector<int>t;
 	int cnt=0;
 	rep(i,1,n+1){
 		if(root(i)==i){
 			if(sz[i]>1)t.pb(sz[i]);
 			else cnt++;
 		}
 	}
 	int s1=0,s2=0;
 	for(auto i:t){
 		s1+=i;
 		s2+=i*i;
 	}
 	ans+=s1*s1-s2;
 	ans+=cnt*(cnt-1)+2*cnt*(n-cnt);
 	cout<<ans<<endl;
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