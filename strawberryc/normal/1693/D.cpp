#include <bits/stdc++.h>
#define p2 p << 1
#define p3 p << 1 | 1

template <class T>
inline void read(T &res) {
  res = 0; bool bo = 0; char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-');
  if (c == '-') bo = 1; else res = c - 48;
  while ((c = getchar()) >= '0' && c <= '9')
    res = (res << 3) + (res << 1) + (c - 48);
  if (bo) res = ~res + 1;
}

typedef long long ll;

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 2e5 + 5, M = N << 2;

int n, p[N], bi[N], sm[N], top, stk[N], inc[N], dec[N], T[M],
fi[N], fd[N];
ll ans;

void change(int l, int r, int pos, int v, int p) {
  if (l == r) return (void) (T[p] = v);
  int mid = l + r >> 1;
  if (pos <= mid) change(l, mid, pos, v, p2);
  else change(mid + 1, r, pos, v, p3);
  T[p] = Max(T[p2], T[p3]);
}

int ask(int l, int r, int s, int e, int p) {
  if (e < l || s > r) return 0;
  if (s <= l && r <= e) return T[p];
  int mid = l + r >> 1;
  return Max(ask(l, mid, s, e, p2), ask(mid + 1, r, s, e, p3));
}

int main() {
  read(n);
  for (int i = 1; i <= n; i++) read(p[i]);
  stk[top = 0] = n + 1;
  for (int i = n; i >= 1; i--) {
  	inc[i] = i < n && p[i] < p[i + 1] ? inc[i + 1] : i;
  	dec[i] = i < n && p[i] > p[i + 1] ? dec[i + 1] : i;
  	while (top && p[i] > p[stk[top]]) top--;
  	bi[i] = stk[top]; stk[++top] = i;
  }
  stk[top = 0] = n + 1;
  for (int i = n; i >= 1; i--) {
  	while (top && p[i] < p[stk[top]]) top--;
  	sm[i] = stk[top]; stk[++top] = i;
  }
  fi[n] = fd[n] = n;
  for (int i = n - 1; i >= 1; i--)
    if (p[i] < p[i + 1]) {
      fd[i] = inc[i] + 1 == sm[i] ? fi[inc[i]] : inc[i];
      fi[i] = fi[i + 1]; int wx = 0;
      if (dec[i + 1] < n && p[dec[i + 1] + 1] > p[i]) {
      	int tf = fd[dec[i + 1]];
      	fi[i] = Max(fi[i], tf); wx = Max(wx, tf);
	  }
	  if (dec[i + 1] == n) fi[i] = wx = n;
	  int tx = Min(dec[i + 1], sm[i] - 1);
	  if (tx > i + 1) {
	  	int tf = ask(1, n, i + 1, tx - 1, 1);
	  	fi[i] = Max(fi[i], tf); wx = Max(wx, tf);
	  }
	  change(1, n, i, wx, 1);
	}
	else {
	  fi[i] = dec[i] + 1 == bi[i] ? fd[dec[i]] : dec[i];
	  fd[i] = fd[i + 1]; int wx = 0;
	  if (inc[i + 1] < n && p[inc[i + 1] + 1] < p[i]) {
	  	int tf = fi[inc[i + 1]];
	  	fd[i] = Max(fd[i], tf); wx = Max(wx, tf);
	  }
	  if (inc[i + 1] == n) fd[i] = wx = n;
	  int tx = Min(inc[i + 1], bi[i] - 1);
	  if (tx > i + 1) {
	  	int tf = ask(1, n, i + 1, tx - 1, 1);
	  	fd[i] = Max(fd[i], tf); wx = Max(wx, tf);
	  }
	  change(1, n, i, wx, 1);
	}
  for (int i = 1; i <= n; i++) ans += Max(fi[i], fd[i]) - i + 1;
  return std::cout << ans << std::endl, 0;
}