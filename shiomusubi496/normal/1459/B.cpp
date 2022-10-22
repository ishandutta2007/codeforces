#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int n;cin>>n;
  if(n&1)cout<<(n/2+2)*(n/2+1)*2<<endl;
  else cout<<(n/2+1)*(n/2+1)<<endl;
}