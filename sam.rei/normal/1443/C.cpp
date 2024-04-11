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
    int n;
    cin>>n;
    ll totp = 0;
    for(int i=0;i<n;++i){
      cin>>a[i];
    }
    for(int i=0;i<n;++i){
      cin>>b[i];
      totp+=b[i];
    }
    
    vector<pair<ll,ll>> pairs;
    for(int i=0;i<n;++i){
      pairs.emplace_back(make_pair(a[i],b[i]));
    }
    sort(pairs.begin(),pairs.end());
    ll minv = totp;
    totp = 0;
    for( auto it = pairs.rbegin(); it!=pairs.rend();++it){
      minv = min(minv,max(totp,it->first));
      totp+=it->second;
    }
    cout<<minv<<'\n';
  }
  cout<<flush;
  return 0;
}