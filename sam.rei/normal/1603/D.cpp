#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define RANGE(x) x.begin(),x.end()
const ll LINF = 999999999999999999ll;

const int MAX_K = 17;
const int MAX_N = 100000;
ll res[MAX_K+1][MAX_N+1];

struct segval {
  ll wi;
  ll wo;
  segval operator+(const segval& o) const {
    return segval{min(o.wi, o.wo+wi),o.wo+wo};
  }
};
  
struct segtree{
  vector<segval> t;
  segtree(int k): t((MAX_N+1)*4){
    build(res[k-1],1,0,MAX_N);
  }
  void build(ll a[], int v, int tl, int tr) {
    if (tl == tr) {
      t[v] = segval{a[tl],0};
    } else {
      int tm = (tl + tr) / 2;
      build(a, v*2, tl, tm);
      build(a, v*2+1, tm+1, tr);
      t[v] = t[v*2] + t[v*2+1];
    }
  }
  segval sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
      return segval{LINF,0};
    if (l == tl && r == tr) {
      return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
      + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
  } 
  void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
      t[v].wo += new_val;
    } else {
      int tm = (tl + tr) / 2;
      if (pos <= tm)
        update(v*2, tl, tm, pos, new_val);
      else
        update(v*2+1, tm+1, tr, pos, new_val);
      t[v] = t[v*2] + t[v*2+1];
    }
  }
};
ll one(){
  int N,K;
  cin>>N>>K;
  if(K>MAX_K)K=MAX_K;
  return N+res[K][N];
}
vector<vector<int>> divisors(MAX_N+1,vector<int>(0));
int phi[MAX_N+1];
//cp-algs
void phi_1_to_n() {
  // vector<int> phi(n + 1);
  int n = MAX_N;
  phi[0] = 0;
  phi[1] = 1;
  for (int i = 2; i <= n; i++)
    phi[i] = i;
  
  for (int i = 2; i <= n; i++) {
    if (phi[i] == i) {
      for (int j = i; j <= n; j += i)
        phi[j] -= phi[j] / i;
    }
  }
}

void precomp1(){
  phi_1_to_n();
  // track max L/gcd props to the left
  divisors.clear();
  divisors.resize(MAX_N,vector<int>(0));
  for(int d=MAX_N;d>=1;--d){
    for(int j=2*d; j<=MAX_N;j+=d){
      divisors[j].push_back(d);
    }
  }
  //for(int j=0;j<=MAX_K;++j)
  for(int i=0;i<=MAX_N;++i)
    res[0][i] = LINF;
  //for(int k=0;k<=MAX_K;++k)res[k][0] = 0;
  res[0][0] = 0;
  // figure out how to compute this reasonably
  // push-forward dp, compute values based on L?
  // C(l,r ) is convex in l, convex in r
  // dp is nondecreasing
  // dp [N] is either not split or goes to at most N/2;
  // can find the correct value to jump to?
  // go by decreasing L?
  //
  // l, 2l-1 as a grouping results in 0 as added
  // l, 2l -> 1
  // l, 2l +k -> k/2 + 1 (For k<l)
  // if bounds goes to 3, get some more
  // sliding window of l,r to add along
  for(int k=1;k<=MAX_K;++k){
    int l =1;
    // see if moving l over is worth it
    ll segcost = 0;
    vector<ll> gcd_counts(MAX_N+1,0);
    // make segtree for min
    // value at i can either replace all to left with one lower, or just add to sum
    // suffix + special
    // suffix + special is fixed on right
    segtree st(k);
    
    for(int r=1;r<=MAX_N;++r){
      // add in the segcost at r
      // how many r has in range
      // iterate over divisors of r that are at least l
      
      for(int d : divisors[r]){
        // keep track of how many to change for each
        // add to the counts
        // d divides 
        st.update(1,0,MAX_N,d,phi[r/d]);
      }
      auto aaa = st.sum(1,0,MAX_N,0,r);
      ll newv = aaa.wi;
      //if(res[k][r]!=newv){
      //  cout<<"ERR AT "<<k<<" "<<r<<" "<<res[k][r]<<" "<<newv<<endl;
      //}
      res[k][r] = newv;
    }
  }
}


void precomp(){
  phi_1_to_n();
  // track max L/gcd props to the left
  divisors.clear();
  divisors.resize(MAX_N+1,vector<int>(0));
  
  for(int d=MAX_N;d>=1;--d){
    for(int j=2*d; j<=MAX_N;j+=d){
      divisors[j].push_back(d);
    }
  }
  //for(int j=0;j<=MAX_K;++j)
  for(int i=0;i<=MAX_N;++i)
    res[0][i] = 999999999999999999ll;
  for(int k=0;k<=MAX_K;++k)res[k][0] = 0;
  // figure out how to compute this reasonably
  // push-forward dp, compute values based on L?
  // C(l,r ) is convex in l, convex in r
  // dp is nondecreasing
  // dp [N] is either not split or goes to at most N/2;
  // can find the correct value to jump to?
  // go by decreasing L?
  //
  // l, 2l-1 as a grouping results in 0 as added
  // l, 2l -> 1
  // l, 2l +k -> k/2 + 1 (For k<l)
  // if bounds goes to 3, get some more
  // sliding window of l,r to add along
  for(int k=1;k<=MAX_K;++k){
    int l =1;
    // see if moving l over is worth it
    ll segcost = 0;
    vector<ll> gcd_counts(MAX_N+1,0);
    for(int r=1;r<=MAX_N;++r){
      // add in the segcost at r
      // how many r has in range
      // iterate over divisors of r that are at least l
      for(int d_ind = 0; d_ind<divisors[r].size() && divisors[r][d_ind]>=l;++d_ind){
        int d = divisors[r][d_ind];
        if(d<l){
          cerr<<"MESSED UP A CONDITION"<<endl;
          break;
        }
        // keep track of how many to change for each
        // add to the counts
        // d divides r
        //
        int num_free=  phi[r/d];
        gcd_counts[d]+= num_free;
        segcost += num_free;
      }
      // add gcd
      
      // see while moving l up is worth it
      // add segcost to both 
      while(res[k-1][l]-gcd_counts[l]<= res[k-1][l-1]&& l<r){
        segcost-= gcd_counts[l];
        ++l;
      }
      //      cerr<<l<<" "<<r<<" "<<endl
      ll newv = res[k-1][l-1]+segcost;
      if(newv!=res[k][r]){
        cerr<<k<<" "<<r<<" "<<newv<<" "<<res[k][r]<<endl;
      }
      res[k][r] = newv;
      
    }
  }
}

int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  precomp1();
  //  precomp();
  int TC;
  cin>>TC;
  while(TC-->0){
    cout<<one()<<'\n';
  }
  cout<<flush;
}