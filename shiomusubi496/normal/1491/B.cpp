#include<bits/stdc++.h>
#define int long long
using namespace std;
int N,U,V,A[110];
void solve(){
  set<int>st;
  for(int i=0;i<N;i++)st.insert(A[i]);
  if(st.size()==1)cout<<min(U,V)+V<<endl;
  else{
    for(int i=0;i<N-1;i++)if(abs(A[i]-A[i+1])>1)goto home;
    cout<<min(U,V)<<endl;
    return;
    home:;
    cout<<0<<endl;
  }
}
signed main(){
  int t;cin>>t;
  while(t--){
    cin>>N>>U>>V;
    for(int i=0;i<N;i++)cin>>A[i];
    solve();
  }
}