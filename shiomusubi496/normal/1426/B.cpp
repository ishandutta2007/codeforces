#include<bits/stdc++.h>
using namespace std;
int main(){
  int Q;
  cin>>Q;
  while(Q--){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> A(n,vector<int>(4));
    bool ok=false;
    for(int i=0;i<n;i++){
      cin>>A[i][0]>>A[i][1]>>A[i][2]>>A[i][3];
      ok=ok||(A[i][1]==A[i][2]);
    }
    if(!ok || m%2)puts("NO");
    else if(m==2)puts("YES");
    else{
      ok=false;
      sort(A.begin(),A.end());
      for(int i=0;i<n;i++)
        ok=ok||binary_search(A.begin(),A.end(),vector<int>{A[i][0],A[i][2],A[i][1],A[i][3]});
      cout<<(ok?"YES":"NO")<<'\n';
    }
  }
}