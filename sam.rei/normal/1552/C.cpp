#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool intersect(pair<int,int> a, pair<int,int> b){
  // cout<<a.first<<" "<<b.first<<" "<<a.second<<" "<<b.second<<endl;
  return (a.first<b.first && a.second<b.second && b.first < a.second )
       ||(b.first<a.first && b.second<a.second && a.first < b.second );
}
void one(){
  int N,K;
  cin>>N>>K;
  vector<pair<int,int>> pairs;
  vector<bool> taken(2*N,false);
  for(int i=0;i<K;++i){
    int A,B;
    cin>>A>>B;
    --A;
    --B;
    if(A>B)swap(A,B);
    pairs.emplace_back(A,B);
    taken[A]=taken[B]=true;
  }
  vector<int> nott;
  for(int i=0;i<2*N;++i){
    if(!taken[i]){
      // cout<<i<<" taken\n";
      nott.push_back(i);
    }
  }
  for(int i=0;i<N-K;++i){
    //cout<<nott[i]<<" "<<nott[i+N-K]<<endl;
    pairs.emplace_back(nott[i],nott[i+N-K]);
  }
  int res=0;
  for(int i=0;i<N;++i)
    for(int j=i+1;j<N;++j){
      if(intersect(pairs[i],pairs[j]))++res;
    }
  cout<<res<<"\n";
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