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

const int N = 5002;
ll s[N], nx[N];
ll t, n;

int fn(int p) {
  if (nx[p] < n && s[nx[p]] == 1) {
    nx[p] = fn(nx[p]);
  }
  return nx[p];
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> t;
  rep(z, t) {
    cin >> n;
    rep(i, n) {
      cin >> s[i];
      nx[i] = i + 1;
    }
    ll ans = 0;
    rep(i, n) {
      ll cm = min(n - i, s[i]);
      ans += s[i] - cm;
      s[i] = cm;
      while (s[i] > 1) {
        ans++;
        int pos = i;
        while (pos < n) {
          int op = pos;
          if (s[pos] > 1)
            pos += s[pos];
          else
            pos = fn(pos);
          if (s[op] > 1)
            s[op]--;
        }
      }
    }
    cout << ans << '\n';
  }
}