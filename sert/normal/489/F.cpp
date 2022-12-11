#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9 + 34;
typedef long long ll;
const int N = 504;

int MD;

ll dp[N][N];
map<pair<int, int>, ll> mp;

inline ll c2(ll x) {
  return (x * (x - 1)) / 2;
}

ll getDP(int h, int w) {
  if (h == 0 || w == 0) return dp[h][w] = 1;
  auto key = make_pair(h, w);
  if (mp.count(key)) return mp[key];

  ll n1 = 2 * (w - h);
  ll n2 = 2 * h - w;

  ll ans = 0;
  if (n1 >= 2)
    ans += getDP(h - 1, w - 2) * h * (n1 - 1);  
  if (n1 >= 1 && n2 >= 1)
    ans += getDP(h - 1, w - 1) * h * n2;

  if (n1 == 0)
    ans += c2(n2) * getDP(h - 1, w);

  ans %= MD;

  // cout << h << " " << w << " n1=" << n1 << " n2=" << n2 << " ans:" << ans << "\n";

  return mp[key] = dp[h][w] = ans;  
}

void solve() {
  int n, m;
  cin >> n >> m >> MD;

  vector<int> sum(n, 0);
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++) {
      if (s[j] == '1')
        sum[j]++;
    }
  }

  int h = n - m;
  int w = n;
  for (int i = 0; i < n; i++)
    if (sum[i] == 2)
      w--;

  cout << getDP(h, w) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}