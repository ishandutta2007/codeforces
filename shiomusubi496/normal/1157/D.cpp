#include<bits/stdc++.h>
#define int long long
using namespace std;
bool f(int a,int k,int n){
  int sum=0;
  for(int i=0;i<k;i++){
    sum+=a;
    a*=2;
    if(sum>=n)return true;
  }
  return false;
}
signed main(){
  int n,k; cin>>n>>k;
  vector<int> ans(k);
  if(k>=50)ans[0]=1;
  else{
    int sum=0;
    for(int i=0,j=1;i<k;i++,j*=2)sum+=j;
    ans[0]=(n+sum-1)/sum;
  }
  n-=ans[0];
  for(int i=1;i<k;i++){
    ans[i]=ans[i-1]+1;
    n-=ans[i];
  }
  if(n<0)return puts("NO"),0;
  int sum=0;
  for(int i=1;i<k;i++){
    ans[i]+=sum;
    int a=ans[i-1]*2-ans[i];
    if(a*(k-i)<n){
      n-=a*(k-i);
      sum+=a; ans[i]+=a;
      continue;
    }
    for(int j=i+1;j<k;j++)ans[j]+=sum;
    for(int j=i;j<k;j++)ans[j]+=n/(k-i);
    for(int j=0;j<n%(k-i);j++)ans[k-1-j]++;
    n=0;
    break;
  }
  puts("YES");
  for(int i=0;i<k;i++){
      if(i!=k-1)printf("%d ",ans[i]);
      else printf("%d\n",ans[i]);
  }
}