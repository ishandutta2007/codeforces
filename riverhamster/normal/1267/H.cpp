#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <set>
using namespace std;

#define LOG(f...) fprintf(stderr, f)

using ll = long long;

template<class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template<class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

template<class CRIter, class RIter>
void cons_4(CRIter l, CRIter r, RIter res, int start) {
  static int a[4];
  iota(a, a + (r - l), 0);
  sort(a, a + (r - l), [&](int a, int b) { return l[a] < l[b]; });
  fill_n(res, r - l, 0);
  for (int i = 0, li = min<int>(r - l, 3); i < li; ++i)
    res[a[i]] = i + start;
  if (r - l == 4) {
    bool vis[3] = {false, false, false};
    int p = a[3];
    if (p != 0 && res[p - 1])
      vis[res[p - 1] - start] = true;
    if (p + 1 != r - l && res[p + 1])
      vis[res[p + 1] - start] = true;
    for (int j = 0; j < 3; ++j)
      if (!vis[j]) {
        res[p] = j + start;
        break;
      }
  }
}

vector<int> cons(const vector<int> &a, int start = 22) {
  if (a.size() <= 4) {
    vector<int> res(a.size());
    cons_4(a.begin(), a.end(), res.begin(), start);
    return res;
  }
  int n = a.size();
  vector<int> b((n + 2) / 3);
  vector<bool> ismn(n);
  for (size_t i = 0; i != b.size(); ++i) {
    int pos = min_element(a.begin() + 3 * i, a.begin() + min(a.size(), 3 * i + 3)) - a.begin();
    b[i] = a[pos];
    ismn[pos] = true;
  }
  vector<int> c = cons(b, start - 3);
  vector<int> res(n), nmin(n);
  iota(nmin.begin(), nmin.end(), 0);
  auto cpos = c.begin();
  for (int i = 0; i < n; ++i)
    if (ismn[i]) res[i] = *(cpos++);
  sort(nmin.begin(), nmin.end(), [&](int x, int y) { return a[x] < a[y]; });
  set<int> s;
  for (int p : nmin) {
    auto it = s.insert(p).first;
    if (ismn[p]) continue;
    bool vis[3] = {false, false, false};
    int cnt[3] = {0, 0, 0};
    if (it != s.begin() && !ismn[*prev(it)])
      vis[res[*prev(it)] - start] = true;
    if (next(it) != s.end() && !ismn[*next(it)])
      vis[res[*next(it)] - start] = true;
    auto i = it;
    while (true) {
      if (i == s.begin()) break;
      --i;
      if (ismn[*i]) break;
      ++cnt[res[*i] - start];
    }
    i = it;
    while (true) {
      ++i;
      if (i == s.end() || ismn[*i]) break;
      ++cnt[res[*i] - start];
    }
    bool flag = find(cnt, cnt + 3, 2) != cnt + 3;
    for (int i = 0; i < 3; ++i)
      if (!vis[i] && !(flag && cnt[i])) {
        res[p] = i + start;
        break;
      }
  }
  return res;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  read(T);
  while (T--) {
    int n;
    read(n);
    vector<int> a(n);
    for (int i = 0, x; i < n; ++i) {
      read(x);
      a[x - 1] = i;
    }
    for (int x : cons(a))
      printf("%d ", x);
    putchar('\n');
  }
  return 0;
}