#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int t;cin>>t;
  while(t--){
    int a;cin>>a;
    while(a%2==0)a/=2;
    if(a==1)puts("NO");
    else puts("YES");
  }
}