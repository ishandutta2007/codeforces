#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e7;

int x[N], sum[N], lft[N];
int numV = 0;

inline int nw() {  
  lft[numV] = sum[numV] = x[numV] = -1;  
  return numV++;
}

inline void setSeg(int v, int L, int R, int l, int r, int xx) {    
  if (L >= r || l >= R) return;
  if (L <= l && r <= R) {
    x[v] = xx;
    sum[v] = (r - l) * xx;
    return;
  }
  int m = (l + r) / 2;
  if (lft[v] == -1) {
    lft[v] = nw();
    nw();
  }

  if (x[v] != -1) {      
    x[lft[v]] = x[v];
    x[lft[v] + 1] = x[v];
    sum[lft[v]] = x[v] * (m - l);
    sum[lft[v] + 1] = x[v] * (r - m);
    x[v] = -1;
  }

  setSeg(lft[v], L, R, l, m, xx);
  setSeg(lft[v] + 1, L, R, m, r, xx);

  sum[v] = sum[lft[v]] + sum[lft[v] + 1];
}

inline int read() {
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  int x = 0;
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}

void solve() {
  int n, q;
  n = read();
  q = read();
  int root = nw();
  x[root] = 1;
  sum[root] = n;

  while (q--) {
    int t, l, r;
    l = read();
    r = read();
    t = read();  
    setSeg(root, l - 1, r, 0, n, t - 1);
    cout << sum[root] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;  

#ifdef SERT
  t = 1;
#endif

  for (int i = 0; i < t; i++)
    solve();
}