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

struct elem {
  int id, x;
  
  friend inline bool operator < (elem a, elem b) {
  	return a.x > b.x;
  }
};

std::priority_queue<elem> pq;

int n, m, x;

void work() {
  read(n); read(m); read(x);
  while (!pq.empty()) pq.pop();
  for (int i = 1; i <= m; i++) pq.push((elem) {i, 0});
  puts("YES");
  while (n--) {
  	read(x); elem y = pq.top(); pq.pop();
  	printf("%d ", y.id); pq.push((elem) {y.id, y.x + x});
  }
  puts("");
}

int main() {
  int T; read(T);
  while (T--) work();
  return 0;
}