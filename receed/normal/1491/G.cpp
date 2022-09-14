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

const int N = 200002;
int a[N], used[N];
vector<int> c[N];
vector<pair<int, int>> ans;

void sw(int x, int y) {
  swap(a[x], a[y]);
  a[x] *= -1;
  a[y] *= -1;
  ans.push_back({x, y});
}

void go(const vector<int> &v1, const vector<int> &v2) {
  for (int i : v1)
    sw(i, v2.back());
  for (int i : v2)
    sw(v1[0], i);
}

void go(const vector<int> &v1) {
  for (int i = 1; i + 1 < (int) v1.size(); i++)
    sw(v1.back(), v1[i]);
  sw(v1[0], v1.back());
  sw(v1[0], v1[1]);
  sw(v1[1], v1.back());
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  int pos = 0;
  vector<pair<int, int>> li;
  for (int i = 1; i <= n; ++i) {
    if (used[i])
      continue;
    int v = i;
    while (!used[v]) {
      used[v] = 1;
      c[pos].push_back(v);
      v = a[v];
    }
    li.push_back({c[pos].size(), pos});
    pos++;
  }
  sort(all(li));
  if (li.back().first == 1) {
    cout << 0;
    return 0;
  }
  for (int i = 1; i < li.size(); i += 2)
    go(c[li[i - 1].second], c[li[i].second]);
  if (li.size() % 2) {
    if (li.back().first == 2)
      go({c[li[0].second][0]}, c[li.back().second]);
    else
      go(c[li.back().second]);
  }
  cout << ans.size() << '\n';
  for (auto &pp : ans)
    cout << pp.first << ' ' << pp.second << '\n';
  for (int i = 1; i <= n; ++i)
    assert(a[i] == i);
}