#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int Q;
    cin>>Q;
    while(Q--){
      int N,Q;
      cin>>N>>Q;
      int mx1=0,mx2=0;
      for(int i=0;i<N;i++){
        int a;
        cin>>a;
        mx2=max(mx2,mx1+a);
        mx1=max(mx1,mx2-a);
      }
      cout<<max(mx1,mx2)<<endl;
    }
}