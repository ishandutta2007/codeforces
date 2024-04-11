#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
void one(){
  int n,l,r;
  cin>>n>>l>>r;
  vector<int> vec(n);
  for(int i=0;i<n;++i){
    cin>>vec[i];
  }
  sort(RANGE(vec));
  //cerr<<"sorted"<<endl;
  //least such that greater
  int lindex=n-1;
  //greatest such that still less
  int rindex=n-1;
  ll res=0;
  for(int curr=0;curr<n;++curr){
    while(rindex>=0 && vec[rindex]+vec[curr]>r){
      --rindex;
    }
    while(lindex>=0 && vec[lindex]+vec[curr]>=l){
      --lindex;
    }
    res+=max(0,rindex-max(lindex,curr));
  }
  cout<<res<<"\n";
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