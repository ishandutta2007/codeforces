#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
void one(){
  int n;
  cin>>n;
  vector<int> a(n);
  vector<int> b(n);
  for(int j=0;j<n;++j){cin>>a[j];}
  for(int j=0;j<n;++j){cin>>b[j];}
  sort(RANGE(a));
  sort(RANGE(b));
  int tot = n - (n/4);
  int asc = 0;
  int bsc = 0;
  for(int j=1;j<=tot;++j){
    asc+=a[n-j];
    bsc+=b[n-j];
  }
  int currlast = n-tot;
  int added=0;
  int k = n;
  // cout<<asc<<" "<<bsc<<" "<<k<<endl;
  while(asc<bsc){
    ++added;
    ++k;
    asc+=100;
    if(k%4 ==0){
      asc-=a[k/4 - 1];
    }
    else {
    int curramt = k - (k/4);
    if(curramt<=n){
      bsc+=b[n-curramt];
    }
    }
    // cout<<asc<<" "<<bsc<<" "<<k<<endl;
  }
  cout<< added<<'\n';
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