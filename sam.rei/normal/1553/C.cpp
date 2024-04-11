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
  string s;
  cin>>s;
  int lcurrmax = 0;
  int rcurrmax = 0;
  int lcurrmin = 0;
  int rcurrmin = 0;
  int lendmax = 5;
  int rendmax = 5;
  int lendmin = 5;
  int rendmin = 5;
  for(int i=0;i<10;++i){
    if(i%2==0){
      switch(s[i]){
      case '0':
        --lendmin;
        --lendmax;
        break;
      case '1':
        ++lcurrmin;
        ++lcurrmax;
        break;
      case '?':
        ++lcurrmax;
        --lendmin;
        break;
      }
    }
    else{
      switch(s[i]){
      case '0':
        --rendmin;
        --rendmax;
        break;
      case '1':
        ++rcurrmin;
        ++rcurrmax;
        break;
      case '?':
        ++rcurrmax;
        --rendmin;
        break;
      }
    }
    if( lendmin < rcurrmax || rendmin < lcurrmax){
      cout<< (i+1)<<"\n";
      return;
    }
  }
  cout<<10<<"\n";
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