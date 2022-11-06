#include "bits/stdc++.h"

using namespace std;
//static int w[100000];
//static char s[300001];
#define ll long long 
static ll a[200001], b[200001];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int ct;
  cin >>ct;
  while(ct-->0){
    int a,b;
    
    cin>>a>>b;
    if(b>0)--a;
    cout<<a<<" "<<b<<'\n';
  }
  cout<<flush;
  return 0;
}