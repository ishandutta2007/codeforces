#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
void one(){
  int n;
  cin>>n;
  int tot=0;
  for(int i=0;i<n;++i){
    int k;
    cin>>k;
    tot+=k;
  }
  cout<< max(tot-n,min(n-tot,1))<<"\n";
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