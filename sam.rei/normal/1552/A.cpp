#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void one(){
  int n;
  string s;
  cin>>n>>s;
  string d =s;
  vector<char> cs(s.begin(),s.end());
  sort(cs.begin(),cs.end());
  int res =0;
  for(int i=0;i<n;++i){
    if(cs[i]!=s[i])++res;
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