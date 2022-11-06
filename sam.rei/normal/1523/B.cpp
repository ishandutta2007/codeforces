#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC;
  cin>>TC;
  while(TC-->0){
    int n;
    cin>>n;
    cout<<3*n<<"\n";
    for(int i=1;i<n;i+=2){
      int k,j;
      cin>>k>>j;
      cout<<2<<" "<<i<<" "<<(i+1)<<"\n";
      cout<<1<<" "<<i<<" "<<(i+1)<<"\n";
      cout<<2<<" "<<i<<" "<<(i+1)<<"\n";
      cout<<2<<" "<<i<<" "<<(i+1)<<"\n";
      cout<<1<<" "<<i<<" "<<(i+1)<<"\n";
      cout<<2<<" "<<i<<" "<<(i+1)<<"\n";
    }
  }

  cout<<flush;
}