#include<bits/stdc++.h>
#define int long long
using namespace std;
int gcd(int a,int b){
  if(!b)return a;
  return gcd(b,a%b);
}
int n,m,a[1<<20];
signed main(){
  cin>>n>>m;
  for(int i=0;i<n;i++)cin>>a[i];
  int g=0;
  for(int i=0;i<n-1;i++)g=gcd(g,abs(a[i+1]-a[i]));
  while(m--){
    int k;cin>>k;
    cout<<gcd(g,a[0]+k)<<endl;
  }
}