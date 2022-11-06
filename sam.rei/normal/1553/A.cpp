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
  int N;
  cin>>N;
  cout<< (N+1)/10<<"\n";
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