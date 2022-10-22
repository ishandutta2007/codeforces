#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int Q;cin>>Q;
  while(Q--){
    int n,a=0,b=0;string s,t;cin>>n>>s>>t;
    for(int i=0;i<n;i++){
      if(s[i]>t[i])a++;
      if(s[i]<t[i])b++;
    }
    if(a==b)puts("EQUAL");
    else puts(a>b?"RED":"BLUE");
  }
}