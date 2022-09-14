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

void pr(int v) {
  cout << (char) ('a' + v);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t, k = 26;
  string s;
  cin >> t;
  while (t--) {
    cin >> s;
    vector<int> cc(k);
    for (char c : s)
      cc[c - 'a']++;
    int v = -1;
    rep(i, k)
      if (cc[i] == 1) {
        v = i;
        break;
      }
    if (v != -1) {
      pr(v);
      cc[v] = 0;
      rep(i, k)
        rep(j, cc[i])
          pr(i);
      cout << '\n';
      continue;
    }
    v = 0;
    while (cc[v] == 0)
      v++;
    if (s.size() - cc[v] >= cc[v] - 2) {
      pr(v);
      cc[v]--;
      for (int i = v + 1; i < k; ++i)
        rep(j, cc[i]) {
          if (cc[v] > 0) {
            pr(v);
            cc[v]--;
          }
          pr(i);
        }
      if (cc[v])
        pr(v);
      cout << '\n';
      continue;
    }
    int u = v + 1;
    while (u < k && cc[u] == 0)
      u++;
    if (u == k) {
      cout << s << '\n';
      continue;
    }
    int w = u + 1;
    while (w < k && cc[w] == 0)
      w++;
    if (w == k) {
      pr(v);
      rep(i, cc[u])
        pr(u);
      rep(i, cc[v] - 1)
        pr(v);
      cout << '\n';
      continue;
    }
    pr(v);
    cc[v]--;
    pr(u);
    cc[u]--;
    rep(i, cc[v])
      pr(v);
    pr(w);
    cc[w]--;
    for (int i = u; i < k; ++i)
      rep(j, cc[i])
        pr(i);
    cout << '\n';
  }
}