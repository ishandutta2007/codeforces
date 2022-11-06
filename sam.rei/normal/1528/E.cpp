#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 998244353;
ll t[1000001];
// number with at most this height 
ll np3c3(ll n){
  //cout<<n<<endl;
  return ((((((n+3)*(n+2))%M)*(n+1))%M)*166374059)%M;
}
ll exactwithtwo(ll n){
  return (t[n]-t[n-1]-t[n-1]+(n>1?t[n-2]:0))%M;
}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  // t[i] is number of rooted downward trees of depth at most i with outdegree 2 max
  t[0]=1;
  for(int i=0;i<n;++i){
    // each child is size at most one less, or can have nothing
    t[i+1]= (((t[i]+1)*(t[i]+2))/2)%M;
  }
  ll res=5;
  // t[n-1]+3 choose 3
  if(n>=2){
    //   rooted tree with at most 3 elements 
    res=(2*(np3c3(t[n-1])-np3c3(t[n-2]))-1+M*3)%M;
    for(int i=1;i<=n-2;++i){
      //cout<<res<<endl;
      //height n-i-1 tree up top
      res+=(exactwithtwo(n-i-1)*(t[i]-t[i-1]-1))%M;
      res%=M;
    }
  }
  cout<<(res+M)%M<<flush;
}