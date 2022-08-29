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
  int n;
  cin >> n;
  vector<long long> a(n), b(n), c(n), d(n);
  for (int i = 0; i < n; i++){
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }
  vector<pair<long long, long long>> A(n), B(n);
  for (int i = 0; i < n; i++){
    long long A1 = b[i] * (c[i] + d[i]);
    long long B1 = a[i] * d[i];
    long long g1 = gcd(A1, B1);
    A[i] = make_pair(A1 / g1, B1 / g1);
    long long A2 = b[i] * c[i];
    long long B2 = (a[i] + b[i]) * d[i];
    long long g2 = gcd(A2, B2);
    B[i] = make_pair(A2 / g2, B2 / g2);
  }
  vector<pair<long long, long long>> P;
  for (int i = 0; i < n; i++){
    P.push_back(A[i]);
    P.push_back(B[i]);
  }
  sort(P.begin(), P.end());
  P.erase(unique(P.begin(), P.end()), P.end());
  int cnt = P.size();
  unionfind UF(n + cnt);
  vector<long long> x(n), y(n);
  for (int i = 0; i < n; i++){
    x[i] = lower_bound(P.begin(), P.end(), A[i]) - P.begin();
    y[i] = lower_bound(P.begin(), P.end(), B[i]) - P.begin();
    if (UF.same(x[i], y[i])){
      y[i] = cnt + i;
    }
    UF.unite(x[i], y[i]);
  }
  int V = n + cnt;
  vector<vector<pair<int, int>>> E(V);
  for (int i = 0; i < n; i++){
    E[x[i]].push_back(make_pair(i, y[i]));
    E[y[i]].push_back(make_pair(i, x[i]));
  }
  vector<bool> used(cnt, false);
  vector<int> p(V, -1);
  vector<vector<pair<int, int>>> ch(V);
  vector<bool> ok(V, false);
  vector<pair<int, int>> ans;
  for (int i = 0; i < V; i++){
    if (p[i] == -1){
      queue<int> Q;
      Q.push(i);
      vector<int> bfs;
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        bfs.push_back(v);
        for (auto P : E[v]){
          int w = P.second;
          if (w != p[v]){
            p[w] = v;
            ch[v].push_back(P);
            Q.push(w);
          }
        }
      }
      reverse(bfs.begin(), bfs.end());
      for (int v : bfs){
        vector<pair<int, int>> r;
        for (auto P : ch[v]){
          int w = P.second;
          if (!ok[w]){
            ans.push_back(make_pair(P.first, ch[w][0].first));
          } else {
            r.push_back(P);
          }
        }
        int sz = r.size();
        for (int j = 0; j < sz / 2; j++){
          ans.push_back(make_pair(r[j * 2].first, r[j * 2 + 1].first));
        }
        if (sz % 2 == 0){
          ok[v] = true;
        } else {
          ch[v] = {r.back()};
        }
      }
    }
  }
  int sz = ans.size();
  cout << sz << endl;
  for (int i = 0; i < sz; i++){
    cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << endl;
  }
}