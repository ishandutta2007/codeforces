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
const int maxn=2000005;
int p[maxn];
int sz[maxn];
vector<pii>con;
vector<int>ci;
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
void mst(vector<pair<int,pii>>&g,int n){
     sort(all(g));
     int res=0;
     clear();
     for(auto i:g){
          int x=i.y.x;
          int y=i.y.y;
          if(root(x)==root(y))continue;
          else {
          	res+=i.x;
          	merge(x,y);
          	if(x==0)ci.pb(y);
                else if(y==0)ci.pb(x);
                else con.pb({x,y}); 
          }
     }
     cout<<res<<endl;
     cout<<sz(ci)<<endl;
     for(auto i:ci)cout<<i<<" ";cout<<endl;
     cout<<sz(con)<<endl;
     for(auto i:con)cout<<i<<"\n";

}
int solve(){
 	int n;cin>>n;
 	vector<pii>cor(n+1);
 	vector<int>c(n+1),k(n+1);
 	vector<pair<int,pii>>g;
 	rep(i,1,n+1)cin>>cor[i];
        rep(i,1,n+1)cin>>c[i];
        rep(i,1,n+1)cin>>k[i];
        for(int i=1;i<=n;i++){
        	g.pb({c[i],{i,0}});
        	for(int j=i+1;j<=n;j++){
        		int w=abs(cor[i].x-cor[j].x)+abs(cor[i].y-cor[j].y);
        		w*=(k[i]+k[j]);
        		g.pb({w,{i,j}});
        	}
        } 
        mst(g,n);
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