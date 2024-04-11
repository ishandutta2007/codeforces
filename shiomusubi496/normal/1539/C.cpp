#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int n,k,x; cin>>n>>k>>x;
  vector<int> a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  sort(a.begin(),a.end());
  a.erase(unique(a.begin(),a.end()),a.end());
  if(x==0)return cout<<a.size()<<endl,0;
  vector<int> b(a.size()-1);
  for(int i=0;i<a.size()-1;i++)b[i]=a[i+1]-a[i];
  sort(b.begin(),b.end());
  int ans=a.size();
  for(int i:b){
    k-=(i-1)/x;
    if(k>=0)ans--;
  }
  cout<<ans<<endl;
}