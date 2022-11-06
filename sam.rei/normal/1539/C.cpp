#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
void one(){
  
}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; ll k,x;
  cin>>n>>k>>x;
  vector<ll> t(n);
  for(int i=0;i<n;++i){
    cin>>t[i];
  }
  sort(RANGE(t));
  vector<ll> gaps;
  for(int i=1;i<n;++i){
    ll d = (t[i]-t[i-1]-1)/x;
    if(d>0)gaps.push_back(d);
  }
  sort(RANGE(gaps));
  int taken=0;
  for(;taken<gaps.size()&&gaps[taken]<=k;++taken){
    k-=gaps[taken];
   // cout<<gaps[taken]<<" "<<k<<endl;
  }
  cout<<gaps.size()-(taken-1)<<endl;
  cout<<flush;
}