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

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 3e5 + 5, E = 20;

int n, q, k, a[N], l[N], r[N], Log[N], RMQ[N][E], top, stk[N];
std::vector<int> que[N];
ll ans[N];

struct elem {
  int val, sc;
  ll sci;
};

std::vector<elem> mo[N];

int qmin(int l, int r) {
  int k = Log[r - l + 1];
  return Min(RMQ[l][k], RMQ[r - (1 << k) + 1][k]);
}

int main() {
  read(n); read(q); read(k);
  for (int i = 0; i < n; i++) read(a[i]);
  for (int i = 1; i <= q; i++) read(l[i]), read(r[i]), l[i]--, r[i]--;
  if (1ll * k * k > n) {
  	Log[0] = -1;
  	for (int i = 1; i <= n; i++) Log[i] = Log[i >> 1] + 1;
  	for (int i = 0; i < n; i++) RMQ[i][0] = a[i];
  	for (int j = 0; j < 18; j++)
  	  for (int i = 0; i + (1 << j + 1) - 1 < n; i++)
  	    RMQ[i][j + 1] = Min(RMQ[i][j], RMQ[i + (1 << j)][j]);
  	for (int i = 1; i <= q; i++) {
  	  ll res = 0;
  	  for (int j = l[i]; j <= r[i]; j += k) res += qmin(l[i], j);
  	  printf("%lld\n", res);
	}
	return 0;
  }
  for (int i = 0; i < k; i++) mo[i].push_back((elem) {0, 0, 0ll});
  for (int i = 1; i <= q; i++) que[l[i]].push_back(i);
  stk[top = 0] = n;
  for (int i = n - 1; i >= 0; i--) {
  	while (top && a[stk[top]] >= a[i]) {
  	  for (int j = 0; j < k; j++)
  	    if (mo[j][mo[j].size() - 1].val == a[stk[top]])
  	      mo[j].pop_back();
  	  top--;
	}
	int z = i % k, c = (stk[top] - i) / k, ck = (stk[top] - i) % k;
	for (int j = 1, w = z; j <= k; j++) {
	  int l = j <= ck ? c + 1 : c, lt = mo[w].size() - 1;
	  int _sc = mo[w][lt].sc; ll _sci = mo[w][lt].sci;
	  if (l) mo[w].push_back((elem) {a[i], _sc + l, _sci + 1ll * l * a[i]});
	  if ((++w) == k) w = 0;
	}
	stk[++top] = i;
	for (int wd = 0; wd < que[i].size(); wd++) {
	  int id = que[i][wd], cnt = (r[id] - l[id]) / k + 1;
	  int allsc = mo[z][mo[z].size() - 1].sc;
	  ll allsci = mo[z][mo[z].size() - 1].sci, L = 0, R = mo[z].size() - 1;
	  while (L <= R) {
	  	int mid = L + R >> 1;
	  	if (mo[z][mid].sc >= allsc - cnt) R = mid - 1;
	  	else L = mid + 1;
	  }
	  ans[id] = allsci - mo[z][L].sci +
	    1ll * mo[z][L].val * (mo[z][L].sc - allsc + cnt);
	}
  }
  for (int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
  return 0;
}