#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
#define ook order_of_key
#define fbo find_by_order
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


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}
const int maxn=20005;
vector<int>g[maxn];
int sz[maxn];
int c[maxn];
int a[maxn];
Tree<int>tr;
void dfs(int u,int p){
     sz[u]++;
     for(auto i:g[u]){
     	if(i!=p){
     		dfs(i,u);
     		sz[u]+=sz[i];
     	} 
     }
     if(c[u]>=sz[u]){
     	cout<<"NO"<<endl;exit(0);
     }
}
void dfs2(int u,int p){
	 a[u]=*tr.fbo(c[u]);
	 tr.erase(a[u]);
	 for(auto i:g[u]){
	 	if(i!=p){
	 		dfs2(i,u);
	 	}
	 }
}
int solve(){
 int n;cin>>n;
 int r;
 rep(i,1,n+1){
 	int p,cc;cin>>p>>cc;
 	c[i]=cc;
 	if(p==0)r=i;
 	else {
 		g[p].pb(i);
 		g[i].pb(p);
 	}
 	tr.insert(i);
 }
 dfs(r,r);
 dfs2(r,r);
 cout<<"YES\n";
 for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
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