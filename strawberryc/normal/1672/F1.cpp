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

const int N = 2e5 + 5;

int n, a[N], cnt[N], ans[N];
std::vector<int> rka[N];
std::pair<int, int> wd[N];

int main() {
  int T; read(T);
  while (T--) {
  	read(n);
  	for (int i = 1; i <= n; i++) read(a[i]), cnt[i] = 0, rka[i].clear();
  	for (int i = 1; i <= n; i++) cnt[a[i]]++, rka[a[i]].push_back(i);
  	for (int i = 1; i <= n; i++) wd[i] = std::make_pair(i, cnt[i]);
  	std::sort(wd + 1, wd + n + 1, [&](std::pair<int, int> u, std::pair<int, int> v)
	  {return u.second < v.second;});
	int cur = n;
	while (cur) {
	  int lst = n, x, tmp = wd[n].second;
	  while (wd[lst].second == tmp) wd[lst--].second--;
	  cur -= n - lst;
	  std::vector<int> tobe;
	  for (int i = n; i > lst; i--) tobe.push_back(wd[i].first);
	  for (int i = 0; i < tobe.size(); i++)
	    tobe[i] = rka[x = tobe[i]][rka[tobe[i]].size() - 1], rka[x].pop_back();
	  for (int i = 0; i + 1 < tobe.size(); i++)
	    ans[tobe[i]] = a[tobe[i + 1]];
	  ans[tobe[tobe.size() - 1]] = a[tobe[0]];
	}
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	puts("");
  }
  return 0;
}