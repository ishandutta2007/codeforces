#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
struct FenwickTree {
    vector<ll> bit;  // binary indexed tree
    ll n;

    FenwickTree(ll n) {
        this->n = n;
        bit.assign(n, 0);
    }

    ll sum(int r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    ll sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, ll delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll N;
  cin>>N;
  vector<ll> x(N),y(N),v(N);
  vector<pair<ll,ll>> events;
  vector<ll> costs(N);
  for(ll i=0;i<N;++i){
    cin>>x[i]>>y[i]>>v[i];
    events.emplace_back(x[i],1+i);
    events.emplace_back(y[i],-1-i);
    costs[i] = (x[i]-y[i])%mod;
  }
  ll res = x[N-1]+1;
  //cout<<res<<endl;
  sort(events.begin(),events.end());
  FenwickTree ft(2*N);
  for(int i=0;i<2*N;++i){
    if(events[i].second>0)x[events[i].second-1]=i;
    if(events[i].second<0)y[-1-events[i].second]=i;
  }

  for(int i=2*N-1;i>=0;--i){
    if(events[i].second>0){
      int p = events[i].second-1;
      ll tps = (ft.sum(i)+v[p])%mod;
      //cout<<ft.sum(i)<<" "<<tps<<endl;
      res += (tps*costs[p])%mod;
      ft.add(y[p],tps);
      //   cout<<tps<<" "<<res<<endl;
    }
  }

  cout<<res%mod<<endl;
}