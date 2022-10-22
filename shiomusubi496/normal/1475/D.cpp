#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1e18;
signed main(){
  int t;cin>>t;
  while(t--){
    int n,s;cin>>n>>s;
    vector<int>X(n),Y(n),A,B;
    for(int i=0;i<n;i++)cin>>X[i];
    for(int i=0;i<n;i++){
      cin>>Y[i];
      if(Y[i]==1)A.push_back(X[i]);
      else B.push_back(X[i]);
    }
    sort(A.rbegin(),A.rend());sort(B.rbegin(),B.rend());
    A.insert(A.begin(),0),B.insert(B.begin(),0);
    for(int i=0;i+1<A.size();i++)A[i+1]+=A[i];
    for(int i=0;i+1<B.size();i++)B[i+1]+=B[i];
    int mn=INF;
    for(int i=0;i<A.size();i++){
      int it=lower_bound(B.begin(),B.end(),s-A[i])-B.begin();
      if(it<B.size())mn=min(mn,i+2*it);
    }
    cout<<(mn==INF?-1:mn)<<endl;
  }
}