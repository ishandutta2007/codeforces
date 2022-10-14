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
const int maxn=100005;
bool good[maxn];
vector<int> g[maxn];
int dp1[maxn],dp2[maxn];
void dfs1(int u=1,int p=-1){
     if(good[u])dp1[u]=0;
     else dp1[u]=-1e9;
     for(auto i:g[u]){
     	if(i!=p){
     		dfs1(i,u);
     		if(dp1[i]>=0)maxs(dp1[u],dp1[i]+1);
     	}
     } 
}
void dfs2(int u=1,int p=-1){
     int mx1=-1e9;
     int mx2=-1e9;
     for(auto i:g[u]){
     	 if(i!=p){
     	 	if(dp1[i]>mx1)mx2=mx1,mx1=dp1[i];
     	 	else if(dp1[i]>mx2)mx2=dp1[i];
     	 }
     }
     for(auto i:g[u]){
     	if(i==p)continue;
         int d=(dp1[i]==mx1)?mx2:mx1;
         if(d>=0)d+=2;
         dp2[i]=d;
         if(dp2[u]>=0)dp2[i]=max(dp2[i],dp2[u]+1);
         if(good[i])dp2[i]=max(dp2[i],0LL);
         dfs2(i,u);
     } 
}
int solve(){
 int n,m,d;cin>>n>>m>>d;
 for(int i=1;i<=m;i++){
 	int t;cin>>t;
 	good[t]=1;
 }
 rep3(n-1){
 	int a,b;cin>>a>>b;
 	g[a].pb(b);
 	g[b].pb(a);
 }
 dfs1();
 if(good[1])dp2[1]=0;
 else dp2[1]=-1e9;
 dfs2();
 int cnt=0;
 for(int i=1;i<=n;i++){
 	if(dp1[i]<=d && dp2[i]<=d)cnt++;
 }
 cout<<cnt<<endl;
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