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

const int N = 1e6 + 5, EI = 1e9 + 7;

int n, p[N], tot, s[N];
bool vis[N];

void work() {
  read(n);
  for (int i = 1; i <= n; i++) read(p[i]), vis[i] = 0;
  int cnt1 = 0, cnt2 = 0, pr = 1, ans = 0;
  tot = 0;
  for (int i = 1; i <= n; i++) if (!vis[i]) {
  	s[++tot] = 0;
    for (int j = i; !vis[j]; j = p[j])
      s[tot]++, vis[j] = 1;
  }
  for (int i = 1; i <= tot; i++) {
    if (s[i] % 3 == 1) cnt1++;
    else if (s[i] % 3 == 2) cnt2++;
    ans += (s[i] - 1) / 3;
  }
  if (n % 3 == 0) {
  	for (int i = 1; i <= n / 3; i++) pr = 3ll * pr % EI;
  	if (cnt1 <= cnt2) ans += cnt2;
  	else ans += (cnt2 * 2 + cnt1) / 3 * 2 - cnt2;
  }
  else if (n % 3 == 2) {
  	pr = 2;
  	for (int i = 1; i <= n / 3; i++) pr = 3ll * pr % EI;
  	int k = ((cnt2 - 1) * 2 + cnt1) / 3;
  	if (cnt2 >= k + 1) ans += cnt2 - 1;
  	else ans += k * 2 - cnt2 + 1;
  }
  else {
  	pr = 4;
  	for (int i = 1; i < n / 3; i++) pr = 3ll * pr % EI;
  	int k = (cnt2 * 2 + cnt1 - 1) / 3, bas = ans, res = ans;
  	if (cnt2 >= k) ans += cnt2; else ans += k * 2 - cnt2;
  	ans++;
  	if (cnt2 * 2 + cnt1 >= 4) {
  	  k = (cnt2 * 2 + cnt1 - 4) / 3 + 2; res -= 2;
  	  if (cnt2 >= k) res += cnt2; else res += k * 2 - cnt2;
  	  if (res < ans) ans = res;
	}
  	for (int i = 1; i <= tot; i++) if (s[i] >= 4) {
  	  int tr = bas, t1 = cnt1, t2 = cnt2;
  	  tr -= (s[i] - 1) / 3;
  	  if (s[i] > 4) tr += (s[i] - 5) / 3;
  	  if (s[i] % 3 == 1) t1--;
  	  else if (s[i] % 3 == 2) t2--, t1++;
  	  else t2++;
  	  int res = tr + (t1 <= t2 ? t2 : (t2 * 2 + t1) / 3 * 2 - t2) + (s[i] > 4);
  	  if (res < ans) ans = res;
	}
  }
  printf("%d %d\n", pr, ans);
}

int main() {
  int T; read(T);
  while (T--) work();
  return 0;
}