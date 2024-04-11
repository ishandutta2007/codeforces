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
bool one(){
  string s,t;
  cin>>s>>t;
  int n = s.length();
  int m = t.length();
  for(int i=0;i<n;++i){
    for(int j=i;j<n&&j-i+1<=m;++j){
      if(s[j] != t[j-i])break;
      bool works = true;
      int currp = j-i+1;
      int k = j-1;
      // cout<<"trying "<<i<<" "<<j<<endl;
      for(;currp<m;++currp){
        if(t[currp]!=s[k])break;
        --k;
      }
      if(currp==m)return true;
    }
  }
  // construct prefix of t with s
  // construct prefix of rev(t) with s
  
  return false;
}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC;
  cin>>TC;
  while(TC-->0){
    cout<<(one()?"YES":"NO")<<"\n";
  }
  cout<<flush;
}