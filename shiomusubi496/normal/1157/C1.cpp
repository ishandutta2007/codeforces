#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int n; cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  int l=1,r=n-2;
  for(;l<n;l++){
    if(a[l-1]>a[l])break;
  }
  for(;r>=0;r--){
    if(a[r+1]>a[r])break;
  }
  if(l-1==r+1)l--;
  cout<<l+(n-r-1)<<endl;
  for(int i=0,j=n-1;i<l || r<j;){
    if(i==l)cout<<"R",j--;
    else if(j==r)cout<<"L",i++;
    else if(a[i]>a[j])cout<<"R",j--;
    else cout<<"L",i++;
  }
  cout<<endl;
}