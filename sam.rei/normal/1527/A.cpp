#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC;
  cin>>TC;
  while(TC-->0){
    int n;
    cin>>n;
    int k=1;
    while(k*2<=n){
      k*=2;
    }
    cout<<k-1<<"\n";
  }
  cout<<flush;
}