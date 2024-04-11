#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>
 
using namespace std;
 
typedef long long ll;
 
#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
 
int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k, l;
  cin >> n >> k >> l;
  string s;
  cin >> s;
  vector <int> ret;
  for (auto c : s) {
    if ('a' <= c && c <= 'z') ret.push_back(0);
    else ret.push_back(1);
  }
  const ll inf = (ll) (1e18) + 7;
  ll ans = n;
  for (int t = 0; t < 2; t++) {
    auto f = [&] (int m) {
      vector <pair <ll, int> > dp(n, make_pair(inf, 0));
      for (int i = 0; i < n; i++) {
        {
          auto go = (i >= l ? dp[i - l] : make_pair(0ll, 0));
          go.first += m;
          go.second++;
          dp[i] = min(dp[i], go);
        }
        {
          auto go = (i > 0 ? dp[i - 1] : make_pair(0ll, 0));
          go.first += ret[i];
          dp[i] = min(dp[i], go);
        }
      }
      return dp[n - 1];
    };
    if (f(0).second <= k) {
      ans = min(ans, f(0).first);
    } else {
      int l = 0, r = n + 228;
      while (l < r - 1) {
        int mid = (l + r) / 2;
        if (f(mid).second <= k) {
          r = mid;
        } else {
          l = mid;
        }
      }
      auto go = f(r);
      ans = min(ans, go.first - r * (ll) k);
    }
    for (int &x : ret) {
      x ^= 1;
    }
  }
  cout << ans << '\n';
}