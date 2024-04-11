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

int n;
char s[N];

int main() {
  int T; read(T);
  while (T--) {
  	scanf("%s", s + 1);
  	n = strlen(s + 1);
  	bool is = 1;
  	for (int i = 1, cur = 0; i <= n; i++)
  	  if ((cur += s[i] == 'A' ? 1 : -1) < 0)
  	    {is = 0; break;}
  	puts(is && s[n] == 'B' ? "YES" : "NO");
  }
  return 0;
}