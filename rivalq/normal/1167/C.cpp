//https://codeforces.com/contest/1167/problem/C
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
int solve(){
  int n,m;cin>>n>>m;
  set<int> g[n+1];
  lop(i,m,1){
      int k,a;cin>>k;
      if(k==0)continue;
      cin>>a;
      lop(j,k-1,1){
          int b;cin>>b;
          g[a].insert({b});
          g[b].insert({a});
          
      }
  }
  int ans[n+1]={0};
  int visit[n+1]={0};
  for(int i=1;i<=n;i++){
      if(!visit[i]){
        queue<int> q;
        q.push(i);
        set<int> temp;
        while(!q.empty()){
            int v=q.front();
            q.pop();
            visit[v]=1;
            temp.insert({v});
            for(auto j:g[v]){
                if(!visit[j]){
                    visit[j]=1;
                    q.push(j);
                }
            }
        }
        int k=temp.size();
        for(auto j:temp)ans[j]=k;
      }
  }
  for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;
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