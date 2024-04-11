#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()

const ll mod = 1000000007;
vector<vector<ll>> edgedp(201,vector<ll>(201));
template<typename num>
num gcd(num a, num b, num& x, num& y){
  if(b == 0){
    x=1;
    y=0;
    return a;
  }
  num d = gcd(b,a%b,x,y);
  num temp = x;
  x=y;
  y=temp-y*(a/b);
  return d;
}
template<typename num>
num modinv(num a, num m){
  num x,y;
  assert(1==gcd(a,m,x,y));
  return (x+m)%m;
}

int n;
int dfs1(int curr, vector<vector<int>>& g,vector<bool>& seen,vector<int>& desc){
  int res =1;
  seen[curr]=true;
  for(int c:g[curr]){
    if(seen[c])continue;
    res += dfs1(c,g,seen,desc);
  }
  return desc[curr]=res;
}
void dfs2(ll& res, const int& source, int curr, vector<vector<int>>& g,vector<bool>& seen, vector<int>& desc, vector<int>& currpath){
  currpath.push_back(curr);
  if(curr>source){
    ll cu= res;
    int l = currpath.size();
    for(int i=1;i<l-1;++i){
      res += ((desc[currpath[i]]-desc[currpath[i+1]])* edgedp[i][l-i-1])%mod;
    }
    res += desc[curr];
    //cout<< curr<<" "<<source<<" "<< (res-cu) <<endl;
    res%=mod;
  }
  seen[curr]=true;
  for(int c:g[curr]){
    if(seen[c])continue;
    dfs2(res,source,c,g,seen,desc,currpath);
  }
      
  currpath.pop_back();
}
ll dfs(int source, vector<vector<int>>& g){
  // determine how many are in each subtree at each depth
  // step one is determine descendants
  vector<int> desc(n,0);
  vector<bool> blank(n,false);
  dfs1(source,g,blank,desc);
  ll res = 0;
  blank.clear();
  blank.resize(n,false);
  vector<int> path;
  dfs2(res,source,source,g,blank,desc,path);
  return res;
}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>n;
  
  for(int i=0;i<n;++i){
    edgedp[i][0]=1;
    edgedp[0][i]=0;
  }
  for(int i=1;i<=200;++i){
    for(int j=1;j<=200;++j){
      edgedp[i][j]=((edgedp[i][j-1]+edgedp[i-1][j])*((mod+1)/2))%mod;
      //cout<<i<<" "<<j<<" "<<edgedp[i][j]<<endl;
    }
  }
  vector<vector<int>> g(n);
  for(int i=0;i<n-1;++i){
    int a,b;
    cin>>a>>b;
    --a;
    --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  ll res = 0;
  for(int i=0;i<n;++i){
    // dfs from i
    res += dfs(i,g);
  }
  res%=mod;
  /*  for(int i=2;i<=200;++i){
    cout<<modinv<ll>(i,mod)<<endl;
    }*/
  cout<<(res * modinv<ll>(n,mod))%mod<<endl;
}