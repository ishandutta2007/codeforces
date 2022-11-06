#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()

int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  vector<pair<ll,ll>> ba(n);
  for(int i=0;i<n;++i)cin>>ba[i].second>>ba[i].first;
  
  // sort by required to cost 1, attack from both ends;
  ll currpurch = 0;
  ll spent = 0;
  int front = 0;
  int back = n-1;
  sort(RANGE(ba));
  while(true){
    if (front > back){
      break;
    }
    if(currpurch>=ba[front].first){
      currpurch+=ba[front].second;
      spent += ba[front].second;
      //cout<<" buying "<<ba[front].first;
      ++front;
    }else{
      ll taken = min(ba[back].second, ba[front].first-currpurch);
      currpurch+=taken;
      spent += 2*taken;
      ba[back].second-=taken;
      //cout<<" buying "<<ba[back].first;
      if(ba[back].second==0)--back;
    }
  }
  cout<<spent<<endl;
}