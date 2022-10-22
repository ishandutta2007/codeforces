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

int n, m, a[N], b[N], l[N], r[N], L[N], R[N], pos[N], nm, s[N], iL[N], iR[N];
ll sum[N];
std::set<int> vis, cur;
std::vector<int> al[N], ar[N];

void rec(int i) {if (iL[i] && iR[i]) cur.insert(i);}

int main() {
  int T; read(T);
  while (T--) {
  	read(n); read(m);
  	for (int i = 1; i <= n; i++) read(a[i]);
  	for (int i = 1; i <= n; i++) read(b[i]);
  	for (int i = 1; i <= m; i++) read(l[i]), read(r[i]);
  	for (int i = 1; i <= n; i++)
  	  sum[i] = sum[i - 1] + a[i] - b[i];
  	if (sum[n]) {puts("NO"); continue;}
  	nm = 0;
  	for (int i = 1; i <= n; i++) if (!sum[i]) pos[++nm] = i;
  	vis.clear(); cur.clear();
  	for (int i = 1; i <= nm; i++) {
  	  al[i].clear(); ar[i].clear();
  	  if (pos[i] > pos[i - 1] + 1) vis.insert(i);
	}
  	for (int i = 1; i <= m; i++) {
  	  L[i] = std::lower_bound(pos + 1, pos + nm + 1, l[i]) - pos;
  	  R[i] = std::lower_bound(pos + 1, pos + nm + 1, r[i]) - pos;
  	  bool il = l[i] == pos[L[i] - 1] + 1, ir = r[i] == pos[R[i]];
  	  if (!il) al[L[i]].push_back(i);
  	  if (!ir) ar[R[i]].push_back(i);
  	  iL[i] = il; iR[i] = ir; rec(i);
	}
	while (!cur.empty()) {
	  std::set<int>::iterator it = cur.begin();
	  int id = *it; cur.erase(it);
	  for (it = vis.lower_bound(L[id]); it != vis.end() && *it <= R[id];) {
	  	std::set<int>::iterator ti = it; ti++;
	  	int x = *it; vis.erase(it);
	  	for (int i = 0; i < al[x].size(); i++)
	  	  iL[al[x][i]] = 1, rec(al[x][i]);
	  	for (int i = 0; i < ar[x].size(); i++)
	  	  iR[ar[x][i]] = 1, rec(ar[x][i]);
	  	it = ti;
	  }
	}
	puts(vis.empty() ? "YES" : "NO");
  }
  return 0;
}