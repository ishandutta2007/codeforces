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

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

typedef long long ll;

const int N = 3e5 + 5;
const ll INF = 1145141919810114514ll;

int n, h[N], b[N], top, stk[N];
ll val[N], mx[N];

int main() {
  read(n); mx[0] = -INF;
  for (int i = 1; i <= n; i++) read(h[i]);
  for (int i = 1; i <= n; i++) read(b[i]);
  for (int i = 1; i <= n; i++) {
  	ll v = (i == 1 ? 0 : mx[top]) + b[i];
  	while (top && h[stk[top]] > h[i])
  	  v = Max(v, val[top] - b[stk[top]] + b[i]), top--;
  	stk[++top] = i; val[top] = v;
  	mx[top] = Max(mx[top - 1], v);
  }
  return std::cout << mx[top] << std::endl, 0;
}