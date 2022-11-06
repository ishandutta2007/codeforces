#include "bits/stdc++.h"

using namespace std;

static int a[100];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int ct;
  cin>>ct;
  while(ct-->0){
    int n;
    cin>>n;
    int a = 2*n;
    for(int i=1;i<=n;++i){
      cout<<(2*i+a)<< (i==n?'\n':' ');
    }
  }
  cout<<flush;
}