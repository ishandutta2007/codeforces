#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
void one(){
  int h,w;
  cin>>h>>w;
  vector<vector<char>> res(h,vector<char>(w,'0'));

  for(int i=0;i<h;i+=2){
    res[i][0]='1';
  }
  for(int i=0;i<w;i+=2){
    res[0][i]='1';
  }
  for(int i=h-1;i>1;i-=2){
    res[i][w-1]='1';
  }
  for(int i=w-1;i>1;i-=2){
    res[h-1][i]='1';
  }
  
  for(int j=0;j<h;++j){
    for(int i=0;i<w;++i){
      cout<<res[j][i];
    }
    cout<<'\n';
  }
}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC;
  cin>>TC;
  while(TC-->0){
    one();
  }
  cout<<flush;
}