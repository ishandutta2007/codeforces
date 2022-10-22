#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
  int n; cin>>n;
  vector<int>A(n);
  for(int i=0;i<n;i++) cin>>A[i];
  for(int i=0;i<n-1;i++) if(A[i]>A[i+1])goto home;
  puts("0"); return;
  home:;
  puts(A.front()==1||A.back()==n?"1":A.front()==n&&A.back()==1?"3":"2");
}
signed main(){
  int Q; cin>>Q;
  while(Q--)solve();
}