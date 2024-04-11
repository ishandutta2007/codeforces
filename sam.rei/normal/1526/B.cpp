#include <bits/stdc++.h>
using namespace std;
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC;
  cin>>TC;
  
  while(TC-->0){
    int x;
    cin>>x;
    if(x>10000){
      cout<<"YES\n";
      continue;
    }
    if(x>= 111*(x%11)){
      cout<<"YES\n";
    }else
      cout<<"NO\n";
  }
  cout<<flush;
}