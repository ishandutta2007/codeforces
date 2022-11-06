#include "bits/stdc++.h"

using namespace std;

static int a[100];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int ct;
  cin>>ct;
  while(ct-->0){
    int n,m;
    cin>>n>>m;
    while(n-->0){
      int k;
      cin>>k;
      m-=k;
    }
    if(m==0)cout<<"YES\n";
    else cout<<"NO\n";
  }
  cout<<flush;
}