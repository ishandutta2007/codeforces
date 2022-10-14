#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

#define pb push_back
// #define int long long
#define ld long double
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;
const int N = 262144;
int tree1[4 * N + 777], tree2[4 * N + 777];

void upd1(int v, int l, int r, int i, int x) {
  if (l + 1 == r && l == i) {
    tree1[v] = x;
    return;
  }
  int m = (l + r) / 2;
  if (i < m) {
    upd1(2 * v + 1, l, m, i, x);
  } else {
    upd1(2 * v + 2, m, r, i, x);
  }
  tree1[v] = max(tree1[2 * v + 1], tree1[2 * v + 2]);
}

void upd2(int v, int l, int r, int i, int x) {
  if (l + 1 == r && l == i) {
    tree2[v] = x;
    return;
  }
  int m = (l + r) / 2;
  if (i < m) {
    upd2(2 * v + 1, l, m, i, x);
  } else {
    upd2(2 * v + 2, m, r, i, x);
  }
  tree2[v] = max(tree2[2 * v + 1], tree2[2 * v + 2]);
}

int get1(int v, int l, int r, int lq, int rq) {
  if (l >= rq || lq >= r || l >= r) {
    return (int) -1e9;
  }
  if (l >= lq && r <= rq) {
    return tree1[v];
  }
  int m = (l + r) / 2;
  return max(get1(2 * v + 1, l, m, lq, rq), get1(2 * v + 2, m, r, lq, rq));
}

int get2(int v, int l, int r, int lq, int rq) {
  if (l >= rq || lq >= r || l >= r) {
    return (int) -1e9;
  }
  if (l >= lq && r <= rq) {
    return tree2[v];
  }
  int m = (l + r) / 2;
  return max(get2(2 * v + 1, l, m, lq, rq), get2(2 * v + 2, m, r, lq, rq));
}

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  vector<int> l(n + 1, -1), r(n + 1, -1);
  for (int i = 0; i < n; i++) {
    r[A[i]] = i;
    if (l[A[i]] == -1) {
      l[A[i]] = i;
    }
  }
  vector<pair<int, int>> kek;
  for (int j = 1; j <= n; j++) {
    if (l[j] != -1 && l[j] != r[j]) {
      kek.pb({l[j], r[j]});
    }
  }
  sort(all(kek));
  int k = (int) kek.size();
  for (int i = 0; i < k; i++) {
    int lf = kek[i].first, rf = kek[i].second;
    int mdp = rf - lf - 1;
    mdp = max(mdp, get1(0, 0, N, 0, lf) + rf - lf - 1);
    mdp = max(mdp, rf - 1 + get2(0, 0, N, lf, rf));
    upd1(0, 0, N, rf, mdp);
    upd2(0, 0, N, rf, mdp - rf);
  }
  int ans = get1(0, 0, N, 0, n);
  ans = max(ans, 0);
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  for (int i = 0; i < 4 * N + 228; i++) {
    tree1[i] = (int) -1e9;
    tree2[i] = (int) -1e9;
  }
  while (t--) {
    solve();
  }
}