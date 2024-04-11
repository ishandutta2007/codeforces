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

const int N = 505;

int n, m;
char s[N][N];

void work() {
  read(n); read(m);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  for (int i = 1; i <= m; i++) s[1][i] = 'X';
  for (int i = 2; i <= n; i += 3) {
  	for (int j = 1; j <= m; j++) s[i + 2][j] = 'X';
  	int id1 = -1, id2 = -1;
  	for (int j = 1; j <= m; j++) {
  	  if (s[i][j] == 'X') id1 = j;
  	  if (s[i + 1][j] == 'X') id2 = j;
	}
	if (id1 == -1 && id2 == -1) s[i][1] = s[i + 1][1] = 'X';
	else if (id1 != -1) s[i + 1][id1] = 'X';
	else s[i][id2] = 'X';
  }
  if (n % 3 == 0) {
  	bool is1 = 0, is2 = 0;
  	for (int i = 1; i <= m; i++) {
  	  if (s[n - 1][i] == 'X') is1 = 1;
  	  if (s[n][i] == 'X') is2 = 1;
	}
	if (!is1) {
	  for (int i = 1; i <= m; i++) s[n][i] = 'X';
	  s[n - 1][1] = 'X';
	}
	else {
	  int fis;
	  for (int i = 1; i <= m; i++)
	    if (s[n - 1][i] == 'X') {fis = i; break;}
	  for (int i = 1; i < fis; i++) s[n][i] = 'X';
	  for (int i = fis; i <= m; i++)
	    if (s[n - 1][i + 1] != 'X') s[n][i] = 'X';
	}
  }
  for (int i = 1; i <= n; i++) {
  	for (int j = 1; j <= m; j++) putchar(s[i][j]);
  	puts("");
  }
}

int main() {
  int T; read(T);
  while (T--) work();
  return 0;
}