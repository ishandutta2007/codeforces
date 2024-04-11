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

const int N = 2e5 + 5;

int n, a[N];
ll s;
std::map<ll, int> cnt;
std::priority_queue<ll> pq;

void yhjssa() {
  read(n); s = 0;
  for (int i = 1; i <= n; i++) read(a[i]), s += a[i];
  cnt.clear();
  while (!pq.empty()) pq.pop(); pq.push(s);
  for (int i = 1; i <= n; i++) cnt[a[i]]++;
  int T = 0;
  while (!pq.empty()) {
  	ll v = pq.top(); pq.pop();
  	if (cnt[v]) cnt[v]--;
  	else if (T < n - 1) T++, pq.push(v >> 1), pq.push(v + 1 >> 1);
  	else return (void) puts("No");
  }
  puts("Yes");
}

int main() {
  int T; std::cin >> T;
  while (T--) yhjssa();
  return 0;
}