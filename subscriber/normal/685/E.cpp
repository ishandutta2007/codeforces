#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
const int M = 200010;

typedef bitset<N> bs;

bs a[N];
bs mem[M];
int u[M], v[M];
int l[M], r[M], s[M], t[M];
bool ans[M], solved[M];
vector <int> qs[M], qf[M];

void solve(int from, int to) {
  int mid = (from + to) >> 1;
  for (int j = mid; j >= from; j--) {
    a[u[j]] |= a[v[j]];
    a[v[j]] = a[u[j]];
    for (int q : qs[j]) {
      if (!solved[q] && (mid <= r[q] && r[q] <= to)) {
        mem[q] = a[s[q]];
      }
    }
  }
  for (int j = mid; j >= from; j--) {
    a[u[j]].reset();
    a[u[j]].set(u[j]);
    a[v[j]].reset();
    a[v[j]].set(v[j]);
  }
  for (int j = mid; j <= to; j++) {
    for (int q : qf[j]) {
      if (!solved[q] && (from <= l[q] && l[q] <= mid)) {
        ans[q] = ((mem[q] & a[t[q]]).count() > 0);
        solved[q] = true;
      }
    }
    if (j < to) {
      a[u[j + 1]] |= a[v[j + 1]];
      a[v[j + 1]] = a[u[j + 1]];
    }
  }
  for (int j = mid + 1; j <= to; j++) {
    a[u[j]].reset();
    a[u[j]].set(u[j]);
    a[v[j]].reset();
    a[v[j]].set(v[j]);
  }
  if (from < to) {
    solve(from, mid);
    solve(mid + 1, to);
  }
}

int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", u + i, v + i);
    u[i]--; v[i]--;
  }
  for (int i = 0; i < q; i++) {
    scanf("%d %d %d %d", l + i, r + i, s + i, t + i);
    l[i]--; r[i]--; s[i]--; t[i]--;
    qs[l[i]].push_back(i);
    qf[r[i]].push_back(i);
    ans[i] = false;
    solved[i] = false;
  }
  for (int i = 0; i < n; i++) {
    a[i].set(i);
  }
  solve(0, m - 1);
  for (int i = 0; i < q; i++) {
    puts(ans[i] ? "Yes" : "No");
  }
  return 0;
}