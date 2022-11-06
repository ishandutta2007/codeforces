#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
int main(){
  //std::ios_base::sync_with_stdio(false);
  //  cin.tie(NULL);
  int N,K;
  // given a or b, b or c, c or a : can determine which are set unless
  // a,b,c all set, then need a and b, b and c
  // figures out a,b,c . then, 
  cin>>N>>K;
  cout<<"or 1 2\nor 2 3\nor 1 3\nand 1 2\nand 2 3\nand 1 3"<<endl;
  vector<int> res(3,0);
  int or12,or23,or13,and12,and23,and13;
  cin>>or12>>or23>>or13>>and12>>and23>>and13;
  res[0] = (or12&or13)&((~and23)|(and12|and13));//
  res[1] = (or12&or23)&((~and13)|(and12|and23));//
  res[2] = (or13&or23)&((~and12)|(and23|and13));// 
  //cerr<<res[0]<<" "<<res[1]<<" "<<res[2]<<endl;
  for(int j=4;j<=N;++j){
    cout<<"or 1 "<<j<<'\n';
    cout<<"and 1 "<<j<<'\n';
    int a,b;
    cin>>a>>b;
    res.push_back(res[0]^(a^b));
  }
  sort(RANGE(res));
  cout<<"finish "<<res[K-1]<<endl;
}