#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int t;cin>>t;
  while(t--){
    int n,k;cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    reverse(a.begin(),a.end());
    int need=0;
    for(int i=0;i<n-1;i++){
      int nn=(a[i]*100+k-1)/k;
      need=max(need-a[i],nn);
    }
    cout<<max(need-a[n-1],0ll)<<endl;
  }
}