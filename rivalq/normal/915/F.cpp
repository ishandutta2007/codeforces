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
int p[maxn];
int sz[maxn];
vector<int>g[maxn];
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
    }
    else{
        p[p1]=p2;
        sz[p2]+=sz[p1];
    }
}

int solve(){
 int n;cin>>n;
 vector<pii>a(n+1),b(n+1);
 vector<int>val(n+1,0);
 b[0].x=1e9;
 rep(i,1,n+1)cin>>a[i].x,b[i].x=a[i].x,b[i].y=a[i].y=i;
 rep3(n-1){
 	int a,b;cin>>a>>b;
 	g[a].pb(b);
 	g[b].pb(a);
 }
 sort(all(a));
 sort(all(b),greater<pii>());
 int ans=0;
 for(int i=1;i<=n;i++){
 	int s=0;
 	val[a[i].y]=1;
 	for(auto j:g[a[i].y]){
       if(val[j])s+=sz[root(j)];
 	}
 	int v=2*s;
 	for(auto j:g[a[i].y]){
 		if(val[j])v=v+sz[root(j)]*(s-sz[root(j)]),merge(a[i].y,j);
 	}
    ans+=a[i].x*v;
 }
 clear();
 for(int i=1;i<=n;i++)val[i]=0;
 for(int i=1;i<=n;i++){
 	int s=0;
 	val[b[i].y]=1;
 	for(auto j:g[b[i].y]){
       if(val[j])s+=sz[root(j)];
 	}
 	int v=2*s;
 	for(auto j:g[b[i].y]){
       if(val[j])v=v+sz[root(j)]*(s-sz[root(j)]),merge(b[i].y,j);
 	}
 	//cout<<b[i].y<<" "<<b[i].x<<" "<<v<<endl;
    ans-=b[i].x*v;
    //cout<<ans<<endl;
 }
 cout<<ans/2<<endl;
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
    clear();
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}