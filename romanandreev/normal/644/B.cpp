#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define image(a) {sort(all(a)), a.resize(unique(all(a)) - a.begin());}

int main(){
  int n, b;
  cin >> n >> b;
  vector<int> d(n + 1);
  vector<ll> ans(n + 1);
  queue<int> q;
  ll cur = 0;
  for (int i = 0; i <= n; i++) {
    ll t;
    if (i < n) {
      cin >> t >> d[i];
    } else {
      t = (ll)1e18;
    }
    while (cur <= t && !q.empty()) {
      int x = q.front();
      q.pop();
      cur += d[x];
      ans[x] = cur;
    }
    if (cur < t && q.empty()) {
      cur = t;
    }
    if (sz(q) == b) {
      ans[i] = -1;
    } else {
      q.push(i);
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}