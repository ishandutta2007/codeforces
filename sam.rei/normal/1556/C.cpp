#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cin>>N;
  vector<ll> C(N);
  for(int i=0;i<N;++i)cin>>C[i];
  //maintain depth at start/end of each segment
  vector<ll> d(N+1);//d[i] is depth before start of segment i
  d[0]=0;
  for(int i=0;i<N;++i){
    d[i+1] = d[i] +  (i%2==1?-C[i]:C[i]);
  }
  uint64_t res=0;
  
  // for pairs i,j, determine minimum needed for leftmost to be in i, rightmost to be in j

  for(int i=0;i<N;i+=2){
    ll md = 0;
    for(int j=i+1;j<N;j+=2){
      ll reqdiff = d[i+1]-d[j];
      ll minleft = -min(-reqdiff,md);
      // left>= minleft so no free right parens
      // left + d[j]-d[i+1] - right = 0
      // left = right - reqdiff
      ll maxleft = min(C[i], C[j]+reqdiff);
      // if 0,0 is an option take away one
      if(maxleft>=minleft){
        ll ways = maxleft-minleft+1;
        if(reqdiff == 0 && minleft== 0){
          --ways;
        }
        //cout<<i<<" "<<j<<" "<<maxleft<<" "<<minleft<<" "<<ways<<" "<<md<<endl;
        res += ways;
      
      }
      
      md = min(md,d[j+1]-d[i+1]);
    }
  }
  // depth after going i,j
  cout<<res<<flush;
}