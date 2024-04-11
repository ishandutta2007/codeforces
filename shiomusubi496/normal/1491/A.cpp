#include<bits/stdc++.h>
#define int long long
using namespace std;
int N,Q,A[1<<20],a,b;
signed main(){
  cin>>N>>Q;
  for(int i=0;i<N;i++){
    cin>>A[i];
    if(A[i])a++;
    else b++;
  }
  while(Q--){
    int t;cin>>t;
    if(t==1){
      int k;cin>>k;k--;
      if(A[k])a--,b++;
      else b--,a++;
      A[k]^=1;
    }else{
      int k;cin>>k;
      if(a>=k)cout<<1<<endl;
      else cout<<0<<endl;
    }
  }
}