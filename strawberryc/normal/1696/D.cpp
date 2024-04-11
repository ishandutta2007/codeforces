#include <bits/stdc++.h>

template <class T>
inline void read(T &res) {
  res = 0; bool bo = 0; char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-');
  if (c == '-') bo = 1; else res = c - 48;
  while ((c = getchar()) >= '0' && c <= '9')
    res = (res << 3) + (res << 1) + (c - 48);
  if (bo) res = ~res + 1;
}

const int N = 292451;

int n, a[N], mi[N], mx[N], top, stk[N], mip[N], mxp[N];

void yhjssa() {
  read(n);
  for (int i = 1; i <= n; i++) read(a[i]);
  mip[n] = mxp[n] = n;
  for (int i = n - 1; i >= 1; i--)
    mip[i] = a[i] < a[mip[i + 1]] ? i : mip[i + 1],
    mxp[i] = a[i] > a[mxp[i + 1]] ? i : mxp[i + 1];
  stk[top = 0] = n + 1;
  for (int i = n; i >= 1; i--) {
  	while (top && a[i] < a[stk[top]]) top--;
  	mi[i] = stk[top]; stk[++top] = i;
  }
  stk[top = 0] = n + 1;
  for (int i = n; i >= 1; i--) {
  	while (top && a[i] > a[stk[top]]) top--;
  	mx[i] = stk[top]; stk[++top] = i;
  }
  int ans = 0;
  for (int x = 1; x < n;) {
  	ans++;
  	if (a[x] < a[x + 1]) {
  	  int y = mi[x] - 1, z = y;
  	  if (y == n) z = mxp[x + 1];
  	  else for (int i = y; i > x; i--)
  	    if (a[i] > a[z]) z = i;
  	  x = z;
	}
	else {
	  int y = mx[x] - 1, z = y;
	  if (y == n) z = mip[x + 1];
	  else for (int i = y; i > x; i--)
	    if (a[i] < a[z]) z = i;
	  x = z;
	}
  }
  printf("%d\n", ans);
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}