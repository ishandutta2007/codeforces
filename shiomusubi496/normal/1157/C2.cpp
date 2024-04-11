#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int n; cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  string ans="";
  for(int l=0,r=n-1;l<=r;){
    if((l!=0 && a[l-1]>=a[l]) && (r!=n-1 && a[r+1]>=a[r]))break;
    else if(l!=0 && a[l-1]>=a[l])ans+="R",r--;
    else if(r!=n-1 && a[r+1]>=a[r])ans+="L",l++;
    else if(a[l]==a[r]){
      string x="",y="";
      for(int i=l;i<=r && (i==0 || a[i-1]<a[i]);i++)x+="L";
      for(int i=r;i>=l && (i==n-1 || a[i+1]<a[i]);i--)y+="R";
      if(x.size()<y.size())ans+=y;
      else ans+=x;
      break;
    }
    else if(a[l]>a[r])ans+="R",r--;
    else ans+="L",l++;
  }
  cout<<ans.size()<<endl;
  cout<<ans<<endl;
}