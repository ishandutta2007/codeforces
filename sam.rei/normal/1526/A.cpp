#include <bits/stdc++.h>
using namespace std;
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC;
  cin>>TC;
  while(TC-->0){
    int n;
    cin>>n;
    vector<int> vals(2*n);
    for(int i=0;i<2*n;++i){
      cin>>vals[i];
    }
    sort(vals.begin(),vals.end());
    
    for(int i=0;i<n;++i){
      cout<<vals[i]<<" "<<vals[i+n];
      if(i!=n)cout<<" ";
    }
    cout<<"\n";
  }
  cout<<flush;
}