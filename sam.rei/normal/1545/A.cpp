#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
bool one(){
  int N;
  cin>>N;
  vector<int> odds(100001,0);
  vector<int> evens(100001,0);
  for(int i=0;i<N;++i){
    int k;
    cin>>k;
    --k;
    if(i%2==0)++evens[k];
    else ++ odds[k];
  }
  int curr = 0;
  for(int k=0;k<=100000;++k){
    if(odds[k]>0 || evens[k]>0){
      //cout<<k<<" "<<odds[k]<<" "<<evens[k]<<" "<<curr<<endl;
      int last = curr+odds[k]+evens[k];
      if (evens[k] != (last+1)/2 - (curr+1)/2)return false;
      if (odds[k] !=  (last/2) - (curr)/2)return false;
      curr = last;
    }
  }
    return true;
}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC;
  cin>>TC;
  while(TC-->0){
    cout<<(one()?"YES\n":"NO\n");
  }
  cout<<flush;
}