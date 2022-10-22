#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int Q;cin>>Q;
  while(Q--){
    int n;cin>>n;
    vector<bool>use(2*n,false);
    vector<int>b(n);
    for(int i=0;i<n;i++){
      cin>>b[i];
      use[--b[i]]=true;
    }
    int p,q;
    for(int i=0,r=0;i<n;i++){
      r=max(r+1,b[i]);
      while(r<2*n&&use[r])r++;
      if(r>=2*n){
        p=i;
        break;
      }
      if(i==n-1)p=n;
    }
    for(int i=n-1,l=2*n-1;i>=0;i--){
      l=min(l-1,b[i]);
      while(l>=0&&use[l])l--;
      if(l<=-1){
        q=i+1;
        break;
      }
      if(i==0)q=0;
    }
    cout<<p-q+1<<endl;
  }
}