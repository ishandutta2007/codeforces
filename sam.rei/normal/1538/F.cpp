#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC;
  cin>>TC;
  while(TC-->0){
    int l,r;
    cin>>l>>r;
    int res = 0;
    while(l!=r){
      res+= r-l;
      l/=10;
      r/=10;
    }
    cout<<res<<"\n";
  }
  cout<<flush;
}