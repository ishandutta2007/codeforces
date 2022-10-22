#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int n; string s; cin>>n>>s;
  char f[10];
  for(int i=1;i<10;i++)cin>>f[i];
  for(int i=0;i<n;i++){
    if(s[i]<f[s[i]-48]){
      for(int j=i;j<n && s[j]<=f[s[j]-48];j++)s[j]=f[s[j]-48];
      break;
    }
  }
  cout<<s<<endl;
}