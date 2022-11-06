#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
void one(){
  int n;
  cin>>n;
  vector<int> vec(n);
  int minpos=0,maxpos=0;
  for(int i=0;i<n;++i){
    int k;
    cin>>k;
    if(k==1){
      minpos =i;
    }
    if(k==n){
      maxpos = i;
    }
  }
  cout<< min(min(max(minpos+1,maxpos+1),max(n-minpos,n-maxpos)),min(minpos+ n-maxpos+1, 1-minpos+ n+maxpos))<<"\n";
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