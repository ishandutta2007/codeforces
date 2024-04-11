#include <bits/stdc++.h>
using namespace std;
struct unionfind{
	vector<int> p;
	unionfind(int N){
		p = vector<int>(N, -1);
	}
	int root(int x){
		if (p[x] < 0){
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
			if (p[x] < p[y]){
				swap(x, y);
			}
			p[y] += p[x];
			p[x] = y;
		}
	}
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, x;
  cin >> n >> m >> x;
  vector<long long> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  long long asum = 0;
  for (int i = 0; i < n; i++){
    asum += a[i];
  }
  if (asum < (long long) x * (n - 1)){
    cout << "NO" << endl;
  } else {
    vector<int> U(m), V(m);
    for (int i = 0; i < m; i++){
      cin >> U[i] >> V[i];
      U[i]--;
      V[i]--;
    }
    vector<vector<pair<int, int>>> E(n);
    for (int i = 0; i < m; i++){
      E[U[i]].push_back(make_pair(i, V[i]));
      E[V[i]].push_back(make_pair(i, U[i]));
    }
    priority_queue<pair<long long, int>> pq;
    for (int i = 0; i < n; i++){
      pq.push(make_pair(a[i], i));
    }
    unionfind UF(n);
    vector<int> curr(n, 0);
    vector<int> e;
    while (!pq.empty()){
      long long A = pq.top().first;
      int v = pq.top().second;
      pq.pop();
      v = UF.root(v);
      A = a[v];
      if (A < x){
        continue;
      }
      if (curr[v] == E[v].size()){
        continue;
      }
      while (true){
        int w = E[v][curr[v]].second;
        if (!UF.same(v, w)){
          break;
        }
        curr[v]++;
        if (curr[v] == E[v].size()){
          break;
        }
      }
      if (curr[v] == E[v].size()){
        continue;
      }
      int id = E[v][curr[v]].first;
      e.push_back(id);
      int w = E[v][curr[v]].second;
      w = UF.root(w);
      long long sum1 = a[v];
      long long sum2 = a[w];
      UF.unite(v, w);
      int r = UF.root(v);
      if (r == v){
        for (auto P : E[w]){
          E[v].push_back(P);
        }
        E[w].clear();
      } else {
        for (auto P : E[v]){
          E[w].push_back(P);
        }
        E[v].clear();
      }
      a[r] = sum1 + sum2 - x;
      pq.push(make_pair(a[r], r));
    }
    for (int i = 0; i < m; i++){
      if (!UF.same(U[i], V[i])){
        UF.unite(U[i], V[i]);
        e.push_back(i);
      }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n - 1; i++){
      cout << e[i] + 1 << "\n";
    }
  }
}