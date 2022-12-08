#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int n;

ll ans = 0LL;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  priority_queue<ll> pq;
  cin >> n;
  ll cur;
  cin >> cur;
  // ll popt = cur;
  pq.push(cur);
  ll res = 0LL;
  for (int i = 1; i < n; i++) {
    cin >> cur;
    cur -= i;

    if (pq.top() <= cur) {
      //opt becomes cur
      res += 0LL;
      pq.push(cur);
    }
    else {
      res += abs(pq.top()-cur);
      pq.pop();
      pq.push(cur);
      pq.push(cur);
    }
  }
  cout << res << endl;
}