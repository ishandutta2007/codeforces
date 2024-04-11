#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
void one(){
  string s;
  cin>>s;
  int state = 0;
  for ( char c : s){
    // seen a 0
    if(state == 0 && c =='0')++state;
    if(state == 1 && c =='1')++state;
    if(state == 2 && c =='0')++state;
  }
  // if it's possible to do with 0 - > no zeros
  // if it's possible to do as 1   - > all 0s consecutive
  // else 2 
  cout << "0112"[state]<<endl;
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