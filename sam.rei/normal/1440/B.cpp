#include "bits/stdc++.h"

using namespace std;
//static int w[100000];
//static char s[300001];
#define ll long long 
static ll vals[300001];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int ct;
  cin>>ct;
  while(ct-->0){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n*k;++i){
      cin>>vals[i];
    }
    sort(vals,vals+n*k);
    ll tot=0;
    int z = n/2;
    for(int i=0;i<k;++i){
      tot+=vals[n*k - (z+1)*(i+1)];
    }
    cout<<tot<<endl;
  }
  cout<<flush;
  
  return 0;
}