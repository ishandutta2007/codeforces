#include <iostream>
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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int N = 300002;
vector<int> g[N];
vector<int> g0[N];
int A[N], B[N];
int cnt[N];
int par[N];
bitset<N> used;

vector<int> path(int a, int b) {
  used.reset();
  deque<int> st = {a};
  used[a] = true;
  while (!st.empty()) {
    int v = st.front();
    st.pop_front();
    for (auto u : g0[v]) {
      if (!used[u]) {
        used[u] = true;
        st.pb(u);
        par[u] = v;
      }
    }
  }
  vector<int> p;
  while (b != a) {
    p.pb(b);
    b = par[b];
  }
  p.pb(a);
  reverse(all(p));
  return p;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int _ = 0; _ < m; _++) {
    int x, y;
    cin >> x >> y;
    g[x].pb(y);
    g[y].pb(x);
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> A[i] >> B[i];
    cnt[A[i]]++;
    cnt[B[i]]++;
  }
  int kek = 0;
  for (int v = 1; v <= n; v++) {
    if (cnt[v] % 2) {
      kek++;
    }
  }
  if (kek) {
    cout << "NO\n";
    cout << kek / 2 << '\n';
    return 0;
  }
  vector<int> st = {1};
  used[1] = true;
  while (!st.empty()) {
    int v = st.back();
    st.pop_back();
    for (auto u : g[v]) {
      if (!used[u]) {
        used[u] = true;
        st.pb(u);
        g0[u].pb(v);
        g0[v].pb(u);
      }
    }
  }
  cout << "YES\n";
  for (int i = 0; i < q; i++) {
    vector<int> p = path(A[i], B[i]);
    cout << (int) p.size() << '\n';
    for (auto x : p) {
      cout << x << ' ';
    }
    cout << '\n';
  }


}