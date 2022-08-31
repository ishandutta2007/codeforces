#include <bits/stdc++.h>
using namespace std;
const int INF = 100000000;
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
	int size(int x){
		return -p[root(x)];
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
struct union_enumerate{
  vector<int> nxt;
  union_enumerate(int N): nxt(N){
    for (int i = 0; i < N; i++){
      nxt[i] = i;
    }
  }
  vector<int> enumerate(int x){
    vector<int> ans;
    int y = x;
    while (true){
      ans.push_back(y);
      y = nxt[y];
      if (y == x){
        break;
      }
    }
    return ans;
  }
  void unite(int x, int y){
    swap(nxt[x], nxt[y]);
  }
};
void dfs(vector<vector<int>> &c, vector<int> &P, vector<int> &L, vector<int> &R, int v){
  L[v] = P.size();
  if (c[v].empty()){
    P.push_back(v);
  }
  for (int w : c[v]){
    dfs(c, P, L, R, w);
  }
  R[v] = P.size();
}
struct segment_tree_min{
  int N;
  vector<pair<int, int>> ST;
  segment_tree_min(vector<pair<int, int>> &A){
    int n = A.size();
    N = 1;
    while (N < n){
      N *= 2;
    }
    ST = vector<pair<int, int>>(N * 2 - 1, make_pair(INF, 0));
    for (int i = 0; i < n; i++){
      ST[N - 1 + i] = A[i];
    }
    for (int i = N - 2; i >= 0; i--){
      ST[i] = min(ST[i * 2 + 1], ST[i * 2 + 2]);
    }
  }
  void update(int i, int x){
    i += N - 1;
    ST[i].first = x;
    while (i > 0){
      i = (i - 1) / 2;
      ST[i] = min(ST[i * 2 + 1], ST[i * 2 + 2]);
    }
  }
  pair<int, int> range_min(int L, int R, int i, int l, int r){
    if (r <= L || R <= l){
      return make_pair(INF, INF);
    } else if (L <= l && r <= R){
      return ST[i];
    } else {
      int m = (l + r) / 2;
      return min(range_min(L, R, i * 2 + 1, l, m), range_min(L, R, i * 2 + 2, m, r));
    }
  }
  pair<int, int> range_min(int L, int R){
    return range_min(L, R, 0, 0, N);
  }
};
struct segment_tree_max{
  int N;
  vector<pair<int, int>> ST;
  segment_tree_max(vector<pair<int, int>> &A){
    int n = A.size();
    N = 1;
    while (N < n){
      N *= 2;
    }
    ST = vector<pair<int, int>>(N * 2 - 1, make_pair(-INF, 0));
    for (int i = 0; i < n; i++){
      ST[N - 1 + i] = A[i];
    }
    for (int i = N - 2; i >= 0; i--){
      ST[i] = max(ST[i * 2 + 1], ST[i * 2 + 2]);
    }
  }
  void update(int i, int x){
    i += N - 1;
    ST[i].first = x;
    while (i > 0){
      i = (i - 1) / 2;
      ST[i] = max(ST[i * 2 + 1], ST[i * 2 + 2]);
    }
  }
  pair<int, int> range_max(int L, int R, int i, int l, int r){
    if (r <= L || R <= l){
      return make_pair(-INF, -INF);
    } else if (L <= l && r <= R){
      return ST[i];
    } else {
      int m = (l + r) / 2;
      return max(range_max(L, R, i * 2 + 1, l, m), range_max(L, R, i * 2 + 2, m, r));
    }
  }
  pair<int, int> range_max(int L, int R){
    return range_max(L, R, 0, 0, N);
  }
};
struct heavy_light_decomposition{
  vector<int> p, sz, in, next;
  heavy_light_decomposition(vector<int> &p, vector<vector<int>> &c): p(p){
    int N = p.size();
    sz = vector<int>(N);
    dfs1(c, N - 1);
    in = vector<int>(N);
    next = vector<int>(N);
    next[N - 1] = N - 1;
    int t = 0;
    dfs2(c, t, N - 1);
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
  int lca(int u, int v){
    while (true){
      if (in[u] > in[v]){
        swap(u, v);
      }
      if (next[u] == next[v]){
        return u;
      }
      v = p[next[v]];
    }
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m), c(m);
    for (int j = 0; j < m; j++){
      cin >> a[j] >> b[j] >> c[j];
      a[j]--;
      b[j]--;
    }
    vector<tuple<int, int, int>> E(m);
    for (int j = 0; j < m; j++){
      E[j] = make_tuple(c[j], a[j], b[j]);
    }
    sort(E.begin(), E.end());
    unionfind UF(n);
    vector<int> pr(n * 2 - 1, -1);
    vector<int> cr(n);
    for (int j = 0; j < n; j++){
      cr[j] = j;
    }
    int V = n;
    vector<int> W(n * 2 - 1, -1);
    for (int j = 0; j < m; j++){
      int A = get<1>(E[j]);
      int B = get<2>(E[j]);
      int A2 = UF.root(A);
      int B2 = UF.root(B);
      if (A2 != B2){
        W[V] = get<0>(E[j]);
        pr[cr[A2]] = V;
        pr[cr[B2]] = V;
        UF.unite(A2, B2);
        cr[UF.root(A2)] = V;
        V++;
      }
    }
    vector<vector<int>> ch(V);
    for (int j = 0; j < V - 1; j++){
      ch[pr[j]].push_back(j);
    }
    vector<int> P;
    vector<int> L(V), R(V);
    dfs(ch, P, L, R, n * 2 - 2);
    vector<tuple<int, int, int>> E2;
    vector<int> pos(n);
    for (int j = 0; j < n; j++){
      pos[P[j]] = j;
    }
    vector<set<int>> ng(n);
    for (int j = 0; j < m; j++){
      int A = get<1>(E[j]);
      int B = get<2>(E[j]);
      ng[A].insert(pos[B]);
      ng[B].insert(pos[A]);
    }
    unionfind UF2(n);
    vector<pair<int, int>> S(n);
    for (int j = 0; j < n; j++){
      S[j] = make_pair(P[j], P[j]);
    }
    union_enumerate UE(n);
    segment_tree_min ST1(S);
    segment_tree_max ST2(S);
    for (int j = n; j < V; j++){
      int x = ch[j][0], y = ch[j][1];
      if (R[x] - L[x] > R[y] - L[y]){
        swap(x, y);
      }
      for (int k = L[x]; k < R[x]; k++){
        vector<int> ng2;
        ng2.push_back(L[y] - 1);
        while (true){
          auto itr = ng[P[k]].lower_bound(ng2.back() + 1);
          if (itr == ng[P[k]].end()){
            break;
          }
          if (*itr >= R[y]){
            break;
          }
          ng2.push_back(*itr);
        }
        ng2.push_back(R[y]);
        int cnt = ng2.size();
        for (int l = 0; l < cnt - 1; l++){
          if (ng2[l + 1] - ng2[l] > 1){
            int left = ng2[l] + 1;
            int right = ng2[l + 1];
            while (true){
              bool ok = true;
              pair<int, int> p1 = ST1.range_min(left, right);
              if (p1.first != UF2.root(P[k])){
                ok = false;
                int x = p1.second;
                int y = P[k];
                E2.push_back(make_tuple(W[j], x, y));
                x = UF2.root(x);
                y = UF2.root(y);
                UF2.unite(x, y);
                int r = UF2.root(x);
                vector<int> e = UE.enumerate(r ^ x ^ y);
                for (int v : e){
                  ST1.update(pos[v], UF2.root(v));
                  ST2.update(pos[v], UF2.root(v));
                }
                UE.unite(x, y);
              }
              pair<int, int> p2 = ST2.range_max(left, right);
              if (p2.first != UF2.root(P[k])){
                ok = false;
                int x = p2.second;
                int y = P[k];
                if (UF2.size(x) > UF2.size(y)){
                  swap(x, y);
                }
                E2.push_back(make_tuple(W[j], x, y));
                x = UF2.root(x);
                y = UF2.root(y);
                UF2.unite(x, y);
                int r = UF2.root(x);
                vector<int> e = UE.enumerate(r ^ x ^ y);
                for (int v : e){
                  ST1.update(pos[v], UF2.root(v));
                  ST2.update(pos[v], UF2.root(v));
                }
                UE.unite(x, y);
              }
              if (ok){
                break;
              }
            }
          }
        }
      }
    }
    sort(E2.begin(), E2.end());
    unionfind UF3(n);
    vector<int> pr2(n * 2 - 1, -1);
    vector<int> cr2(n);
    for (int j = 0; j < n; j++){
      cr2[j] = j;
    }
    int V2 = n;
    vector<int> W2(n * 2 - 1, -1);
    for (int j = 0; j < n - 1; j++){
      int A = get<1>(E2[j]);
      int B = get<2>(E2[j]);
      int A2 = UF3.root(A);
      int B2 = UF3.root(B);
      W2[V2] = get<0>(E2[j]);
      pr2[cr2[A2]] = V2;
      pr2[cr2[B2]] = V2;
      UF3.unite(A2, B2);
      cr2[UF3.root(A2)] = V2;
      V2++;
    }
    vector<vector<int>> ch2(V2);
    for (int j = 0; j < V2 - 1; j++){
      ch2[pr2[j]].push_back(j);
    }
    heavy_light_decomposition HLD(pr2, ch2);
    for (int j = 0; j < m; j++){
      cout << W2[HLD.lca(a[j], b[j])];
      if (j < m - 1){
        cout << ' ';
      }
    }
    cout << "\n";
  }
}