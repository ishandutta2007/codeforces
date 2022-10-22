#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int n; cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  multiset<int> b;
  for(int i=0;i<n;i++){
    int a; cin>>a;
    b.insert(a);
  }
  for(int i=0;i<n;i++){
    auto itr=b.lower_bound(n-a[i]);
    if(itr==b.end())itr=b.begin();
    a[i]=(a[i]+*itr)%n;
    b.erase(itr);
  }
  for(int i=0;i<n;i++)cout<<a[i]<<" \n"[i==n-1];
}