#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool one(){
  int N;
  cin>>N;
  set<int> achievable;
  achievable.insert(0);
  vector<int> A(N);
  for(int j=0;j<N;++j){
    cin>>A[j];
  }
  for(int j= 0 ;j<N;++j){
    if(achievable.count(A[j])>0)return true;
    set<int> next(achievable.begin(),achievable.end());
    for(int z : achievable){
      next.insert(z+A[j]);
      next.insert(z-A[j]);
    }
    achievable = next;
    // can either add or subtract it to get a different b
  }
  return false;
}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC;
  cin>>TC;
  while(TC-->0){
    cout<< (one()?"YES":"NO")<<"\n";
  }
  cout<<flush;
}