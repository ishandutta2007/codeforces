#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct binary_indexed_tree{
	int N;
	vector<T> BIT;
	binary_indexed_tree(){
	}
	binary_indexed_tree(int N): N(N), BIT(N + 1, 0){
	}
	void add(int i, T x){
		i++;
		while (i <= N){
			BIT[i] += x;
			i += i & -i;
		}
	}
	T sum(int i){
		T ans = 0;
		while (i > 0){
			ans += BIT[i];
			i -= i & -i;
		}
		return ans;
	}
	T sum(int L, int R){
		return sum(R) - sum(L);
	}
};
struct heavy_light_decomposition{
  vector<int> p, sz, in, next;
  binary_indexed_tree<long long> BIT1, BIT2;
  heavy_light_decomposition(vector<int> &p, vector<vector<int>> &c, int r): p(p){
    int N = p.size();
    sz = vector<int>(N);
    dfs1(c, r);
    in = vector<int>(N);
    next = vector<int>(N, r);
    int t = 0;
    dfs2(c, t, r);
    BIT1 = binary_indexed_tree<long long>(N);
    BIT2 = binary_indexed_tree<long long>(N);
  }
  void dfs1(vector<vector<int>> &c, int v){
    sz[v] = 1;
    for (int &w : c[v]){
      dfs1(c, w);
      sz[v] += sz[w];
      if (sz[w] > sz[c[v][0]]){
        swap(w, c[v][0]);
      }
    }
  }
  void dfs2(vector<vector<int>> &c, int &t, int v){
    in[v] = t;
    t++;
    for (int w : c[v]){
      if (w == c[v][0]){
        next[w] = next[v];
      } else {
        next[w] = w;
      }
      dfs2(c, t, w);
    }
  }
  void add(int v){
    while (v != -1){
      int L = in[next[v]];
      int R = in[v] + 1;
      BIT1.add(L, -L);
      BIT2.add(L, 1);
      BIT1.add(R, R);
      BIT2.add(R, -1);
      v = p[next[v]];
    }
  }
  long long sum(int v){
    long long ans = 0;
    while (v != -1){
      int L = in[next[v]];
      int R = in[v] + 1;
      ans += BIT1.sum(R);
      ans -= BIT1.sum(L);
      ans += BIT2.sum(R) * R;
      ans -= BIT2.sum(L) * L;
      v = p[next[v]];
    }
    return ans;
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> p(n, -1);
  for (int i = 0; i < n; i++){
    cin >> p[i];
    p[i]--;
  }
  int r;
  for (int i = 0; i < n; i++){
    if (p[i] == -1){
      r = i;
    }
  }
  vector<vector<int>> c(n);
  for (int i = 0; i < n; i++){
    if (p[i] != -1){
      c[p[i]].push_back(i);
    }
  }
  vector<int> d(n, 0);
  queue<int> Q;
  Q.push(r);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (int w : c[v]){
      d[w] = d[v] + 1;
      Q.push(w);
    }
  }
  vector<vector<int>> id(n);
  for (int i = 0; i < n; i++){
    id[d[i]].push_back(i);
  }
  heavy_light_decomposition T(p, c, r);
  vector<long long> z(n);
  for (int i = 0; i < n; i++){
    for (int v : id[i]){
      T.add(v);
    }
    for (int v : id[i]){
      z[v] = T.sum(v) - d[v] - 1;
    }
  }
  for (int i = 0; i < n; i++){
    cout << z[i];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}