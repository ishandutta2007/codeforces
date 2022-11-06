#include "bits/stdc++.h"

using namespace std;
//static int w[100000];
//static char s[300001];
#define ll long long 
static ll values[100001];
static int cs   [100001];
static ll cc    [100001];
ll cost_to_split(int i){
  ll n = cs[i]+1;
  ll x = values[i]/(cs[i]+1);
  ll c = values[i]%n;
  return c*(2*x+1) + n*x*x -cc[i];  
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,k;

  cin >>n>>k;
  std::vector<std::pair<int,int>> booms;
  
  for(int i = 0; i<n;++i){
    cin>>values[i];
    cc[i] = values[i]*values[i];
    cs[i]=1;

  }
  //sort(values,values+n);
  using pli = pair<ll,int>;
  std::priority_queue<pli,vector<pli>,greater<pli>> bonuses;
  for(int i=0;i<n;++i){
    bonuses.emplace(cost_to_split(i),i);
  }
  for(int i=n;i<k;++i){
    pli split = bonuses.top();
    bonuses.pop();
    int j = split.second;
    cc[j]+=split.first;
    ++cs[j];
    bonuses.emplace(cost_to_split(j),j);
  }
  ll res=0;
  for(int i=0;i<n;++i){
    res += cc[i];
  }
  cout<<res<<endl;
  return 0;
}