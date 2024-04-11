#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve_sub(int m,vector<int>&ans,vector<tuple<int,char,int>>&X){
  sort(X.begin(),X.end());
  int l=X.size();
  vector<tuple<int,char,int>> A;
  for(int i=0;i<l;i++){
    if(A.size() && get<1>(A.back())=='R' && get<1>(X[i])=='L'){
      ans[get<2>(A.back())]=ans[get<2>(X[i])]=(get<0>(X[i])-get<0>(A.back()))/2;
      A.pop_back();
    }
    else A.push_back(X[i]);
  }
  l=A.size();
  vector<tuple<int,char,int>> B;
  for(int i=0;i+1<l;i+=2){
    if(get<1>(A[i])=='L' && get<1>(A[i+1])=='L'){
      ans[get<2>(A[i])]=ans[get<2>(A[i+1])]=(get<0>(A[i])+get<0>(A[i+1]))/2;
    }else if(get<1>(A[i])=='L') B.push_back(A[i]);
  }
  reverse(A.begin(),A.end());
  for(int i=0;i+1<l;i+=2){
    if(get<1>(A[i])=='R' && get<1>(A[i+1])=='R'){
      ans[get<2>(A[i])]=ans[get<2>(A[i+1])]=(2*m-get<0>(A[i])-get<0>(A[i+1]))/2;
    }else if(get<1>(A[i])=='R') B.push_back(A[i]);
  }
  if(B.size()==2){
    ans[get<2>(B[0])]=ans[get<2>(B[1])]=(2*m+get<0>(B[0])-get<0>(B[1]))/2;
  }
}
void solve(){
  int n,m; cin>>n>>m;
  vector<tuple<int,char,int>> X,Y;
  {
    vector<int>A(n);
    for(int i=0;i<n;i++) cin>>A[i];
    vector<char>B(n);
    for(int i=0;i<n;i++) cin>>B[i];
    for(int i=0;i<n;i++){
      if(A[i]%2==0) X.push_back({A[i],B[i],i});
      else Y.push_back({A[i],B[i],i});
    }
  }
  vector<int>ans(n,-1);
  solve_sub(m,ans,X);
  solve_sub(m,ans,Y);
  for(int i=0;i<n;i++) cout<<ans[i]<<" \n"[i==n-1];
}
signed main(){
  int Q; cin>>Q;
  while(Q--)solve();
}