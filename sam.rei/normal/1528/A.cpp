#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

//int dfstime;
//vector<int> starts;
//vector<int> ends;
//vector<ll> partials;
//vector<int> path;
ll l[100001];
ll r[100001];
vector<int> p;
pair<ll,ll> dfs(vector<vector<int>>& g, int index){
  ll ltotal=0;
  ll rtotal=0;
  for(int n:g[index]){
    if(p[n]==-1)p[n]=index;
    if(p[n]==index){
      // sum all distinct
      pair<ll,ll> tots=dfs(g,n);
      ltotal += max(tots.first + abs(l[n]-l[index]),tots.second+abs(r[n]-l[index]));
      rtotal += max(tots.first + abs(l[n]-r[index]),tots.second+ abs(r[n]-r[index]));
      
    }
  }
  // cout<<index<<" "<<ltotal<<" "<<rtotal<<endl;
  return make_pair(ltotal,rtotal);
}

int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC;
  cin>>TC;
  while(TC-->0){
    int N;
    cin>>N;
    p.resize(N);
    vector<vector<int>> g(N);
    for(int i=0;i<N;++i){
      cin>>l[i]>>r[i];
      p[i]=-1;
    }
    p[0]=0;
    for(int i=1;i<N;++i){
      int a,b;
      cin>>a>>b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    pair<ll,ll> res= dfs(g,0);
    // answer is convex for each value, left or rightmost is optimal pick
    cout<<max(res.first,res.second)<<endl;
  }
  
  cout<<flush;
}