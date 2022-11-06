#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
void one(){
  ll n,x,t;
  cin>>n>>x>>t;
  ll maxval = t/x;
  ll wean = min(maxval,n);
  ll res = wean*n- (wean*(wean+1))/2;
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