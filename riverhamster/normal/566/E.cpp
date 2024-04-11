#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <bitset>
#include <unordered_map>
#include <cassert>
using namespace std;

#define LOG(f...) fprintf(stderr, f)

using ll = long long;

template<class T> void read(T &x){
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
  x *= f;
}
template<class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int N = 1005;
bitset<N> S[N];
bitset<N> G[N];
vector<pair<int, int>> res;
unordered_map<bitset<N>, int> ID;
bitset<N> nleaf;
int cnt[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  read(n);
  bool full = true;
  for (int i = 1; i <= n; ++i) {
    int c, x;
    read(c); cnt[i] = c;
    full &= (c == n);
    while (c--) read(x), S[i].set(x);
  }
  if (full) {
    for (int i = 2; i <= n; ++i)
      printf("1 %d\n", i);
    return 0;
  }
  for (int i = 1; i < n; ++i)
    for (int j = i + 1; j <= n; ++j) {
      auto I = S[i] & S[j];
      if (I.count() != 2) continue;
      int x = I._Find_first(), y = I._Find_next(x);
      if (G[x].test(y)) continue;
      res.emplace_back(x, y);
      G[x].set(y); G[y].set(x);
      nleaf.set(x); nleaf.set(y);
    }

  if (nleaf.count() == 2) {
    int x = nleaf._Find_first(), y = nleaf._Find_next(x);
    for (int i = 1; i <= n; ++i)
      if ((int)S[i].count() != n) {
        for (int j = 1; j <= n; ++j)
          if (!nleaf[j]) {
            if (!S[i].test(j)) res.emplace_back(y, j);
            else res.emplace_back(x, j);
          }
        goto finish;
      }
  }
  for (int i = 1; i <= n; ++i) G[i].set(i);

  ID.rehash(1.5 * n);
  for (int i = 1; i <= n; ++i)
    if (nleaf[i]) ID.emplace(G[i], i);
  for (int i = 1; i <= n; ++i) {
    if (nleaf[i]) continue;
    int id = 0, sz = 1e9;
    for (int j = 1; j <= n; ++j) {
      if (S[j].test(i) && cnt[j] < sz)
        id = j, sz = cnt[j];
    }
    auto mask = S[id] & nleaf;
    res.emplace_back(ID[mask], i);
  }

finish:
  for (const auto &p : res)
    printf("%d %d\n", p.first, p.second);
  return 0;
}