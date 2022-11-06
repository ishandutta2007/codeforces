#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
void one(){
  int n;
  cin>>n;
  vector<int> vec(n);
  ll tot = 0;
  for(int i=0;i<n;++i){
    cin>>vec[i];
    tot += vec[i];
  }
  sort(RANGE(vec));
  if(tot%n!=0){
    cout<<"-1\n";
    return;
  }
  int k=0;
  while(vec[n-1-k]>tot/n)++k;
  cout<<k<<"\n";
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