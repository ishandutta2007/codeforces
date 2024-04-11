#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<pair<int, int>>> &E, vector<pair<int, int>> &C, vector<int> &d, vector<int> &p, int v, int e = -1){
  for (auto P : E[v]){
    if (P.first != e){
      int w = P.second;
      if (d[w] == -1){
        d[w] = d[v] + 1;
        p[w] = v;
        dfs(E, C, d, p, w, P.first);
      } else if (d[w] <= d[v]){
        int mn = v, mx = v;
        int c = v;
        while (c != w){
          c = p[c];
          mn = min(mn, c);
          mx = max(mx, c);
        }
        C.push_back(make_pair(mn, mx));
      }
    }
  }
}
template <typename T>
struct lazy_segment_tree{
	int N;
	vector<T> ST;
	vector<T> lazy;
	lazy_segment_tree(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, 0);
		lazy = vector<T>(N * 2 - 1, 0);
	}
	void eval(int i){
		if (i < N - 1){
			lazy[i * 2 + 1] += lazy[i] / 2;
			lazy[i * 2 + 2] += lazy[i] / 2;
		}
		ST[i] += lazy[i];
		lazy[i] = 0;
	}
	void range_add(int L, int R, T x, int i, int l, int r){
		eval(i);
		if (R <= l || r <= L){
			return;
		} else if (L <= l && r <= R){
			lazy[i] += (r - l) * x;
			eval(i);
		} else {
			int m = (l + r) / 2;
			range_add(L, R, x, i * 2 + 1, l, m);
			range_add(L, R, x, i * 2 + 2, m, r);
			ST[i] = ST[i * 2 + 1] + ST[i * 2 + 2];
		}
	}
	void range_add(int L, int R, T x){
		range_add(L, R, x, 0, 0, N);
	}
	T range_sum(int L, int R, int i, int l, int r){
		eval(i);
		if (R <= l || r <= L){
			return 0;
		} else if (L <= l && r <= R){
			return ST[i];
		} else {
			int m = (l + r) / 2;
			return range_sum(L, R, i * 2 + 1, l, m) + range_sum(L, R, i * 2 + 2, m, r);
		}
	}
	T range_sum(int L, int R){
		return range_sum(L, R, 0, 0, N);
	}
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> E(n);
  for (int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    E[a].push_back(make_pair(i, b));
    E[b].push_back(make_pair(i, a));
  }
  vector<int> d(n, -1);
  vector<int> p(n, -1);
  vector<pair<int, int>> C;
  for (int i = 0; i < n; i++){
    if (d[i] == -1){
      d[i] = 0;
      dfs(E, C, d, p, i);
    }
  }
  int cnt = C.size();
  vector<int> mx(n, n);
  for (int i = 0; i < cnt; i++){
    mx[C[i].first] = min(mx[C[i].first], C[i].second);
  }
  for (int i = n - 2; i >= 0; i--){
    mx[i] = min(mx[i], mx[i + 1]);
  }
  int q;
  cin >> q;
  vector<int> l(q), r(q);
  for (int i = 0; i < q; i++){
    cin >> l[i] >> r[i];
    l[i]--;
  }
  vector<vector<int>> L(n + 1), R(n + 1);
  for (int i = 0; i < q; i++){
    L[l[i]].push_back(i);
    R[r[i]].push_back(i);
  }
  lazy_segment_tree<long long> ST(n);
  vector<long long> ans(q, 0);
  for (int i = 0; i <= n; i++){
    for (int j : L[i]){
      ans[j] -= ST.range_sum(l[j], r[j]);
    }
    for (int j : R[i]){
      ans[j] += ST.range_sum(l[j], r[j]);
    }
    if (i < n){
      ST.range_add(i, mx[i], 1);
    }
  }
  for (int i = 0; i < q; i++){
    cout << ans[i] << "\n";
  }
}