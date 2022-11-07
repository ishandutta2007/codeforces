#include "bits/stdc++.h"

using namespace std;
//static int w[100000];
//static char s[300001];
#define ll long long 
static ll p = 998244353;
static int a[200001];
static int b[200001]; 
static int na[200001];
static bool taken[200002];
int main(){
  constexpr int N=100000;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int ct;
  cin>>ct;
  while(ct-->0){
  int n,k;
  cin>>n>>k;
  taken[0]=taken[n+1]=true;
  for(int i =0; i<n; ++i){
    cin>>a[i];
    --a[i];
    na[a[i]]=i+1;
    taken[i+1]= false;
  }
  for(int j=0;j<k;++j){
    cin>>b[j];
    --b[j];
    taken[na[b[j]]] = true;
  }
  ll r = 1;
  for(int i=0;i<k;++i){
    taken[na[b[i]]] = false;
    int op = 0;
    if(!taken[na[b[i]]+1])++op;
    if(!taken[na[b[i]]-1])++op;
    r*=op;
    r%=p;       
  }
  cout<<r<<'\n';

}
  cout<<flush;
  return 0;
}