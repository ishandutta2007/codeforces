#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int n,q; cin>>n>>q;
  string s; cin>>s;
  vector<int> R(n+1);
  for(int i=0;i<n;i++){
    R[i+1]=R[i]+(s[i]-96);
  }
  while(q--){
    int l,r; cin>>l>>r;
    cout<<R[r]-R[l-1]<<endl;
  }
}