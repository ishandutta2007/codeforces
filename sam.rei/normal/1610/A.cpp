#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define RANGE(x) x.begin(),x.end()
void one(){
  int n,m;
  cin>>n>>m;
  if(min(n,m)==1){
    if(max(n,m)==1)cout<<"0\n";
    else cout<<1<<'\n';}
    else cout<<2<<'\n';
  
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