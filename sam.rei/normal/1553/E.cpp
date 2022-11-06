#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
template< class T>
vector<T> readvec(int N){
  vector<T> res(N);
  for(int i=0;i<N;++i)cin>>res[i];
  return res;
}
void one(){
  int N,M;
  cin>>N>>M;
  vector<int> t = readvec<int>(N);
  vector<int> offsets(N,0);
  for(int i=0;i<N;++i){
    --t[i];
    ++offsets[ (i-t[i]+N)%N];
  }
  vector<int> candidates;
  for(int i=0;i<N;++i){
    if(offsets[i]>= N-2*M)candidates.push_back(i); 
  }
  vector<int> result;
  for(int offset : candidates){
    // value at i is i-offset
    // cout<<"trying "<<offset<<endl;
    int ms = 0;
    vector<bool> seen(N,false);
    for(int i=0;i<N;++i){
      if(seen[i])continue;
      int curr = (t[i]+offset)%N;
      int len = 1;
      seen[i] = true;
      while(curr!=i){
        // offset = i-t[i]
        // t[i] should be at t[i]+offset
        seen[curr] = true;
        curr = (t[curr]+offset)%N;
        ++len;

      }
      ms+=len-1;
    }
    //cout<<ms<<" "<<offset<<endl;
    if(ms<=M)result.push_back(offset);
  }
  cout<<result.size();
  for(int i:result)cout<<" "<<i;
  cout<<"\n";
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