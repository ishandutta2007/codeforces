#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
void one(){
  int n;
  cin>>n;
  vector<ll> vals(n);
  //ll tot = 0;
  ll ma = -1;
  for(int i=0;i<n;++i){
    cin>>vals[i];
    ma = max(ma,vals[i]);
  }
  sort(RANGE(vals));
  ll tot=0;
  ll res=ma;
  for(int i=0;i<n;++i){
    res += tot-vals[i]*i;
    tot+=vals[i];
  }
  cout<<res<<"\n";
  //  cout<<res<<"\n";
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