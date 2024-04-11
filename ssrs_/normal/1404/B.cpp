#include <bits/stdc++.h>
using namespace std;
const int LOG = 18;
vector<int> height(vector<vector<int>> &E){
  int N = E.size();
  vector<int> d1(N, -1);
  d1[0] = 0;
  queue<int> Q1;
  Q1.push(0);
  while (!Q1.empty()){
    int v = Q1.front();
    Q1.pop();
    for (int w : E[v]){
      if (d1[w] == -1){
        d1[w] = d1[v] + 1;
        Q1.push(w);
      }
    }
  }
  int r1 = max_element(d1.begin(), d1.end()) - d1.begin();
  vector<int> d2(N, -1);
  d2[r1] = 0;
  queue<int> Q2;
  Q2.push(r1);
  while (!Q2.empty()){
    int v = Q2.front();
    Q2.pop();
    for (int w : E[v]){
      if (d2[w] == -1){
        d2[w] = d2[v] + 1;
        Q2.push(w);
      }
    }
  }
  int r2 = max_element(d2.begin(), d2.end()) - d2.begin();
  vector<int> d3(N, -1);
  d3[r2] = 0;
  queue<int> Q3;
  Q3.push(r2);
  while (!Q3.empty()){
    int v = Q3.front();
    Q3.pop();
    for (int w : E[v]){
      if (d3[w] == -1){
        d3[w] = d3[v] + 1;
        Q3.push(w);
      }
    }
  }
  vector<int> ans(N);
  for (int i = 0; i < N; i++){
    ans[i] = max(d2[i], d3[i]);
  }
  return ans;
}
struct lowest_common_ancestor{
	vector<int> d;
	vector<vector<int>> p;
	lowest_common_ancestor(vector<int> &P, vector<vector<int>> &C){
		int N = P.size();
		d = vector<int>(N, 0);
		queue<int> Q;
		Q.push(0);
		while (!Q.empty()){
			int v = Q.front();
			Q.pop();
			for (int w : C[v]){
				d[w] = d[v] + 1;
				Q.push(w);
			}
		}
		p = vector<vector<int>>(N, vector<int>(LOG, -1));
		for (int i = 0; i < N; i++){
			p[i][0] = P[i];
		}
		for (int i = 1; i < LOG; i++){
			for (int j = 0; j < N; j++){
				if (p[j][i - 1] != -1){
					p[j][i] = p[p[j][i - 1]][i - 1];
				}
			}
		}
	}
	int lca(int u, int v){
		if (d[u] > d[v]){
			swap(u, v);
		}
		for (int k = 0; k < LOG; k++){
			if ((d[v] - d[u]) >> k & 1){
				v = p[v][k];
			}
		}
		if (u == v){
		    return u;
		}
		for (int k = LOG - 1; k >= 0; k--){
			if (p[u][k] != p[v][k]){
				u = p[u][k];
				v = p[v][k];
			}
		}
		return p[u][0];
	}
	int dist(int u, int v){
	  return d[u] + d[v] - 2 * d[lca(u, v)];
	}
};
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    a--;
    b--;
    vector<vector<int>> E(n);
    for (int j = 0; j < n - 1; j++){
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      E[u].push_back(v);
      E[v].push_back(u);
    }
    if (db <= da * 2){
      cout << "Alice" << endl;
    } else {
      vector<int> p(n, -1);
      vector<vector<int>> c(n);
      queue<int> Q;
      vector<int> d(n, 0);
      Q.push(0);
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        for (int w : E[v]){
          if (w != p[v]){
            p[w] = v;
            c[v].push_back(w);
            d[w] = d[v] + 1;
            Q.push(w);
          }
        }
      }
      lowest_common_ancestor T(p, c);
      if (T.dist(a, b) <= da){
        cout << "Alice" << endl;
      } else {
        vector<int> h = height(E);
        bool ok = true;
        for (int j = 0; j < n; j++){
          if (h[j] <= da){
            ok = false;
          }
        }
        if (ok){
          cout << "Bob" << endl;
        } else {
          cout << "Alice" << endl;
        }
      }
    }
  }
}