#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

struct info_t {
  int i, yl, yr, zl, zr;

  info_t() {
  }

  info_t(int i, int yl, int yr, int zl, int zr):i(i), yl(yl), yr(yr), zl(zl), zr(zr) {
  }

  bool operator < (const info_t &b) const {
    return yl < b.yl || (yl == b.yl && abs(i) < abs(b.i));
  }
};

int n, m, q, total, l[3], r[3], limit[3], sum[N], fenw[N];
vector<pair<int, int>> adj[N];
vector<info_t> queries[N];
bool answer[N];

void modify(int x) {
  for (; x <= limit[2]; x += x & -x) {
    ++fenw[x];
  }
}

void clear(int x) {
  for (; x <= limit[2]; x += x & -x) {
    fenw[x] = 0;
  }
}

int query(int x) {
  int answer = 0;
  for (; x; x -= x & -x) {
    answer += fenw[x];
  }
  return answer;
}

void solve(int l, int r) {
  if (l > r) {
    return;
  }
  int mid = l + r >> 1;
  vector<info_t> info;
  for (int i = l; i <= mid; ++i) {
    for (auto p : adj[i]) {
      info.push_back(info_t(0, p.first, p.first, p.second, p.second));
    }
  }
  for (int i = mid; i <= r; ++i) {
    for (auto p : queries[i]) {
      info.push_back(info_t(-p.i, p.yl - 1, p.yl - 1, p.zl, p.zr));
      info.push_back(info_t(p.i, p.yr, p.yr, p.zl, p.zr));
    }
  }
  sort(info.begin(), info.end());
  for (auto e : info) {
    if (!e.i) {
      modify(e.zl);
    } else if (e.i > 0) {
      sum[e.i] += query(e.zr) - query(e.zl - 1);
    } else {
      sum[-e.i] -= query(e.zr) - query(e.zl - 1);
    }
  }
  for (auto e : info) {
    if (!e.i) {
      clear(e.zl);
    }
  }
  solve(l, mid - 1);
  solve(mid + 1, r);
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  for (int i = 0; i < 3; ++i) {
    scanf("%d", &limit[i]);
    l[i] = limit[i];
  }
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 3; ++j) {
      int x;
      scanf("%d", &x);
      l[j] = min(l[j], x);
      r[j] = max(r[j], x);
    }
  }
  for (int i = 1; i <= m; ++i) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    if (x >= l[0] && x <= r[0] && y >= l[1] && y <= r[1] && z >= l[2] && z <= r[2]) {
      puts("INCORRECT");
      return 0;
    }
    adj[x].push_back(make_pair(y, z));
  }
  puts("CORRECT");
  for (int i = 1; i <= q; ++i) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    if (x >= l[0] && x <= r[0] && y >= l[1] && y <= r[1] && z >= l[2] && z <= r[2]) {
      answer[i] = true;
    } else {
      int lx = l[0], rx = r[0], ly = l[1], ry = r[1], lz = l[2], rz = r[2];
      lx = min(lx, x);
      ly = min(ly, y);
      lz = min(lz, z);
      rx = max(rx, x);
      ry = max(ry, y);
      rz = max(rz, z);
      queries[lx - 1].push_back(info_t(-i, ly, ry, lz, rz));
      queries[rx].push_back(info_t(i, ly, ry, lz, rz));
    }
  }
  solve(1, limit[0]);
  for (int i = 1; i <= q; ++i) {
    if (answer[i]) {
      puts("OPEN");
    } else if (sum[i]) {
      puts("CLOSED");
    } else {
      puts("UNKNOWN");
    }
  }
  return 0;
}