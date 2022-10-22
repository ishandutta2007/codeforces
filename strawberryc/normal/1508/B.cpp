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
const ll INF = 2005013120050131200ll;

ll p2[N];

ll calcsum(int l, int r) {
  if (l == 0) return p2[r];
  l--; r--;
  if (p2[l] >= INF || p2[r - l + 1] >= INF) return INF;
  if (p2[r - l + 1] - 1 > INF / p2[l]) return INF;
  return p2[l] * (p2[r - l + 1] - 1);
}

void work() {
  int n; ll k;
  read(n); read(k);
  if (k > p2[n - 1]) return (void) puts("-1");
  int cur = 1;
  while (cur <= n) {
  	int l = cur, r = n;
  	while (l <= r) {
  	  int mid = l + r >> 1;
  	  if (k <= calcsum(n - mid, n - cur)) r = mid - 1;
  	  else l = mid + 1;
	}
	for (int i = l; i >= cur; i--) printf("%d ", i);
	if (l > cur) k -= calcsum(n - l + 1, n - cur);
	cur = l + 1;
  }
  puts("");
}

int main() {
  p2[0] = 1;
  for (int i = 1; i <= 100000; i++)
    if ((p2[i] = p2[i - 1] * 2) > INF)
      p2[i] = INF;
  int T; read(T);
  while (T--) work();
  return 0;
}