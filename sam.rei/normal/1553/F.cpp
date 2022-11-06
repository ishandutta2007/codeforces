#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
//cp-algs fenwick tree
struct FenwickTree {
  vector<ll> bit;  // binary indexed tree
  vector<ll> base;
  int n;

  FenwickTree(int n) {
    this->n = n;
    bit.assign(n, 0);
    base.assign(n,0);
  }

  ll sum(int r) {
    ll ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
      ret += bit[r];
    return ret;
  }

  ll sum(int l, int r) {
    return sum(r) - sum(l - 1);
  }

  void add(int idx, ll delta) {
    base[idx]+=delta;
    for (; idx < n; idx = idx | (idx + 1))
      bit[idx] += delta;
  }
};
const int maxv = 300000;
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll N;
  cin>>N;
  vector<int> A(N);
  ll res = 0;
  for(int i=0;i<N;++i){
    //A[i] = maxv-i;
    cin>>A[i];
  }
  FenwickTree ft(maxv+1);
  FenwickTree ft2(maxv+1);
  ll currs = 0;
  for(int i=0;i<N;++i){
    int c = A[i];
    ft.add(c,1);
    ft2.add(c,c);
    currs+=c;
    res+=currs + (i+1ll)*c;
    // eliminate those that are larger
    // for each k, for a[i] >= k*c, subtract c
    for(int j=c;j<=maxv;j+=c){
      res-= (i+1-ft.sum(j-1))*(ll)c;
    }
    // eliminate all that are
    // cout<<res<<endl;
    int k = 1;
    for(;k*(k+1)<=c;++k){
      int width = c/k - c/(k+1);
      // sum of values that fit in exactly k times
      res-= ft2.sum(c/(k+1)+1,c/k) * k;
      //cout<<k<<" "<<ft2.sum(c/(k+1)+1,c/k)<<endl;
    }
    int d = c/k;
    for(int i=1;i<=d;++i){
      if(ft.base[i] == 1){
        res -= i* (c/i);
        //cout<<i<<" "<<res<<endl;;
      }
    }
    if(i>0)cout<<" ";
    cout<<res;
    //cout<<res<<endl;
  }
  cout<<endl;
}