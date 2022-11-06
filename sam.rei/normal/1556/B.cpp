#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
ll eval(const vector<int> & B, bool ofirst){
  ll res2 = 0;
  int p1=0;
  int p2=1;
  for(int j=0;j<B.size();++j){
    if((B[j]==1)==ofirst){
      res2+= abs(p1-j);
      p1+=2;
    }else{
      res2+= abs(p2-j);
      p2+=2;
    }
  }
  return res2/2;
}
ll one(){
  int N;
  cin>>N;
  vector<int> p(N);
  vector<int> pcount(2,0);
  for(int i=0;i<N;++i){
    cin>>p[i];
    p[i]%=2;
    ++pcount[p[i]];
  }
  if(N&1){
    // odd, only one way to do things
    if(pcount[1]>pcount[0]){
      // 1s first
      if(pcount[1]!=1+pcount[0]){
        return -1;
      }
      return eval(p,true);
    }
    else{
       if(pcount[1]!=pcount[0]-1){
        return -1;
       }
       
      return eval(p,false);
    }             
  }else{
    if(pcount[1]!=pcount[0])return -1;
    return min(eval(p,true),eval(p,false));
  }
}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC;
  cin>>TC;
  while(TC-->0){
    cout<<one()<<'\n';
  }
  cout<<flush;
}