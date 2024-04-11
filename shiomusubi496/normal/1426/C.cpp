#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int Q;
  cin>>Q;
  while(Q--){
    int n;
    cin>>n;
    int m=sqrt(n),ans=1000000000;
    for(int i=max(m-2,1LL);i<=min(m+2,n);i++)ans=min(ans,i-1+(n-1)/i);
    cout<<ans<<endl;
  }
}