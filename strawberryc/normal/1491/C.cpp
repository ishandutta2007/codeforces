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
ll cnt[N];

void work() {
  read(n); ll ans = 0;
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int i = 1; i <= n; i++) {
  	ll sum = 0;
  	for (int j = 1; j < i - 1; j++)
  	  if (j + a[j] >= i) sum++;
  	if (i > 1) sum += cnt[i - 1] - a[i - 1] + 1;
  	cnt[i] = sum;
	if (sum < a[i]) cnt[i] = a[i] - 1, ans += a[i] - 1 - sum;
  }
  printf("%lld\n", ans);
}

int main() {
  int T; read(T);
  while (T--) work();
  return 0;
}