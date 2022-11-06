#include "bits/stdc++.h"

using namespace std;
//static int w[100000];
//static char s[300001];
#define ll long long 
static ll counts[200001];
static int p[200001];
static int nl[200001];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >>n;
  for(int j=1;j<n;++j){
    cin>>p[j];
    --p[j];
  }
  for(int j=0;j<n;++j){
    cin>>counts[j];
    nl[j]=0;
  }
  p[0]=0;
  ll m=0;
  for(int c=n-1;c>=0;--c){
    if(nl[c]==0){
      nl[c]=1;//we are a leaf
    }
    m=max(m,(counts[c]+nl[c]-1)/nl[c]);
    nl[p[c]]+=nl[c];
    counts[p[c]]+=counts[c];
  }
  cout<<m<<flush;
  return 0;
}