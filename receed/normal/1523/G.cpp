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

const int N = 100001;
vector<int> li[N], f[N], ls[N];
int sl[N], sr[N], ans[N];
int n, m;

ll go(int l, int r) {
  int x = N;
  for (int i = n - l; i; i &= i - 1) {
    int pos = lower_bound(all(li[i - 1]), r) - li[i - 1].begin();
    for (int j = pos; j; j &= j - 1)
      x = min(x, f[i - 1][j - 1]);
  }
  if (x == N)
    return 0;
  return sr[x] - sl[x] + 1 + go(l, sl[x]) + go(sr[x], r);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  rep(i, m) {
    cin >> sl[i] >> sr[i];
    ls[sr[i] - sl[i] + 1].push_back(i);
    for (int j = n - sl[i]; j < N; j |= j + 1)
      li[j].push_back(sr[i]);
  }
  rep(i, N) {
    sort(all(li[i]));
    li[i].erase(unique(all(li[i])), li[i].end());
    f[i].assign(li[i].size(), N);
  }
  for (int i = n; i >= 1; --i) {
    for (int j : ls[i])
      for (int k = n - sl[j]; k < N; k |= k + 1) {
        int pos = lower_bound(all(li[k]), sr[j]) - li[k].begin();
        for (int l = pos; l < f[k].size(); l |= l + 1)
          f[k][l] = min(f[k][l], j);
      }
    ans[i] = go(0, n + 1);
  }
  for (int i = 1; i <= n; ++i)
    cout << ans[i] << '\n';
}