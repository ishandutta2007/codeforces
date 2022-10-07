#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1 << 17;
int lazy[MAXN * 2]; // 0 = nil, 1 = flip, 2 = set(1), 3 = set(-1)

int compose(int a, int b) {
  if (a == 0) return b;
  if (a == 1) {
    return b ^ 1; // oh this is kinda neat
  }
  return a;
}

void down(int cur) {
  int cl = cur * 2, cr = cur * 2 + 1;
  if (cr > 2 * MAXN) cout << "fuck\n";
  lazy[cl] = compose(lazy[cur], lazy[cl]);
  lazy[cr] = compose(lazy[cur], lazy[cr]);
  lazy[cur] = 0;
}

void go(int l, int r, int v, int cur = 1, int left = 0, int right = MAXN) {
  if (right <= l || r <= left) return;
  // printf("go %d %d %d [%d %d %d]\n", l, r, v, cur, left, right);
  int cl = cur * 2, cr = cur * 2 + 1;

  if (l <= left && right <= r) {
    if (cur > 2 * MAXN) cout << l << r << v << cur << left << right << "fuck\n";
    lazy[cur] = compose(v, lazy[cur]);
  } else {
    down(cur);
    int mid = (left + right) / 2;
    go(l, r, v, cl, left, mid);
    go(l, r, v, cr, mid, right);
  }
}

int ar[MAXN];
int main() {
  ios_base::sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  for(int i = 0; i < n; ++i) {
    cin >> ar[i];
  }
  for(int i = 0; i < q; ++i) {
    string s;
    int x;
    cin >> s >> x;
    if (s == "<") {
      if (x < 0) {
        go(-x + 1, MAXN, 2); // [-x + 1, infty): sign = 1
      } else {
        go(x, MAXN, 2); // [x, infty): sign = 1
        go(0, x, 1);
      }
    } else {
      if (x > 0) {
        go(x + 1, MAXN, 3); // [x + 1, infty): sign = -1
      } else {
        go(-x, MAXN, 3); // [-x, infty): sign = -1
        go(0, -x, 1);
      }
    }


    // for(int i = 1; i < 2 * MAXN; ++i) {
      // cout << i << "|" << lazy[i] << "\n";
    // }
  }

  for(int i = 1; i < MAXN;++i) {
    down(i);
  }
  for(int i = 0; i < n; ++i) {
    int v = ar[i];
    // cout << v << "/";
    int x = abs(v);
    int l = lazy[MAXN + x];
    // cout << l << "|";
    if (l == 1) v = -v;
    else if (l == 2) v = x;
    else if (l == 3) v = -x;
    cout << v << " ";
  }
  cout << "\n";
}