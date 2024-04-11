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

typedef long long ll;

const int N = 1e6 + 5;

int n, m;
ll s[N];

void yhjssa() {
  ll x;
  read(n); read(m);
  for (int i = 1; i <= n; i++) {
  	s[i] = 0;
  	for (int j = 1; j <= m; j++) read(x), s[i] += x * j;
  }
  for (int i = 1; i <= n; i++) {
  	int x1 = i == 1 ? 2 : 1, x2 = i <= 2 ? 3 : 2;
  	if (s[x1] == s[x2] && s[i] != s[x1]) {
  	  printf("%d %lld\n", i, s[i] - s[x1]);
  	  return;
	}
  }
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}