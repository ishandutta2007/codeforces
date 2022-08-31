#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
const int LOG = 20;
struct unionfind{
	vector<int> p;
	unionfind(int N): p(vector<int>(N, -1)){
	};
	int root(int x){
		if (p[x] == -1){
			return x;
		} else {
			p[x] = root(p[x]);
			return p[x];
		}
	}
	bool same(int x, int y){
		return root(x) == root(y);
	}
	void unite(int x, int y){
		x = root(x);
		y = root(y);
		if (x != y){
			p[x] = y;
		}
	}
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, k, q;
  cin >> n >> m >> k >> q;
  vector<vector<pair<int, int>>> E(n);
  for (int i = 0; i < m; i++){
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    E[u].push_back(make_pair(w, v));
    E[v].push_back(make_pair(w, u));
  }
  priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
  vector<tuple<long long, int, int>> E2;
  for (int i = 0; i < k; i++){
    pq.push(make_tuple(0, i, i));
  }
  vector<long long> mind(n, INF);
  vector<int> mind_c(n, -1);
  while (!pq.empty()){
    long long d = get<0>(pq.top());
    int v = get<1>(pq.top());
    int c = get<2>(pq.top());
    pq.pop();
    if (mind[v] == INF){
      mind[v] = d;
      mind_c[v] = c;
      for (auto P : E[v]){
        int w = P.second;
        if (mind[w] == INF){
          pq.push(make_tuple(d + P.first, w, c));
        }
      }
    } else {
      long long sum = mind[v] + d;
      E2.push_back(make_tuple(sum, c, mind_c[v]));
    }
  }
  sort(E2.begin(), E2.end());
  int cnt = E2.size();
  unionfind UF(k);
  vector<vector<pair<long long, int>>> E3(k);
  for (int i = 0; i < cnt; i++){
    long long d = get<0>(E2[i]);
    int u = get<1>(E2[i]);
    int v = get<2>(E2[i]);
    if (!UF.same(u, v)){
      UF.unite(u, v);
      E3[u].push_back(make_pair(d, v));
      E3[v].push_back(make_pair(d, u));
    }
  }
  vector<int> p(k, -1);
  vector<int> d(k, 0);
  vector<long long> a(k, 0);
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (auto P : E3[v]){
      int w = P.second;
      if (w != p[v]){
        p[w] = v;
        d[w] = d[v] + 1;
        a[w] = P.first;
        Q.push(w);
      }
    }
  }
  vector<vector<int>> next(LOG, vector<int>(k, -1));
  vector<vector<long long>> mx(LOG, vector<long long>(k, -INF));
  for (int i = 0; i < k; i++){
    next[0][i] = p[i];
    mx[0][i] = a[i];
  }
  for (int i = 1; i < LOG; i++){
    for (int j = 0; j < k; j++){
      if (next[i - 1][j] != -1){
        next[i][j] = next[i - 1][next[i - 1][j]];
        mx[i][j] = max(mx[i - 1][j], mx[i - 1][next[i - 1][j]]);
      }
    }
  }
  for (int i = 0; i < q; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (d[a] > d[b]){
      swap(a, b);
    }
    long long ans = 0;
    for (int j = 0; j < LOG; j++){
      if ((d[b] - d[a]) >> j & 1){
        ans = max(ans, mx[j][b]);
        b = next[j][b];
      }
    }
    if (a != b){
      for (int j = LOG - 1; j >= 0; j--){
        if (next[j][a] != next[j][b]){
          ans = max(ans, mx[j][a]);
          ans = max(ans, mx[j][b]);
          a = next[j][a];
          b = next[j][b];
        }
      }
      ans = max(ans, mx[0][a]);
      ans = max(ans, mx[0][b]);
    }
    cout << ans << endl;
  }
}