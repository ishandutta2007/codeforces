#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
void one(){
  int n,m;
  cin>>n>>m;
  vector<pair<int,int>> seats(n*m);
  for(int i=0;i<n*m;++i){
    int k;
    cin>>k;
    seats[i] = make_pair(k,i);  
  }
  sort(RANGE(seats));
  int res = 0;
  for(int i=0;i<n;++i){
    for(int j=0;j<m;++j){
      for(int k=0;k<j;++k){
        if(seats[i*m+k].first!=seats[i*m+j].first && seats[i*m+k].second < seats[i*m+j].second)++res;
      }
    }
  }
  cout<<res<<'\n';
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