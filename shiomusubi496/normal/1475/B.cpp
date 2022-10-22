#include<bits/stdc++.h>
#define int long long
using namespace std;
bool ok[2000000];
signed main(){
  fill(ok,ok+2000000,0);
  ok[0]=1;
  for(int i=0;i<=1000000;i++){
    ok[i+2020]|=ok[i];
    ok[i+2021]|=ok[i];
  }
  int t;cin>>t;
  while(t--){
    int a;cin>>a;
    puts(ok[a]?"YES":"NO");
  }
}