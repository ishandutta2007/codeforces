#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1 << 20;
const ll inf = 1LL << 60;

ll seg[2 * MAXN];
ll lazy[2 * MAXN];

ll xv[MAXN];
ll yv[MAXN];

pair<int, pair<int, int> > mv[MAXN];

void down(int cur) {
  int cl = cur * 2, cr = cur * 2 + 1;
  lazy[cl] += lazy[cur];
  seg[cl] += lazy[cur];
  lazy[cr] += lazy[cur];
  seg[cr] += lazy[cur];
  lazy[cur] = 0;
}

void build(int cur = 1, int l = 0, int r = MAXN) {
  int cl = cur * 2, cr = cur * 2 + 1;
  if (l + 1 == r) {
    seg[cur] = yv[l];
  } else {
    int mid = (l + r) / 2;
    build(cl, l, mid);
    build(cr, mid, r);
    seg[cur] = min(seg[cl], seg[cr]);
  }
}

void add(int left, int right, int val, int cur = 1, int l = 0, int r = MAXN) {
  int cl = cur * 2, cr = cur * 2 + 1;
  if (left <= l && r <= right) {
    lazy[cur] += val;
    seg[cur] += val;
  } else if (left >= r || l >= right) {
    return;
  } else {
    int mid = (l + r) / 2;
    add(left, right, val, cl, l, mid);
    add(left, right, val, cr, mid, r);
    down(cur);
    seg[cur] = min(seg[cl], seg[cr]);
  }
}

int query() {
  return seg[1];
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m, p;
  cin >> n >> m >> p;
  for (int i = 0; i < MAXN; ++i) {
    xv[i] = yv[i] = inf;
  }

  for (int i = 0; i < n; ++i) {
    ll x, v;
    cin >> x >> v;
    xv[x] = min(xv[x], v);
  }
  for (int i = 0; i < m; ++i) {
    ll y, v;
    cin >> y >> v;
    yv[y] = min(yv[y], v);
  }
  for (int i = 0; i < p; ++i) {
    cin >> mv[i].first >> mv[i].second.first >> mv[i].second.second;
  }
  sort(mv, mv + p);

  for (int i = MAXN - 1; i > 0; --i) {
    yv[i - 1] = min(yv[i - 1], yv[i]);
    xv[i - 1] = min(xv[i - 1], xv[i]);
  }

  build();
  ll ans = query() + xv[0];
  for (int i = 0; i < p; ++i) {
    int x = mv[i].first, y = mv[i].second.first, z = mv[i].second.second;
    add(y + 1, MAXN, -z);
    ll q = query() + xv[x + 1];
    ans = min(ans, q);
  }
  ans *= -1;
  cout << ans << "\n";
}