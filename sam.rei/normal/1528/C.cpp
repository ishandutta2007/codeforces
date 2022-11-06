#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int n;

int st[300001];
int et[300001];

int dfs(vector<vector<int>>& a, int curr,FenwickTree& f, int acc){
  // use st and et
  int prev = -1;
  int ancestor = f.sum(st[curr]);
  if(ancestor>0){
    prev = ancestor-1;
    f.add(st[prev], -(prev+1));
    f.add(et[prev], prev+1);
    //cout<<curr<<" conflicts with "<<prev<<endl;
  }else{
    ++acc;
  }
  f.add(st[curr],curr+1);
  f.add(et[curr],-(curr+1));
  int ma=1;
  for(int s:a[curr]){
    int res = dfs(a,s,f,acc);
    ma = max(ma,res);
  }
  if(ancestor>0){
    f.add(st[prev], (prev+1));
    f.add(et[prev], -(prev+1));
  }
  f.add(et[curr],curr+1);
  f.add(st[curr],-(curr+1));
  return max(ma,acc);
}

int dfst=0;
void dfs1(vector<vector<int>>& g,int k){
  st[k]=dfst;
  dfst++;
  for(int i:g[k])dfs1(g,i);
  et[k]=dfst;
  dfst++;
}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC;
  cin>>TC;
  while(TC-->0){
    cin>>n;
    vector<int> pa(n,0);
    vector<vector<int>> adj(n);
    vector<int> pb(n,0);
    vector<vector<int>> gb(n);
    for(int i=1;i<n;++i){
      int k;
      cin>>k;
      pa[i]=k-1;
      adj[k-1].push_back(i);
    }
    for(int i=1;i<n;++i){
      int k;
      cin>>k;
      pb[i]=k-1;
      gb[k-1].push_back(i);
    }
    vector<int> st(n);
    vector<int> et(n);
    dfst=0;
    dfs1(gb,0);
    FenwickTree f(2*n);
    cout<<dfs(adj,0,f,0)<<"\n";
  }
  
  cout<<flush;
}