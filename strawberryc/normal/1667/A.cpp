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

const int N = 5005;

int n, a[N];
ll ans = 1145141145141919810ll;

int main() {
  read(n);
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int x = 1; x <= n; x++) {
  	ll res = 0, cur = 0;
  	for (int i = x - 1; i >= 1; i--) {
  	  ll cnt = cur / a[i] + 1;
  	  res += cnt; cur = cnt * a[i];
	}
	cur = 0;
	for (int i = x + 1; i <= n; i++) {
	  ll cnt = cur / a[i] + 1;
	  res += cnt; cur = cnt * a[i];
	}
	if (res < ans) ans = res;
  }
  return std::cout << ans << std::endl, 0;
}