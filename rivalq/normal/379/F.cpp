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
const int maxn=1000005;
vector<int> g[maxn];
int p[maxn];
int b_p[maxn][24];
int level[maxn];
void dfs(int n,int e,int l){
     p[n]=e;
     level[n]=l;
     for(auto i:g[n]){
         if(i!=e){
             dfs(i,n,l+1);
         }
     }
     return;
}
void lift(int n){
     for(int i=0;i<=23;i++){
         for(int j=1;j<=n;j++){
             if(i==0)b_p[j][i]=p[j];
             else b_p[j][i]=b_p[b_p[j][i-1]][i-1];
         }
     }
     return;
}
int lca(int u, int v){
   if(level[v]<level[u])u=v+u-(v=u);
   int diff=level[u]-level[v];
   for (int i=23;i >= 0; i--) {
        if (level[v]-level[u] >=(1 << i)) {
            v = b_p[v][i];
        }
   }
   if(v==u){
       return u;
   }
   int k=ceil(log2(level[u]));
   while(k>=0){
        if(b_p[u][k]!=b_p[v][k]){
            u=b_p[u][k];
            v=b_p[v][k];
        }
        k--;
   } 
   return p[u];

}
int d(int u,int v){
	return level[u]+level[v]-2*level[lca(u,v)];
}
int solve(){
 int n;cin>>n;
 g[1].pb(2);
 g[2].pb(1);
 g[1].pb(3);
 g[3].pb(1);
 g[4].pb(1);
 g[1].pb(4);
 dfs(1,1,0);
 lift(4);
 int v1=2;
 int v2=3;
 int cnt=4;
 int cur=2;
 rep3(n){
 	int v;cin>>v;
 	int new_node=++cnt;
 	int new_node2=++cnt;
 	level[new_node]=level[v]+1;
 	level[new_node2]=level[v]+1;
 	p[new_node]=v;
 	p[new_node2]=v;
    for(int i=0;i<=23;i++){
    	if(i==0)b_p[new_node][i]=p[new_node];
        else b_p[new_node][i]=b_p[b_p[new_node][i-1]][i-1];
    }
    for(int i=0;i<=23;i++){
    	if(i==0)b_p[new_node2][i]=p[new_node2];
        else b_p[new_node2][i]=b_p[b_p[new_node2][i-1]][i-1];
    }
    int cur1=d(new_node,v1);
    int cur2=d(new_node,v2);
    if(max(cur1,cur2)>cur){
       cur=max(cur1,cur2);
       if(cur1>cur2)v2=new_node;
       else v1=new_node;
    }
    //cout<<v1<<" "<<v2<<endl;
    cout<<cur<<endl;
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
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}