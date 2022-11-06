#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
void one(){
  
}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N=100;
  vector<bool> wins(N,false);
  for(int i=1;i<N;++i){
    for(int j=2;j<i;++j){
      if(i%j==0 && !wins[i-j])
        wins[i]=true;;
    }
    //if(!wins[i])
    // cout<<i<<" "<<wins[i]<<endl;
  }
  int TC;
  cin>>TC;
  while(TC-->0){
    int n;
    cin>>n;
    if(n>=N){
      int pow2=0;
      while(n%2==0){
        n/=2;
        ++pow2;
      }
      if(n==1)cout<< (pow2%2?"Bob":"Alice");
      else cout<< (pow2==0? "Bob":"Alice");
    }
    else {
      cout<< (wins[n]?"Alice":"Bob");
    }
    cout<<"\n";
    //    one();
  }
  cout<<flush;
}