#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1 << 19;

int seg[2 * MAXN];
int lazy[2 * MAXN];
void down(int cur) {
  int cl = cur * 2, cr = cur * 2 + 1;
  lazy[cl] += lazy[cur];
  seg[cl] += lazy[cur];
  lazy[cr] += lazy[cur];
  seg[cr] += lazy[cur];
  lazy[cur] = 0;
}

void inc(int left, int right, int val, int cur = 1, int l = 0, int r = MAXN) {
  int mid = (l + r) / 2, cl = cur * 2, cr = cur * 2 + 1;
  if (left <= l && r <= right) {
    lazy[cur] += val;
    seg[cur] += val;
  } else if (left >= r || l >= right) {
  } else {
    down(cur);
    inc(left, right, val, cl, l, mid);
    inc(left, right, val, cr, mid, r);
    seg[cur] = max(seg[cl], seg[cr]);
  }
}

int query() {
  return seg[1];
}

int P[MAXN];
int Q[MAXN];

int pos[MAXN]; // P[pos[i]] = i
int larger[MAXN]; // larger[p[i]]: number of j > i s.t. p[j] > p[i]
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  int n;
  cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> P[i];
    pos[P[i]] = i;
  }
  for(int i = 0; i < n; ++i) {
    cin >> Q[i];
  }

  int ans = n;
  inc(0, pos[ans], 1);
  for(int i = 0; i < n; ++i) {
    while (query() <= 0) {
      --ans;
      inc(0, pos[ans], 1);
    }
    inc(0, Q[i], -1);
    cout << ans << " ";
  }
  cout << "\n";
}