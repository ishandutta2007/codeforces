//https://codeforces.com/problemset/problem/1133/F2
#pragma GCC optimize "trapv" 
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define inarr(arr,n)   rep(i,a,n)cin>>arr[i]
#define ll             long long int
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define IOS            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret            return 0
#define pi             3.1415926536
#define hell           1000000007
#define narak          998244353
#define elasped_time 1.0 * clock() / CLOCKS_PER_SEC
const int inf1=1e9;
const ll inf2=1e18;
const int N=200010;
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update>
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
bool good[N];
int p[2*N+10];
ll sz[2*N+10];
vector<pair<int,pii>> edges;
vector<pii>ans;
int root(int x){
   while(x!=p[x]){
       p[x]=p[p[x]];
       x=p[x];
   }
   return x;  
}
void merge2(int x,int y){
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
 int n,m,d;cin>>n>>m>>d;   
 int cnt=0;        
 for(int i=0;i<m;i++){
     int a,b;cin>>a>>b;
     if(a>b)swap(a,b);
     edges.pb({i,{a,b}});
     if(a==1)good[b]=1,cnt++;
 }           
 if(cnt<d){
     cout<<"NO"<<endl;ret;
 }
 for(int i=0;i<=n;i++)p[i]=i;
 for(int i=0;i<m;i++){
     if(edges[i].y.x==1)continue;
     merge2(edges[i].y.x,edges[i].y.y);
 }
 set<int>s;
 for(int i=2;i<=n;i++)s.insert(root(i));
 if(sz(s)>d){
     cout<<"NO"<<endl;ret;
 }
 s.clear();
 for(int i=2;i<=n;i++){
     if(good[i]){
        s.insert(i);
     }
 }
 set<int>st2;
 vector<int>v;
 for(auto i:s){
    if(root(1)!=root(i)){
        merge2(1,i);
        d--;
        v.pb(i);
        ans.pb({1,i});
    }
    else{
        st2.insert(i);
    }
 }
 while(d--){
     merge2(*st2.begin(),1);
     v.pb(*st2.begin());
     ans.pb({1,v.back()});
     st2.erase(st2.begin());
 }
 for(int i=1;i<=n;i++)p[i]=i;
 for(int i=1;i<v.size();i++)merge2(v[i],v[i-1]);
 for(int i=0;i<m;i++){
     if(edges[i].y.x==1)continue;
     if(root(edges[i].y.x)!=root(edges[i].y.y)){
         merge2(edges[i].y.x,edges[i].y.y);
         ans.eb(edges[i].y.x,edges[i].y.y);
     }
 }
 cout<<"YES"<<endl;
 for(auto i:ans)cout<<i.x<<" "<<i.y<<endl;
 ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef cat
    cat();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}