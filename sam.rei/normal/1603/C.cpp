#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define RANGE(x) x.begin(),x.end()
const ll MOD = 998244353;
int mad(int a, int b){
  int c = a+b;
  return c>=MOD?c-MOD:c;
}
ll one(){
  int N;
  cin>>N;
  vi a(N);
  for(int i=0;i<N;++i){
    //    a[i] = N-i;
     cin>>a[i];
  }
    // a[i] <=10^5
  // do this backwards
  // sequence is dictated by leftmost.
  // value at i forces i+1 to split into k parts if i>j
  // keep list of numbers, parts forced to split into
  // value i split into k parts will have a consistent value
  
  // i is split into k parts if there's one to the rightt split into enough to force it to
  //
  // track number of splits,
  ll res = 0;
  // leftmost is split never, is involved in n different subarrays
  // store in increasing order the number of counts
  vector<pair<int,int>> counts;
  counts.emplace_back(a[N-1],1);
  // add 0 to res because this one is never split
  
  for( int j = N-2;j>=0;--j){
    // keep track of sum of num splits
    // num different split values is bounded by sqrt(n)
    ll subtot = 0;
    vector<pii> out_counts;
    bool added_free = false;
    int maxsofar = 0;
    for( auto& p: counts){
      // check if new val differs
      // must split into at least  ceil(a[j]/old)
      int ns = (a[j] + p.first -1) /p.first;
      // 5, 2 -> split into 3 -> 1 is the smallest value
      int new_val = a[j]/ns;
      //cerr<<j<<" "<<ns<<" "<<p.second<<" "<<new_val<<endl;
      subtot += (ns-1)*(ll)p.second%MOD;
      if(new_val > maxsofar){
        out_counts.emplace_back(new_val,0);
        maxsofar = new_val;
      }
      //auto it = out_counts.emplace(new_val,0).first;
      out_counts.back().second = mad(p.second,out_counts.back().second);
      // add ns-1
      //cerr<<j<<" "<<new_val<<" "<<out_counts[new_val]<<endl;
    }
    //    cerr<<counts.size()<<endl;
    //    cerr<<j<<" "<<subtot<<endl;
    res += ((subtot% MOD ) * (j+1))%MOD;
    if( maxsofar < a[j])
      out_counts.emplace_back(a[j],0);
    ++out_counts.back().second;
    counts = out_counts;
  }
  return res%MOD;
}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC;
  cin>>TC;
  while(TC-->0){
    cout<< one()<<'\n';
  }
  cout<<flush;
}