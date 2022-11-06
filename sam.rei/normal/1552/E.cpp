#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<int,int>> solve(vector<pair<int,int>>& coloring, int K){
  // K repeats of K-1 colors
  vector<bool> taken(K-1);
  vector<pair<int,int>> result(K-1);
  vector<int> lastseen(K-1,-1);
  int lastmatch = -1;
  for(int i=0;i< coloring.size();++i){
    int c = coloring[i].first;
    if(taken[c])continue;
    if(lastseen[c]>lastmatch){
      taken[c] = true;
      result[c]=make_pair(lastseen[c],coloring[i].second);
      lastmatch = coloring[i].second;
      //cout<<c<<" "<<lastseen[c]<<" "<<coloring[i].second<<endl;
    }else{
      lastseen[c] = coloring[i].second;
    }
  }
  return result;
}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N,K;
  cin>>N>>K;
  vector<int> a(N);
  vector<int> b(N);
  vector<int> c(N*K);
  vector<vector<pair<int,int>>> minis((N+K-2)/(K-1));
  for(int i=0;i<N*K;++i){
    
    cin>>c[i];
    --c[i];
    minis[c[i]/(K-1)].emplace_back( c[i]% (K-1),i+1);
  }
  for(int j=0; j<N;j+=K-1){
    vector<pair<int,int>> temp = solve(minis[j/(K-1)],K);
    for(int i=0;i+j<N&&i<K-1;++i){
      cout<<temp[i].first<<" "<<temp[i].second<<"\n";
    }
  }
  cout<<flush;
}