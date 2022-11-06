#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define RANGE(x) x.begin(),x.end()
void one(){
  int N;
  cin>>N;
  vi A(N);
  vi B(N);
  for(int i=0;i<N;++i)cin>>A[i]>>B[i];
  
  //game state p is max number of richer we can have given we have k poorer
  // B,A
  // for all k<=A+1

  // say h(k) = maximum to left that allows k to right
  // H, same as h, but (k)->(at least k)
  // encounter B(efore), A(fter)
  // This is first 
  // h(A) = max(1,H(A))
  // for a<A, h(a) = max(B+1,h(a)

  int lo = 0;
  int hi = N+1;
  while(hi-lo>1){
    // always doable with lo
    int test = (hi+lo)/2;
    int curr = 0;
    for(int i=0;i<N;++i){
      if(A[i]>=test-1-curr &&B[i]>=curr)++curr; 
    }
    if(curr>=test){
      lo=test;
    }
    else{
      hi=test;
    }
  }
  cout<<lo<<'\n';
}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC;
  cin>>TC;
  while(TC-->0){
    one();
  }
  cout<<flush;
}