#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cassert>
using namespace std;

#define LOG(f...) fprintf(stderr, f)

const int N = 200005;
int a[N], cnt[N], sm[N], mode;
int L[N], R[N];
int last[N];
vector<int> pos[N];
int _first[N * 2], *first = _first + N;
int n;
int llen[N];

int force_solve(int x, int y) {
  first[0] = 0;
  int s = 0, res = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == x) ++s;
    if (a[i] == y) --s;
    if (first[s] != -1) res = max(res, i - first[s]);
    else first[s] = i;
  }
  fill(first - n, first + n + 1, -1);
  return res;
}
int solve(vector<int> &pos) {
  if (pos.empty()) return 0;
  int s = 0, res = 0;
  first[sm[pos.front() - 1]] = a[pos.front()] == mode ? L[pos.front()] : 0;
  for (int p : pos) {
    s += int(a[p] != mode);
    if (first[sm[p] - s] != -1) res = max(res, R[p] - 1 - first[sm[p] - s]);
    else first[sm[p] - s] = p;
  }
  first[sm[pos.front() - 1]] = -1;
  s = 0;
  for (int p : pos) {
    s += int(a[p] != mode);
    first[sm[p] - s] = -1;
  }
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i), ++cnt[a[i]];
    pos[a[i]].push_back(i);
  }
  mode = max_element(cnt + 1, cnt + 1 + n) - cnt;

  for (int i = 1; i <= n; ++i) sm[i] = sm[i - 1] + int(a[i] == mode);
  for (int i = 1; i <= n; ++i) {
    L[i] = max(last[a[i]], last[mode]);
    last[a[i]] = i;
  }
  fill(last + 1, last + 1 + n, n + 1);
  for (int i = n; i >= 1; --i) {
    R[i] = min(last[a[i]], last[mode]);
    last[a[i]] = i;
  }
  fill(first - n, first + n + 1, -1);

  int res = 0;
  vector<int> s; s.reserve(n);
  vector<int> rs; rs.reserve(n);
  for (int i = 1; i <= n; ++i) {
    if (!cnt[i] || i == mode) continue;
    // if (cnt[i] >= B) res = max(res, force_solve(mode, i));
    // else {
    s.clear();
    int Mx = -1000000000, cnt = 0;
    for (auto it = pos[i].rbegin(); it != pos[i].rend(); ++it) {
      int p = *it;
      Mx = max(Mx, sm[n] - sm[p] - cnt);
      ++cnt;
      llen[p] = -(sm[n] - sm[p] - cnt - Mx);
    }
    Mx = -1000000000; cnt = 0;
    for (auto it = pos[i].begin(); it != pos[i].end(); ++it) {
      int p = *it;
      Mx = max(Mx, sm[p] - cnt);
      ++cnt;
      int rlen = -(sm[p] - cnt - Mx);
      rs.clear();
      int q, c;
      for (q = p, c = 0; L[q] && c <= llen[p] && a[L[q]] == mode && (s.empty() || L[q] > s.back()); ++c, q = L[q], rs.push_back(q));
      // notice one more on left    ^
      for (auto it = rs.rbegin(); it != rs.rend(); ++it) s.push_back(*it);
      s.push_back(p);
      int Next = next(it) == pos[i].end() ? n + 1 : *next(it);
      for (q = R[p], c = 0; q != n + 1 && c < rlen && a[q] == mode && q < Next; q = R[q], ++c) s.push_back(q);
    }
    res = max(res, solve(s));
    // }
  }
  printf("%d\n", res);
  return 0;
}