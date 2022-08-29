#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
template <typename T>
struct sparse_table{
	vector<vector<T>> ST;
	sparse_table(vector<T> &A){
		int N = A.size();
		int LOG = 32 - __builtin_clz(N);
		ST = vector<vector<int>>(LOG, vector<int>(N));
		for (int i = 0; i < N; i++){
			ST[0][i] = A[i];
		}
		for (int i = 0; i < LOG - 1; i++){
			for (int j = 0; j < N - (1 << i); j++){
				ST[i + 1][j] = min(ST[i][j], ST[i][j + (1 << i)]);
			}
		}
	}
	int range_min(int L, int R){
		int d = 31 - __builtin_clz(R - L);
		return min(ST[d][L], ST[d][R - (1 << d)]);
	}
};
template <typename T>
struct lazy_segment_tree{
	int N;
	vector<T> ST;
	vector<T> lazy;
	lazy_segment_tree(vector<T> A){
		int n = A.size();
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, INF);
		lazy = vector<T>(N * 2 - 1, -1);
		for (int i = 0; i < n; i++){
			ST[N - 1 + i] = A[i];
		}
		for (int i = N - 2; i >= 0; i--){
			ST[i] = min(ST[i * 2 + 1], ST[i * 2 + 2]);
		}
	}
	void eval(int i){
		if (lazy[i] != -1){
			if (i < N - 1){
				lazy[i * 2 + 1] = lazy[i];
				lazy[i * 2 + 2] = lazy[i];
			}
			ST[i] = lazy[i];
			lazy[i] = -1;
		}
	}
	void range_update(int L, int R, T x, int i, int l, int r){
		eval(i);
		if (R <= l || r <= L){
			return;
		} else if (L <= l && r <= R){
			lazy[i] = x;
			eval(i);
		} else {
			int m = (l + r) / 2;
			range_update(L, R, x, i * 2 + 1, l, m);
			range_update(L, R, x, i * 2 + 2, m, r);
			ST[i] = min(ST[i * 2 + 1], ST[i * 2 + 2]);
		}
	}
	void range_update(int L, int R, T x){
		return range_update(L, R, x, 0, 0, N);
	}
	T range_min(int L, int R, int i, int l, int r){
		eval(i);
		if (R <= l || r <= L){
			return INF;
		} else if (L <= l && r <= R){
			return ST[i];
		} else {
			int m = (l + r) / 2;
			return min(range_min(L, R, i * 2 + 1, l, m), range_min(L, R, i * 2 + 2, m, r));
		}
	}
	T range_min(int L, int R){
		return range_min(L, R, 0, 0, N);
	}
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> b(n);
  for (int i = 0; i < n; i++){
    cin >> b[i];
  }
  int q;
  cin >> q;
  vector<tuple<int, int, int, int>> query(q);
  for (int i = 0; i < q; i++){
    int t;
    cin >> t;
    if (t == 1){
      int l, r, x;
      cin >> l >> r >> x;
      l--;
      query[i] = make_tuple(1, l, r, x);
    }
    if (t == 2){
      int l, r;
      cin >> l >> r;
      l--;
      query[i] = make_tuple(2, l, r, -1);
    }
  }
  vector<int> x;
  x.push_back(0);
  x.push_back(n * k);
  for (int i = 0; i < q; i++){
    x.push_back(get<1>(query[i]));
    x.push_back(get<2>(query[i]));
  }
  sort(x.begin(), x.end());
  x.erase(unique(x.begin(), x.end()), x.end());
  for (int i = 0; i < q; i++){
    get<1>(query[i]) = lower_bound(x.begin(), x.end(), get<1>(query[i])) - x.begin();
    get<2>(query[i]) = lower_bound(x.begin(), x.end(), get<2>(query[i])) - x.begin();
  }
  int cnt = x.size() - 1;
  sparse_table<int> ST(b);
  vector<int> a(cnt);
  for (int i = 0; i < cnt; i++){
    int L = x[i];
    int R = x[i + 1];
    if (L / n == (R - 1) / n){
      a[i] = ST.range_min(L % n, (R - 1) % n + 1);
    } else if (L / n == (R - 1) / n - 1){
      a[i] = min(ST.range_min(L % n, n), ST.range_min(0, (R - 1) % n + 1));
    } else {
      a[i] = ST.range_min(0, n);
    }
  }
  lazy_segment_tree<int> ST2(a);
  for (int i = 0; i < q; i++){
    int t = get<0>(query[i]);
    if (t == 1){
      int l = get<1>(query[i]);
      int r = get<2>(query[i]);
      int x = get<3>(query[i]);
      ST2.range_update(l, r, x);
    }
    if (t == 2){
      int l = get<1>(query[i]);
      int r = get<2>(query[i]);
      cout << ST2.range_min(l, r) << "\n";
    }
  }
}