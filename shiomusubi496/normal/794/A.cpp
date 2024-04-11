#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int a,b,c; cin>>a>>b>>c;
  int n; cin>>n;
  int ans=0;
  for(int i=0;i<n;i++){
    int d; cin>>d;
    if(b<d && d<c)ans++;
  }
  cout<<ans<<endl;
}