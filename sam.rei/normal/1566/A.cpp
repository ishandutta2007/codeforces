#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
void one(){
  int n,s;
  cin>>n>>s;
  // there are n/2 values
  // all else can be 0
  // 0 0 0 0 0 x x x x
  // n 5 -> 3rd element
  // n 2 -> 2nd element
  int pos = 1 + n - (n+1)/2;
  cout<< s/pos<<'\n';
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