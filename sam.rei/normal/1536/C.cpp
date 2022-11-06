#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define RANGE(x) x.begin(),x.end()
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC;
  cin>>TC;
  auto cmp = [](const pll& a,const pll& b){
			  return a.first*b.second<a.second*b.first;
	     };
  while(TC-->0){
    int n;
    string s;
    cin>>n>>s;
    int k=0;
    int d=0;
    vector<int> results;
   
    map<pll,int,decltype(cmp)> counts(cmp);
    for(int i=0;i<n;++i){
      if(s[i]=='K')++k;
      else ++d;
      pll ratio = make_pair((ll)k,(ll)d);
      //cout<<ratio.first<<" "<<ratio.second<<endl;
      counts.emplace(ratio,0).first->second++;
      cout<<counts[ratio]<<(i==n-1?"\n":" ");
    }
  }
  cout<<flush;
}