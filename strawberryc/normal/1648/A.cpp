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

const int N = 1e5 + 5;

int n, m, L = 100000;
ll ans;
std::vector<int> vx[N], vy[N];

int main() {
  int c;
  read(n); read(m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      read(c), vx[c].push_back(i), vy[c].push_back(j);
  for (int i = 1; i <= L; i++) {
  	std::sort(vx[i].begin(), vx[i].end());
  	std::sort(vy[i].begin(), vy[i].end());
  	int l = vx[i].size(); ll cur = 0;
  	for (int j = 0; j < l; j++)
  	  ans += 1ll * vx[i][j] * j - cur, cur += vx[i][j];
  	cur = 0;
  	for (int j = 0; j < l; j++)
  	  ans += 1ll * vy[i][j] * j - cur, cur += vy[i][j];
  }
  return std::cout << ans << std::endl, 0;
}