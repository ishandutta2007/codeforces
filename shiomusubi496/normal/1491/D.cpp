#include<bits/stdc++.h>
#define int long long
using namespace std;
int u,v;
void solve(){
  vector<int>s,t;
  for(int i=30;i--;)if((u>>i)&1)s.push_back(i);
  for(int i=30;i--;)if((v>>i)&1)t.push_back(i);
  if(u>v||s.size()<t.size()){
    puts("NO");
    return;
  }
  bool ok=0,r=0;
  for(int i=0,j=0;;){
    if(i==t.size()||t[i]<s[j]){
      if(ok)j++;
      else if(!r){
        puts("NO");
        return;
      }else j++,ok=1;
    }else{
      if(t[i]==s[j])ok=0;
      else r=ok=1;
      i++,j++;
    }
    if(j==s.size()){
      if(i==t.size())break;
      else{
        puts("NO");
        return;
      }
    }
  }
  puts("YES");
}
signed main(){
  int t;cin>>t;
  while(t--){
    cin>>u>>v;
    solve();
  }
}