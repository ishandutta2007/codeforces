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

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t, n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    vector<int> used(2 * n);
    vector<int> x(n), y(n);
    rep(i, k) {
      cin >> x[i] >> y[i];
      x[i]--; y[i]--;
      if (x[i] > y[i])
        swap(x[i], y[i]);
      used[x[i]] = used[y[i]] = 1;
    }
    vector<int> li;
    rep(i, 2 * n)
      if (!used[i])
        li.push_back(i);
    rep(i, n - k) {
      x[k + i] = li[i];
      y[k + i] = li[n - k + i];
    }
    int ans = 0;
    rep(i, n)
      rep(j, i)
        if (!(y[i] < x[j] || y[j] < x[i] || x[i] < x[j] && y[j] < y[i] || x[j] < x[i] && y[i] < y[j]))
          ans++;
    cout << ans << '\n';
  }
}