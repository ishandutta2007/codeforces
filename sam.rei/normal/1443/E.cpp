#include "bits/stdc++.h"

using namespace std;
#define ll long long 
static ll prefix [200001];
static int n;
static int a[200001];
//static ll to_perm_base(){

//}
void setup_prefix(int start){
  if(start==0) prefix[0]=0;
  for(int i=start;i<n;++i){
    prefix[i+1]=prefix[i]+a[i];
  }
}
void permute_back(ll perm){
  vector<int> vals;
  vals.push_back(0);
  int c =2;
  while(perm>0){
    vals.emplace_back((int)(perm%c));
    perm/=c;
    ++c;
  }
  int m = vals.size();
  set<int> news(a+(n-m),a+n);
  for(int j=m-1;j>=0;--j){
    auto it = news.begin();
    //cout<<j<<" "<<vals[j]<<endl;
    for(int i=0;i<vals[j];++i)++it;
    a[n-j-1] = *it;
    news.erase(*it);
  }
  setup_prefix(n-m);
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q;
  cin>>n>>q;

  for(int i=0;i<n;++i){
    a[i]=i+1;
  }

  setup_prefix(0);
  ll curr = 0;
  while(q-->0){
    int tt;
    cin>>tt;
    if(tt==1){
      int l,r;
      cin>>l>>r;
      cout<<prefix[r]-prefix[l-1]<<'\n';
    }
    else{
      int x;
      cin>>x;
      curr += x;
      permute_back(curr);
    }
  }
  
  cout<<flush;
  return 0;
}