#include <bits/stdc++.h>
#define p2 p << 1
#define p3 p << 1 | 1

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
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

typedef long long ll;

const int N = 1e5 + 5, L = N << 2, M = 17;

int phi[N], tot, pri[N];
bool mark[N];
std::vector<int> di[N];
ll f[N][M], T[L], add[L];

void build(int l, int r, int t, int p) {
  add[p] = 0;
  if (l == r) return (void) (T[p] = f[l][t]);
  int mid = l + r >> 1;
  build(l, mid, t, p2); build(mid + 1, r, t, p3);
  T[p] = Min(T[p2], T[p3]);
}

void change(int l, int r, int x, int v, int p) {
  if (l == r) return (void) (T[p] += v, add[p] += v);
  int mid = l + r >> 1;
  if (x <= mid) change(l, mid, x, v, p2);
  else T[p2] += v, add[p2] += v, change(mid + 1, r, x, v, p3);
  T[p] = Min(T[p2], T[p3]) + add[p];
}

void init(int n, int m) {
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j += i)
      di[j].push_back(i);
  mark[0] = mark[phi[1] = 1] = 1;
  for (int i = 2; i <= n; i++) {
  	if (!mark[i]) {pri[++tot] = i; phi[i] = i - 1;}
	for (int j = 1; j <= tot; j++) {
	  if (1ll * i * pri[j] > n) break;
	  mark[i * pri[j]] = 1;
	  if (i % pri[j] == 0) {
	  	phi[i * pri[j]] = phi[i] * pri[j];
	  	break;
	  }
	  else phi[i * pri[j]] = phi[i] * (pri[j] - 1);
	}
  }
  for (int i = 1; i <= n; i++) f[i][1] = 1ll * i * (i + 1) / 2;
  for (int j = 1; j < m; j++) {
  	build(j, n, j, 1);
  	for (int i = j + 1; i <= n; i++) {
  	  for (int k = 0; k < di[i].size(); k++)
  	    if (di[i][k] > j) change(j, n, di[i][k] - 1, phi[i / di[i][k]], 1);
  	  f[i][j + 1] = T[1];
	}
  }
}

int main() {
  int T; read(T);
  init(100000, 17);
  while (T--) {
  	int n, m;
  	read(n); read(m);
  	printf("%lld\n", m > 17 ? n : f[n][m]);
  }
  return 0;
}