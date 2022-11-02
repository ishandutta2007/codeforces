#include <bits/stdc++.h>

constexpr int max_N = 200000 + 21;

using LL = long long;
using PII = std::pair<int, int>;
using PIPII = std::pair<int, PII>;

int n, q, a[max_N], ql, qr, qa;

LL sum[max_N * 4];

PII tag[max_N * 4];

#define ls(x) ((x) << 1)
#define rs(x) (ls(x) | 1)
#define mid ((l + r) >> 1)
#define lch ls(x), l, mid
#define rch rs(x), mid + 1, r

void update(int x) {
  sum[x] = sum[ls(x)] + sum[rs(x)];
}

void build(int x = 1, int l = 1, int r = n) {
  if (l == r) {
    sum[x] = a[l];
  } else {
    build(lch);
    build(rch);
    update(x);
  }
}

void change(int x, int l, int r, int a) {
  sum[x] = 1LL * (r - l + 1) * a;
  tag[x] = {true, a};
}

void down(int x, int l, int r) {
  if (tag[x].first) {
    change(lch, tag[x].second);
    change(rch, tag[x].second);
    tag[x] = {};
  }
}

void modify(int x = 1, int l = 1, int r = n) {
  if (ql <= l && r <= qr) {
    change(x, l, r, qa);
  } else {
    down(x, l, r);
    if (ql <= mid) {
      modify(lch);
    }
    if (qr > mid) {
      modify(rch);
    }
    update(x);
  }
}

LL query(int x = 1, int l = 1, int r = n) {
  if (ql > qr) {
    return 0;
  }
  if (ql <= l && r <= qr) {
    return sum[x];
  } else {
    down(x, l, r);
    LL ret = 0;
    if (ql <= mid) {
      ret += query(lch);
    }
    if (qr > mid) {
      ret += query(rch);
    }
    return ret;
  }
}

std::set<PIPII> set;

void InsertToSet(PIPII x) {
  auto it = set.lower_bound({x.first, {INT_MIN, INT_MIN}});
  if (it != set.end() && it->first == x.first) {
    x.second.first = std::min(x.second.first, it->second.first);
    x.second.second = std::max(x.second.second, it->second.second);
    set.erase(it);
  }
  set.insert(x);
}

void Opt1(int x, int y) {
  auto it = set.lower_bound({-y, {INT_MIN, INT_MIN}});
  if (it == set.end() || it->second.first > x) {
    return;
  }
  int pos = it->second.first;
  while (it != set.end() && it->second.first <= x) {
    if (it->second.second > x) {
      PIPII tmp{it->first, {x + 1, it->second.second}};
      it = set.erase(it);
      InsertToSet(tmp);
      break;
    }
    it = set.erase(it);
  }
  PIPII nseg{-y, {pos, x}};
  InsertToSet(nseg);
  ql = pos, qr = x, qa = y;
  modify();
}

void Buy(int* start, LL* cur) {
  ql = 1, qr = *start - 1;
  LL pre = query();
  if (*cur >= sum[1] - pre) {
    *start = n + 1;
    *cur -= sum[1] - pre;
    return;
  }
  *cur += pre;
  int x = 1, l = 1, r = n;
  while (l < r) {
    down(x, l, r);
    if (sum[ls(x)] > *cur) {
      x = ls(x);
      r = mid;
    } else {
      *cur -= sum[ls(x)];
      x = rs(x);
      l = mid + 1;
    }
  }
  *start = l;
}

void Opt2(int x, LL y) {
  int ans = 0;
  int start = x;
  while (start <= n) {
    int next = start;
    Buy(&next, &y);
    ans += next - start;
    if (next < n) {
      auto it = set.lower_bound({-y, {INT_MIN, INT_MIN}});
      if (it == set.end() || it->second.second <= next) {
        break;
      }
      start = std::max(it->second.first, next);
    } else {
      break;
    }
  }
  printf("%d\n", ans);
}

void DebugSet() {
  for (const auto& item : set) {
    printf("%d %d %d\n", -item.first, item.second.first, item.second.second);
  }
  puts("");
}

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    InsertToSet({-a[i], {i, i}});
  }
//  DebugSet();
  build();
  while (q--) {
    int t, x, y;
    scanf("%d%d%d", &t, &x, &y);
    if (t == 1) {
      Opt1(x, y);
    } else {
      Opt2(x, y);
    }
//    DebugSet();
  }
}