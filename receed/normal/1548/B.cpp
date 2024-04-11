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

const int N = 1 << 18;
ll nn = 1;
ll tr[N * 2], a[N];
ll cur;

void get(int cl, int cr, int v, int l, int r) {
  if (cr <= l || r <= cl)
    return;
  if (cl <= l && r <= cr) {
    cur = gcd(cur, tr[v]);
    return;
  }
  get(cl, cr, v * 2, l, (l + r) / 2);
  get(cl, cr, v * 2 + 1, (l + r) / 2, r);
}

ll get(int cl, int cr) {
  cur = 0;
  get(cl, cr, 1, 0, nn);
  return cur;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    rep(i, n)
      cin >> a[i];
    nn = 1;
    while (nn < n)
      nn *= 2;
    rep(i, n - 1)
      tr[nn + i] = abs(a[i + 1] - a[i]);
    for (int i = nn - 1; i > 0; --i)
      tr[i] = gcd(tr[i * 2], tr[i * 2 + 1]);
    int ans = 1, pos = 0;
    rep(i, n - 1) {
      while (pos <= i && get(pos, i + 1) == 1)
        pos++;
      ans = max(ans, i - pos + 2);
    }
    cout << ans << '\n';
  }
}