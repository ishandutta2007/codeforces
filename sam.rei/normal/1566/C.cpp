#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
void one(){
  int n;
  string s1,s2;
  cin>>n>>s1>>s2;
  // 01 -> 2
  // 11 will grab a nearby 00, take it to 2
  // determine if we want to go left or right
  int res = 0;
  bool avail = false;
  bool avail1= false;
  for(int i=0;i<n;++i){
    if(s1[i]!=s2[i]){
      res+=2;
      avail = false;
      avail1 = false;
    }else{
      if(s1[i]=='0'){
        ++res;
        if(avail1){
          avail = false;
          avail1= false;
          ++res;
        }
        else{
          avail = true;
        }
        avail1= false;
      }
      else{
        // check left
        if(avail && i>0){
          // claim previous
          ++res;
        }else{
          avail1= true;
        }
        avail = false;
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