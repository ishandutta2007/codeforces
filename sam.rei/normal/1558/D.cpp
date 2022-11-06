#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
ll mod = 998244353;
ll fact[500001];
ll factinv[500001];
int maxF = 500000;
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
void precomp(){
  fact[0]=factinv[0]=1;
  for(int i=1;i<=maxF;++i){
    fact[i] = (i*fact[i-1])%mod;
    factinv[i] = modinv(fact[i],mod);
  }
}
//cp-algs fenwick
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
  int fin(int i){
    //find least t such that t-sum(t) = i;
    int l = -1;
    int r = n-1;
    while(r-l>1){
      int t =  (r+l)/2;
      if( t-sum(t)>=i){
        r=t;
      }else l=t;
    }
    return r;
  }
};
FenwickTree ft(200005);
void one(){
  // answer is (2*N-1 choose N-1-M)... not really
  // looks like it could be, but
  // 3 2
  // 2 1 
  // 3 2 breaks it
  // each operation
  // creates some < values in the end result
  // anything else is free reign
  // process is fully reversible
  // x_i,y_i forces that after x_i, y_i<y_{i+1}
  // some value K <= M is such that N+N-M-1 choose N-1
  int N,M;
  cin>>N>>M;
  vector<pair<int,int>> vals(M);
  for(int i=0;i<M;++i){
    cin>>vals[i].first>>vals[i].second;
  }

  vector<bool> diff(N+1,false);
  int tot=0;
  vector<int> additions;
  for(int i=M-1;i>=0;--i){
    int y = vals[i].second;
    //int x = vals[i].first;
    // number of future values inserted here or later
    // actual final position of y+1
    // see how many positions <= y are taken
    // least t such that sum(t)+y>=t;
    int ep = ft.fin(y+1);
    //cout<<y<<" "<<ft.fin(y+1)<<" "<<ft.fin(y)<<endl;
    if(!diff[ep]){++tot;diff[ep]=true;}
    int p = ft.fin(y);
    additions.push_back(p);
    ft.add(p,1);
  }
  for(int x:additions)ft.add(x,-1);
  ll res = fact[2*N-tot-1] * factinv[N] % mod * factinv[N-1-tot] % mod;
  cout<<res<<'\n';
}
int main(){
  precomp();
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC;
  cin>>TC;
  while(TC-->0){
    one();
  }
  cout<<flush;
}