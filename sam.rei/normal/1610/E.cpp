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
  vi vals(N);
  for(int i=0;i<N;++i){
    cin>>vals[i];
  }

  // say A is good
  // then, for all subarrays with 3 elements a,b,c:
  // mid<=avg
  // arrange a i in increasing
  // say a_1 is least element
  // a_k>=2a_{k-1}-a_1
  // can have a bunch at 0
  sort(RANGE(vals));
  int maxsize = 1;
  for(int i=0;i<N;++i){
    // pick a starting point
    int sta = vals[i];
    int c = 1;
    while(i+1<N && vals[i+1]==sta){
      ++c;++i;
    }
    if(i!=N-1){
      // keep going
      int curr = vals[i+1];
      ++c;
      // next value at least 2*curr-sta
      while(true){
        int targ = 2*curr-sta;
        auto pos = lower_bound(RANGE(vals),targ);
        if(pos!=vals.end()){
          ++c;
          curr = *pos;
          //  cerr<<c<<curr<<endl;
        }
        else break;
      }
    }
    maxsize = max(c,maxsize);
  }

  cout<<N-maxsize<<'\n';
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