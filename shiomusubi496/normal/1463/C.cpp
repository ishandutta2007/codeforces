#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int Q;cin>>Q;
  while(Q--){
    int n;cin>>n;
    vector<int>T(n+1),X(n);
    for(int i=0;i<n;i++)cin>>T[i]>>X[i];
    T[n]=1e18;
    int ans=0,now=0,go=0;
    for(int i=0;i<n;i++){
      int t=T[i+1]-T[i],x=X[i];
      if(now==go)go=x;
      if(now<go){
        if(now+t>=go){
          if(now<=x && x<=go)ans++;
          now=go;
        }else{
          if(now<=x && x<=now+t)ans++;
          now+=t;
        }
      }else if(now>go){
        if(now-t<=go){
          if(now>=x && x>=go)ans++;
          now=go;
        }else{
          if(now>=x && x>=now-t)ans++;
          now-=t;
        }
      }else ans++;
    }
    cout<<ans<<endl;
  }
}