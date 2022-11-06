#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
void one(){
  
  int n;
  cin>>n;
  vector<ll> v(n+2);
  v[0]=0;
  v[n+1]=0;
  for(int i=1;i<=n;++i)cin>>v[i];
  ll res=0;
  for(int i=1;i<=n;++i){
    //left border + right border
    if(v[i]>v[i-1])res+= v[i]-v[i-1];
    if(v[i]>v[i+1])res+= v[i]-v[i+1];
    if(v[i]>v[i+1] && v[i]>v[i-1])res-= v[i]-max(v[i+1],v[i-1]);
    //cout<<i<<" "<<res<<endl;
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