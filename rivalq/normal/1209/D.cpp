//https://codeforces.com/problemset/problem/1209/D
#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
#define inarr(arr,n) lop(i,n,1)cin>>arr[i]
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define endl "\n"
#define eb emplace_back
#define fr first
#define sc second
#define pii pair<int,int>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define hell 1000000007
using namespace std;
// syntax for min priority_queue of pairs
// priority_queue<pair<ll,ll>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
const int N=100001;
ll cycles=0;
set<int> g[N];
int parr[N];
int color[N]={0};
void dfs_cycle(int s,int p){
    if(color[s]==2)return;
    if(color[s]==1){
        cycles++;
        return;
    }
    color[s]=1;
    for(auto i:g[s]){
        if(i==p)continue;
        else{
           dfs_cycle(i,s);
        }
    }
    color[s]=2;
}
int solve(){
  int n,m;cin>>n>>m;
  lop(i,m,1){
      int a,b;cin>>a>>b;
      if(g[a].find(b)!=g[a].end()) cycles++;
  else{g[a].insert(b);
      g[b].insert(a);
  }
  }
  for(int i=1;i<=100000;i++){
   if(color[i]==0) 
   dfs_cycle(i,0);
  }
  cout<<cycles<<endl;
  ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}