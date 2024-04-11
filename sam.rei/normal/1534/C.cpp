#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
void one(){
  int n;
  cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;++i){
    cin>>v[i];
    --v[i];
  }
  vector<int> u(RANGE(v));
  for(int i=0;i<n;++i){
    cin>>v[i];
    --v[i];
  }
  vector<int> perm(n);
  for(int i=0;i<n;++i){
    perm[u[i]]=v[i];
  }
  vector<bool> marked(n,false);
  ll res = 1;
  for(int i=0;i<n;++i){
    if(marked[i])continue;
    int curr=i;
    while(1){
      marked[curr]=true;
      curr=perm[curr];
      if(curr==i)break;
    }
    res*=2;
    res%=1000000007;
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