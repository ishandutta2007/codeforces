#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int N = 4000002;
ll n, m, cs = 0, ci;
ll dp[N], md[N];
vector<pair<int, int>> pd;

void go(int pos, ll x) {
  if (pos == pd.size()) {
    if (x != ci) {
      cs = (cs + dp[x] - dp[x - 1] + m) % m;
    }
    return;
  }
  rep(i, pd[pos].second + 1) {
    if (i)
      x *= pd[pos].first;
    go(pos + 1, x);
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (ll i = 2; i <= n; ++i) {
    if (!md[i])
      md[i] = i;
    for (ll j = i * i; j <= n; j += i)
      if (!md[j])
        md[j] = i;
  }
  dp[1] = 1;
  for (int i = 2; i <= n; ++i) {
    ci = i;
    cs = (cs + dp[i - 1]) % m;
    int x = i;
    pd.clear();
    while (x > 1) {
      if (!pd.empty() && md[x] == pd.back().first)
        pd.back().second++;
      else
        pd.push_back({md[x], 1});
      x /= md[x];
    }
    go(0, 1);
    dp[i] = cs;
  }
  cout << cs << '\n';
}