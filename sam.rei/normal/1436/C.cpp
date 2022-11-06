#include "bits/stdc++.h"

using namespace std;
//static int w[100000];
//static char s[300001];
#define ll long long 
static ll f[1001][1001];
static ll ncr[1001][1001];
const ll p = 1000000007;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int x,n,pos;
  cin >>n>>x>>pos;
  int l=0;
  int r=n;
  int lr = x-1;
  int gr = n-x;
  ll re=1;
  while(l<r){
    //std::cout<<l<<" "<<r<<endl;
    int m = (l+r)/2;
    if(m < pos){
      l = m+1;
      re*= lr;
      --lr;
      re%=p;
      //cerr<<lr<<endl;
    }else if(m==pos){
      l = m+1;
    }else{//m > pos
      re*= gr;
      --gr;
      re%=p;
      r=m;
      //cerr<<gr<<endl;
    }
  }
  int c = gr+lr;
  while(c>0){
    re*=c;
    re%=p;
    --c;
  }
  cout<<re<<flush;
  return 0;
}