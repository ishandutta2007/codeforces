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

int n;

int main() {
  int T; read(T);
  while (T--) {
  	read(n);
  	bool ans = 0;
  	int x;
  	while (n--) read(x), ans ^= (x & 1) ^ 1;
  	puts(ans ? "errorgorn" : "maomao90");
  }
  return 0;
}