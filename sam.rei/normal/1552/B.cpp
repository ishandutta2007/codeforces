#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isless(vector<int>& a, vector<int>&b){
  int res = 0;
  for(int i=0;i<5;++i) if(a[i]<=b[i])++res;
  return res>=3;
}
int one(){
  int N;
  cin>>N;
  vector<vector<int>> perf(N,vector<int>(5));
  for(int i=0;i<N;++i){
    for(int j=0;j<5;++j)cin>>perf[i][j];
  }
  int currbest = 0;
  for(int i=1;i<N;++i){
    if(!isless(perf[currbest],perf[i])){
      currbest = i;
    }
  }
  
  for(int i=0;i<N;++i){
    if(!isless(perf[currbest],perf[i])){
      return -1;
    }
  }
  return 1+currbest;
  
}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC;
  cin>>TC;
  while(TC-->0){
    cout<<one()<<"\n";
  }
  cout<<flush;
}