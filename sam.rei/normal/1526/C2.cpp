#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//typedef ll int;

int n;
pair<ll,ll> t [1000001];
pair<ll,ll> combine(pair<ll,ll> a, pair<ll,ll> b){
  // range sum, minimum prefix sum
  return make_pair(a.first+b.first,min(a.second,a.first+b.second));
}
void build(vector<pair<ll,ll>>& a, int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = a[tl];
  } else {
    int tm = (tl + tr) / 2;
    build(a, v*2, tl, tm);
    build(a, v*2+1, tm+1, tr);
    t[v] = combine(t[v*2],t[v*2+1]);
  }
}
pair<ll,ll> sum(int v, int tl, int tr, int l, int r) {
  if (l > r) 
    return make_pair(0ll,0ll);
  if (l == tl && r == tr) {
    return t[v];
  }
  int tm = (tl + tr) / 2;
  return combine(sum(v*2, tl, tm, l, min(r, tm))
		 ,sum(v*2+1, tm+1, tr, max(l, tm+1), r));
  }
void update(int v, int tl, int tr, int pos, ll new_val) {
  if (tl == tr) {
    t[v] = make_pair(new_val,min(0ll,new_val));
  } else {
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      update(v*2, tl, tm, pos, new_val);
    else
      update(v*2+1, tm+1, tr, pos, new_val);
    t[v] = combine(t[v*2],t[v*2+1]);
  }
}

int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>n;
  vector<ll> pots(n,-7);
  for(int i=0;i<n;++i)
    cin>>pots[i];
  // now have all the positives, go backward
  int res = 0;
  // check over allowed ones, see if can be done, othwerise ignore
  vector<pair<ll,int>> pospairs;
  vector<pair<ll,ll>> nonn(n,make_pair(0ll,0ll));
  for(int i=0;i<n;++i){
    if(pots[i]<0)
      pospairs.emplace_back(-pots[i],i);
    else{
      nonn[i]=make_pair(pots[i],0);
      ++res;
    }
  }
  build(nonn,1,0,n-1);
  //cout<<"built"<<endl;
  sort(pospairs.begin(),pospairs.end());
  // keep track of least prefix sum
  // and prefix sums
  for(auto pai: pospairs){
    // check if prefix is enough
    int pos = pai.second;
    ll value = -pai.first;
    pair<ll,ll> query = sum(1,0,n-1,0,pos);
    if(query.first+value<0)continue;// can't eat
    // check if later is okay
    pair<ll,ll> required = sum(1,0,n-1,pos,n-1);
    if(required.second+query.first+value<0)continue;
    update(1,0,n-1,pos,value);
    ++res;
  }
  cout<<res<<endl<<flush;
}