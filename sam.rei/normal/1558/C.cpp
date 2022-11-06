#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
void apply(vector<int>& P, int v,vector<int>& moves){
  moves.push_back(v);
  for(int i=0;i*2<v-1;++i){
    swap(P[i],P[v-1-i]);
  }
}
void one(){
  int N;
  cin>>N;
  vector<int> P(N);
  for(int i=0;i<N;++i){
    cin>>P[i];
  }
  vector<int> moves;
  for(int j=N;j>=3;j-=2){
    // find j, flip to front
    int index = -1;
    for(int i=0;i<j;++i){
      if(P[i]==j) index = i;
    }
    // cerr<<"e"<<index<<endl;
    if(index%2!=0){
      cout<<"-1\n";return;
    }
    apply(P,index+1,moves);
    for(int i=0;i<j;++i){
      if(P[i]==j-1) index = i;
    }
    //cerr<<"E"<<index<<endl;
    if(index%2!=1){
      cout<<"-1\n";return;
    }
    apply(P,index,moves);
    apply(P,index+2,moves);
    apply(P,3,moves);
    apply(P,j,moves);
  }
  cout<<moves.size()<<'\n';
  for(int i=0;i<moves.size();++i)cout<<moves[i]<<" \n"[i==moves.size()-1];
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