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
#define SIEVE
const int maxn=200005;
int isprime[maxn];
vector<int>primes;
void sieve(int n=maxn){
   rep(i,2,n+1)isprime[i]=1;
   for(int p=2;p*p<=n;p++){
       if(isprime[p]){
           for(int i=p*p;i<=n;i+=p){
           	  isprime[i]=0;
           }
       }
   }
}
set<int>g[maxn];
int a[maxn];
int sz[maxn];
int temp=0;
int ctree[maxn];
map<int,int>mp;
map<int,int>mp2;
vector<int>fact[maxn];
int ans=0;
/**** CENTROID DECOMPOSITION****/
void dfs1(int u,int par){
	 sz[u]=1;
	 temp++;
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
void dfs3(int u,int p,int lvl,int val){
	val=gcd(val,a[u]);
    if(val==1)return;
    ans=maxs(ans,lvl+1);
    for(auto i:fact[val]){
    	mp2[i]=max(mp2[i],lvl);
    	if(mp.count(i)){
    		maxs(ans,mp[i]+lvl+1);
    	}
    }
    for(auto i:g[u]){
    	if(i!=p)dfs3(i,u,lvl+1,val);
    }
}
void decompose(int u,int par){
   temp=0;
   mp.clear();
   mp2.clear();
   dfs1(u,u);
   int centroid=dfs2(u,u);
   if(par==-1)par=u;
   ctree[u]=par;
   if(a[centroid]!=1)maxs(ans,1);
   for(auto i:g[centroid]){
   	  dfs3(i,centroid,1,a[centroid]);
   	  for(auto i:mp2)mp[i.x]=max(mp[i.x],i.y); 
   	  mp2.clear();
   }
   for(auto i:g[centroid]){
   	  g[i].erase(centroid);
   	  decompose(i,centroid);
   } 
   g[centroid].clear();
}
int solve(){
 int n;cin>>n;
 rep3(n)cin>>a[i+1];
 rep3(n-1){
 	int a,b;cin>>a>>b;
 	g[a].insert(b);
 	g[b].insert(a);
 }
 decompose(1,-1);
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
    for(int i=2;i<=2e5;i++){
    	if(isprime[i])primes.pb(i);
    }
    for(auto j:primes){
    	for(int i=j;i<=2e5;i+=j){
           fact[i].pb(j);
    	}
    }
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    //cerr<<elasped_time<<endl;
    return 0;
}