#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <random>
#include <unordered_map>
#include <array>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define LOG(f...) fprintf(stderr, f)
#define DBG(f...) printf("%3d: ", __LINE__), printf(f)
// #define DBG(f...) void()
#define all(cont) begin(cont), end(cont)

const int N = 200005;

ull H(ull x) {
  ull z = (x += 0x9e3779b97f4a7c15);
  z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;
  z = (z ^ (z >> 27)) * 0x94d049bb133111eb;
  return z ^ (z >> 31);
}

int n, m;

struct item {
  int i, c;
};

struct matrix {
  ull hR[N], hC[N];
  vector<item> R[N], C[N];
  int a[N];

  void init() {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        int x;
        scanf("%d", &x);
        a[i * m + j] = x;
        hR[i] += H(x); hC[j] += H(x);
        if (x != 0)
          R[i].push_back({j, x}), C[j].push_back({i, x});
      }
    for (int i = 0; i < n; ++i)
      sort(all(R[i]), [](item a, item b) { return a.c < b.c; });
    for (int i = 0; i < m; ++i)
      sort(all(C[i]), [](item a, item b) { return a.c < b.c; });
    for (int t = 0; t < min(n, m); ++t) {
      for (int i = 0; i < n; ++i)
        for (item j : R[i])
          hR[i] = H(hR[i] + hC[j.i]);
      for (int j = 0; j < m; ++j)
        for (item i : C[j])
          hC[j] = H(hC[j] + hR[i.i]);
    }
  }
} A, B;

vector<array<int, 3>> ans;

vector<int> perform(ull a[], ull b[], int n, int id) {
  unordered_multimap<ull, int> B;
  for (int i = 0; i < n; ++i)
    B.emplace(b[i], i);
  vector<int> P(n), iP(n);
  for (int i = 0; i < n; ++i) {
    auto it = B.find(a[i]);
    if (it == B.end()) {
      puts("-1");
      exit(0);
    }
    P[i] = it->second;
    B.erase(it);
  }
  for (int i = 0; i < n; ++i)
    iP[P[i]] = i;
  for (int i = 0; i < n; ++i) {
    while (P[i] != i) {
      ans.push_back({id, i, P[i]});
      swap(P[i], P[P[i]]);
    }
  }
  return iP;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  scanf("%d%d", &n, &m);
  A.init();
  B.init();
  fill(all(A.hC), 0); fill(all(B.hC), 0);
  for (int i : perform(A.hR, B.hR, n, 1))
    for (int j = 0; j < m; ++j)
      A.hC[j] = H(A.hC[j] + A.a[i * m + j]);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      B.hC[j] = H(B.hC[j] + B.a[i * m + j]);
  perform(A.hC, B.hC, m, 2);
  printf("%d\n", int(ans.size()));
  for (auto a : ans)
    printf("%d %d %d\n", a[0], a[1] + 1, a[2] + 1);
  return 0;
}