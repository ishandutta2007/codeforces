#undef NDEBUG

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <sstream>
#include <typeinfo>
#include <limits>
#include <unordered_map>

using namespace std;

const int kMaxN = 1e6;
const int kInf = 1e9;

struct Query {
  int l, r, idx, answer;
};

bool CmpLf(const Query& o1, const Query& o2) {
  return o1.l < o2.l;
}

bool CmpIdx(const Query& o1, const Query& o2) {
  return o1.idx < o2.idx;
}

int t[4 * kMaxN];

void Upd(int pos, int val, int v, int l, int r) {
  if (l == r) {
    t[v] = val;
    return;
  }
  int mid = (l + r) >> 1;
  if (pos <= mid)
    Upd(pos, val, 2 * v + 1, l, mid);
  else
    Upd(pos, val, 2 * v + 2, mid + 1, r);
  t[v] = min(t[2 * v + 1], t[2 * v + 2]);
}

int GetMin(int l, int r, int v, int tl, int tr) {
  if (l == tl && r == tr) {
    return t[v];
  }
  int ans = kInf, mid = (tl + tr) >> 1;
  if (l <= mid)
    ans = min(ans, GetMin(l, min(r, mid), 2 * v + 1, tl, mid));
  if (r >= mid + 1)
    ans = min(ans, GetMin(max(l, mid + 1), r, 2 * v + 2, mid + 1, tr));
  return ans;
}

int main() {
#ifdef ssu1
  assert(freopen("input.txt", "rt", stdin));
#endif

  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> a(n); 
  unordered_map<int, int> idx(n);
  for (int& ai : a) {
    scanf("%d", &ai);
    if (idx.count(ai) == 0) {
      int newid = idx.size();
      idx[ai] = newid;
    }
    ai = idx[ai];
  }

  vector<int> pos(kMaxN, -1), dist_to_prev(n, kInf), next(n, -1);
  for (int i = 0; i < n; ++i) {
    if (pos[a[i]] != -1) {
      dist_to_prev[i] = i - pos[a[i]];
      next[pos[a[i]]] = i;
    }
    pos[a[i]] = i;
  }

  for (int i = 0; i < n; ++i)
    Upd(i, dist_to_prev[i], 0, 0, n - 1);

  vector<Query> qs(m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &qs[i].l, &qs[i].r);
    qs[i].l--, qs[i].r--;
    qs[i].idx = i;
  }

  sort(qs.begin(), qs.end(), CmpLf);

  int iter = 0;
  for (int left = 0; left < n; ++left) {
    while (iter < qs.size() && qs[iter].l == left) {
      qs[iter].answer = GetMin(qs[iter].l, qs[iter].r, 0, 0, n - 1);
      iter++;
    }
    if (next[left] != -1) {
      Upd(next[left], kInf, 0, 0, n - 1);
    }
  }

  sort(qs.begin(), qs.end(), CmpIdx);

  for (Query q : qs) {
    if (q.answer == kInf)
      q.answer = -1;
    printf("%d\n", q.answer);
  }

#ifdef ssu1
  cerr << "\nTime = " << ((double)clock()) / CLOCKS_PER_SEC << endl;
#endif    
  return 0;
}