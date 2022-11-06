#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
void one(){
  int n;
  cin>>n;
  vector<int> vec(n);
  for(int i=0;i<n;++i){
    cin>>vec[i];
  }
  sort(RANGE(vec));
  int mind=2000000006;
  int minp=-1;
  for(int i=1;i<n;++i){
    int d = vec[i]-vec[i-1];
    if(d<=mind){
      minp=i;
      mind=d;
    }
  }
  if(n==2){
    cout<<vec[0]<<" "<<vec[1]<<"\n";
    return;
  }
  for(int j=minp;j<n;++j){
    cout<<vec[j]<<" ";
  }
  for(int i=0;i<minp;++i){
    cout<<vec[i];
    if(i!=minp-1){
      cout<<" ";
    }
    else {
      cout<<"\n";
    }
  }
  
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