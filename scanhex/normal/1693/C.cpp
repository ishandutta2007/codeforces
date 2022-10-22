#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

const int N=200200;
vector<int>g[N];
vector<int>ginv[N];
int d[N];
int dist[N], cnt[N];

struct cmp {
	 bool operator()(int a, int b) const {
		 if (d[a] != d[b])
			 return d[a] < d[b];
		 return a < b;
	 }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m;++i) {
	  int a, b;
	  cin >> a >> b;
	  --a, --b;
	  g[a].push_back(b);
	  ++cnt[a];
	  ginv[b].push_back(a);
  }
  int oo = 0x3f3f3f3f;
  fill(d, d + n, oo);
  fill(dist, dist + n, oo);
  d[n - 1] = 0;
  dist[n - 1] = 0;
  set<int, cmp> st;
  st.insert(n - 1);
  vector<bool>used(n);
  while (st.size()) {
	  int x = *st.begin();
	  st.erase(x);
	  for(int y : ginv[x]) {
		  if (x == y) continue;
		  if (!used[x])
			  --cnt[y];
		  if (1 + d[x] + cnt[y] < d[y]) {
			  st.erase(y);
			  d[y] = min(d[y], 1 + d[x] + cnt[y]);
			  st.insert(y);
		  }
	  }
	  used[x] = true;
  }
  cout << d[0] << '\n';
  return 0;
}