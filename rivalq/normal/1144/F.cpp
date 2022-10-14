//https://codeforces.com/problemset/problem/1144/F
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
const int N=100000;
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update>
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
int solve(){
  int n,m;cin>>n>>m;          
  char s[m];
  vector<pii>g[n+1];
  set<pii>st;
  rep3(m){
      int a,b;
      cin>>a>>b;
      g[a].pb({b,i});
      g[b].pb({a,i});
      st.insert({a,b});
  }          
  int vis[n+1]={0};
  int lvl[n+1]={0};
  queue<int>q;
  q.push(1);
  set<int>in,out;
  while(!q.empty()){
      int v=q.front();
      q.pop();
      vis[v]=1;
      for(auto i:g[v]){
            if(lvl[v]%2==0){
                if(out.count(v) || in.count(i.x)){
                      cout<<"NO"<<endl;ret;
                  }
                  int idx=i.y;
                  s[idx]=(st.count({v,i.x}))?'1':'0'; 
                  in.insert(v);
                  out.insert(i.x);
              }
              else{
                  if(out.count(i.x) || in.count(v)){
                      cout<<"NO"<<endl;ret;
                  }
                  int idx=i.y;
                  s[idx]=(st.count({v,i.x}))?'0':'1'; 
                  in.insert(i.x);
                  out.insert(v);
              }
              if(!vis[i.x]){
                vis[i.x]=1;
                q.push(i.x); 
                lvl[i.x]=lvl[v]+1;
              } 
          }
  }
  cout<<"YES"<<endl;
  for(int i=0;i<m;i++)cout<<s[i];
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