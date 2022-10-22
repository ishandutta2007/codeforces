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

const int N = 2e6 + 5;

int n, maxA, minA = 1145141919, le[N], ri[N];
bool vis[N];

int main() {
  int x;
  read(n);
  for (int i = 1; i <= n; i++) {
  	read(x); vis[x] = 1;
  	if (x > maxA) maxA = x;
  	if (x < minA) minA = x;
  }
  le[0] = 0; ri[maxA + 1] = maxA + 1;
  for (int i = 1; i <= maxA; i++) le[i] = vis[i] ? i : le[i - 1];
  for (int i = maxA; i >= 1; i--) ri[i] = vis[i] ? i : ri[i + 1];
  for (int len = 2; ; len++) {
  	int L = 1, R = len;
  	bool wd = 0;
  	for (int i = minA - len + 1, li = len; i <= maxA; i += li * 2 - 1, li++) {
  	  int l = i, r = i + (li - 1) * 2;
  	  if (l < 1) l = 1; if (r > maxA) r = maxA;
  	  int lx = ri[l], rx = le[r];
  	  if (lx > r || rx < l) continue;
  	  if (rx - lx + 1 > li || rx > i + len + li - 2)
		{wd = 1; break;}
	  if (rx < i + li - 1) rx = i + li - 1;
	  if (lx > i + len - 1) lx = i + len - 1;
	  if (rx - i - li + 2 > L) L = rx - i - li + 2;
	  if (lx - i + 1 < R) R = lx - i + 1;
	}
	if (wd) continue;
	if (L > R) continue;
	ll kl = 1ll * (len - 2) * (len - 1) / 2 +
	  1ll * len * (len + 1) / 2 - 1 - (minA + R - 1),
	  kr = 1ll * (len - 2) * (len - 1) / 2 +
	  1ll * len * (len + 1) / 2 - 1 - (minA + L - 1);
	if (kr < 0) continue;
	if (kl < 0) kl = 0;
	return std::cout << kl << std::endl, 0;
  }
  return 0;
}