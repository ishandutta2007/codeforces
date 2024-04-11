#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()

int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,q;
  cin>>n>>q;
  string s;
  cin>>s;
  vector<int> tots(n+1,0);
  for(int i=0;i<n;++i){
    tots[i+1] =tots[i]+ (int) (s[i]-'a'+1);
  }
  while(q-->0){
    int l,r;
    cin>>l>>r;
    cout<< tots[r]-tots[l-1]<<"\n";
  }
  cout<<flush;
}