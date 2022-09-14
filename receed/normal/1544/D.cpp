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
  int t, n, x;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n), fa(n), used(n);
    int ans = 0;
    rep(i, n) {
      cin >> a[i];
      a[i]--;
      fa[i] = a[i];
      if (used[a[i]])
        a[i] = -1;
      else {
        used[a[i]] = 1;
        ans++;
      }
    }
    vector<int> li, ls;
    rep(i, n) {
      if (!used[i])
        li.push_back(i);
      if (a[i] == -1)
        ls.push_back(i);
    }
    assert(li.size() == ls.size());
    if (li.size() == 1 && li[0] == ls[0]) {
      int x = li[0];
      int y = -1;
      rep(i, n)
        if (a[i] == fa[x])
          y = i;
      a[x] = fa[x];
      ls[0] = y;
    }
    int k = ls.size();
    rep(i, k)
      if (ls[i] == li[i]) {
        int j = (i + 1) % k;
        swap(li[i], li[j]);
      }
    rep(i, k)
      a[ls[i]] = li[i];
    cout << ans << '\n';
    rep(i, n)
      cout << a[i] + 1 << ' ';
    cout << '\n';
  }
}