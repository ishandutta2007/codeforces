//https://codeforces.com/problemset/problem/20/C
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
const int inf =2e9;
const ll inf2=1e18;
using namespace std;
// syntax for min priority_queue of pairs
// priority_queue<pair<ll,ll>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
int solve(){
  int n,m,a,b,w;
  cin>>n>>m;
  set<pii> g[n+1];
  lop(i,m,1){
    cin>>a>>b>>w;
    g[a].insert({b,w});
    g[b].insert({a,w});
  }
  // dis contains the answer and g is supposed to be the graph
  // vi is used for visited array
  priority_queue<pair<ll,ll>> pq;
    int parent[n+1]={0};
    int vi[n+1]={0};
    ll dis[n+1];
    lop(i,n+1,1)dis[i]=100*(ll)inf;
    dis[1]=0;
    pq.push({0,1});
    while(!pq.empty()){
        int node=pq.top().sc;
        ll wei=pq.top().fr;
        pq.pop();
       
        if(vi[node])continue;
        vi[node]=1;
        for(auto i:g[node]){
            int e=i.fr;
            ll w=i.sc;
            if(vi[e]==0&&dis[node]+w<dis[e]){
                dis[e]=dis[node]+w;
                pq.push({-dis[e],e});
                parent[e]=node;
                //vi[e]=1;
            }
        }
    }
    if(!parent[n] && n!=1)cout<<-1<<endl;
    else {
       stack<int> s;
       s.push(n);
       int i=n;
       while(i!=1){
           i=parent[i];
           s.push(i);
       }
       while(!s.empty()){
           cout<<s.top()<<" ";
           s.pop();
       }
       cout<<endl;
    }
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