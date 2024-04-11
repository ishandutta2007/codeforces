#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

const int MAXN = 1 << 17;
const int SIZE = 1 << 18;

using namespace std;

typedef pair<int, int> pii;
typedef priority_queue<pii> Q;
typedef long long ll;

Q SEG[SIZE];
int ar[MAXN];
ll BIT[MAXN];

ll ask(int idx) {
  ll ret = 0;
  while (idx) {
    ret += BIT[idx];
    idx -= idx & -idx;
  }
  return ret;
}

void inc(int idx, int val) {
  while (idx < MAXN) {
    BIT[idx] += val;
    idx += idx & -idx;
  }
}

void change(int x, int val) {
  int diff = val - ar[x];
  ar[x] = val;
  inc(x, diff);
}

void insert(int x, int cur = 1, int l = 0, int r = MAXN) {
  SEG[cur].push(pii(ar[x], x));
  if (l + 1 == r) {
    return;
  } else {
    int mid = (l + r) / 2;
    if (x < mid) {
      insert(x, cur*2, l, mid);
    } else {
      insert(x, cur*2+1, mid, r);
    }
  }
}

void upd(int left, int right, int mod, int cur = 1, int l = 0, int r = MAXN) {
  if (left <= l && r <= right) {
    Q &q = SEG[cur];
    while (!q.empty()) {
      pii p = q.top(); q.pop();
      int x = p.second;

      change(x, ar[x] % mod);
      q.push(pii(ar[x], x));
      if (p.first < mod) break;
    }
  } else if (left >= r || l >= right) {
    return;
  } else {
    int mid = (l + r) / 2;
    upd(left, right, mod, cur*2, l, mid);
    upd(left, right, mod, cur*2+1, mid, r);
  }
}

int N, M;

int main() {
  ios_base::sync_with_stdio(0);
  scanf("%d %d", &N, &M);
  for(int i = 1; i <= N; ++i) {
    int nxt;
    scanf("%d", &nxt);
    change(i, nxt);
    insert(i);
  }

  for(int i = 0; i < M; ++i) {
    int qtype;
    scanf("%d", &qtype);
    if (qtype == 1) {
      int l, r;
      scanf("%d %d", &l, &r);
      ll ans = ask(r) - ask(l - 1);
      cout << ans << "\n";
    } else if (qtype == 2) {
      int l, r, x;
      scanf("%d %d %d", &l, &r, &x);
      upd(l, r + 1, x);
    } else {
      int k, x;
      scanf("%d %d", &k, &x);
      change(k, x);
      insert(k);
    }

  }
  return 0;
}