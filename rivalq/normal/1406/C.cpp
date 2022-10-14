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

const int maxn=200005;
set<int>g[maxn];
int sz[maxn];
int temp=0;
int p[maxn];
/**** CENTROID DECOMPOSITION****/
void dfs1(int u,int par){
	 sz[u]=1;
	 temp++;
	 p[u]=par;
	 for(auto i:g[u]){
	 	if(i!=par){
            		dfs1(i,u);
            		sz[u]+=sz[i];
	 	}
	 }
}
int dfs2(int u,int par){
	 for(auto i:g[u]){
	 	if(i!=par && sz[i]>temp/2){
             	return dfs2(i,u);
	 	}
	 }
	 return u;
}
int decompose(int u,int par){
   temp=0;
   dfs1(u,u);
   int centroid=dfs2(u,u);
   return centroid;
}

int solve(){
 	int n;cin>>n;
 	rep(i,1,n+1){
 		g[i].clear();
 		sz[i]=0;
 	}
 	int u,v;
 	rep3(n-1){
 		int a,b;cin>>a>>b;
 		g[a].insert(b);
 		g[b].insert(a);
 		u=a,v=b;
 	}
 	if(n%2==1){
 		cout<<u<<" "<<v<<endl;
 		cout<<u<<" "<<v<<endl;return 0;
 	}
 	int cen=decompose(1,1);
 	dfs1(cen,cen);
 	for(auto i:g[cen]){
 		if(sz[i]==n/2){
 			int v;
 			for(auto j:g[i]){
 				if(j!=cen){
 					v=j;break;
 				}
 			}
 			cout<<v<<" "<<i<<endl;
 			cout<<cen<<" "<<v<<endl;return 0;
 		}
 	}
 	cout<<u<<" "<<v<<endl;
 	cout<<u<<" "<<v<<endl;return 0;

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