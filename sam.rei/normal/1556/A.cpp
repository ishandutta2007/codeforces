#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
int one(){
  int c,d;
  cin>>c>>d;
  if((c^d)&1)return -1;
  if(c==0 && d==0)return 0;
  if(abs(c)==abs(d)) return 1;
  return 2;
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