#include<bits/stdc++.h>
#define int long long
using namespace std;
bool ok[1<<20];
signed main(){
  fill(ok,ok+21001,1);
  ok[0]=ok[1]=0;
  for(int i=2;i*i<=21000;i++){
    if(!ok[i])continue;
    for(int j=2;i*j<=21000;j++)ok[i*j]=0;
  }
  int t;cin>>t;
  while(t--){
    int d;cin>>d;
    int k=1+d;
    while(!ok[k])k++;
    int a=k;
    k+=d;
    while(!ok[k])k++;
    cout<<a*k<<endl;
  }
}