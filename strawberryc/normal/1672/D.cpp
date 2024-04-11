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

const int N = 2e5 + 5;

int n, a[N], b[N], orz[N], tot, seq[N], rk[N];

int main() {
  int T; read(T);
  while (T--) {
  	read(n);
  	for (int i = 1; i <= n; i++) read(a[i]);
  	for (int i = 1; i <= n; i++) read(b[i]), orz[i] = 0;
  	tot = 0;
  	for (int i = 1; i <= n; i++) {
  	  orz[b[i]]++;
  	  if (i == n || b[i] != b[i + 1])
  	    seq[++tot] = b[i], rk[tot] = orz[b[i]];
	}
	for (int i = 1; i <= n; i++) orz[i] = 0;
	bool is = 1;
	for (int i = 1, ql = 0; i <= tot; i++) {
	  ql++;
	  while (114 + 514 < 1919 + 810) {
	  	orz[a[ql]]++;
	  	if (seq[i] == a[ql] && orz[a[ql]] >= rk[i]) break;
	  	if ((++ql) > n) break;
	  }
	  if (ql > n) {is = 0; break;}
	}
	puts(is ? "yes" : "no");
  }
  return 0;
}