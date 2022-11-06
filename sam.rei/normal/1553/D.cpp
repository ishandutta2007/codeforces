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
  int n = t.size();
  // go backwards from the end of t
  // must match one char of s at a time, can skip blocks of 2x for some x
  int currmaxeven = 0;
  int currmaxodd  = 0;
  if (s.size()%2 == 0){
    currmaxodd = -1000000;
  }
  else {
    currmaxeven = -1000000;
  }
  for(int i = s.size()-1; i>=0; --i){
    if(i%2==0){
      if(currmaxodd>=0)
      if(s[i] == t[n-currmaxodd-1]){
        currmaxeven = max(currmaxeven,1+currmaxodd);
      }
    }else{
      if(currmaxeven>=0)
      if(s[i] == t[n-currmaxeven-1]){
        currmaxodd = max(currmaxodd,1+currmaxeven);
      }
    }
    if(currmaxodd == n || currmaxeven ==n)break;
  }
  return currmaxodd == n || currmaxeven ==n;
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