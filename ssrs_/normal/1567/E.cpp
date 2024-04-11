#include <bits/stdc++.h>
using namespace std;
struct monoid{
  array<array<long long, 3>, 3> M;
  monoid(){
    M[0] = {1, 0, 0};
    M[1] = {0, 1, 0};
    M[2] = {0, 0, 1};
  }
  monoid(int x){
    if (x < 0){
      M[0] = {0, 0, 0};
      M[1] = {0, 1, 0};
      M[2] = {1, 1, 1};
    } else {
      M[0] = {1, 1, 0};
      M[1] = {0, 1, 0};
      M[2] = {1, 1, 1};
    }
  }
};
monoid f(monoid A, monoid B){
  monoid C;
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      C.M[i][j] = 0;
    }
  }
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      for (int k = 0; k < 3; k++){
        C.M[i][k] += A.M[i][j] * B.M[j][k];
      }
    }
  }
  return C;
}
template <typename T>
struct segment_tree{
	int N;
	vector<T> ST;
	function<T(T, T)> f;
	T E;
	segment_tree(int n, function<T(T, T)> f, T E): f(f), E(E){
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, E);
	}
	T operator [](int k){
		return ST[N - 1 + k];
	}
	void update(int k, T x){
		k += N - 1;
		ST[k] = x;
		while (k > 0){
			k = (k - 1) / 2;
			ST[k] = f(ST[k * 2 + 1], ST[k * 2 + 2]);
		}
	}
	T query(int L, int R, int i, int l, int r){
		if (R <= l || r <= L){
			return E;
		} else if (L <= l && r <= R){
			return ST[i];
		} else {
			int m = (l + r) / 2;
			return f(query(L, R, i * 2 + 1, l, m), query(L, R, i * 2 + 2, m, r));
		}
	}
	T query(int L, int R){
		return query(L, R, 0, 0, N);
	}
	T all(){
		return ST[0];
	}
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  segment_tree<monoid> ST(n - 1, f, monoid());
  for (int i = 0; i < n - 1; i++){
    ST.update(i, monoid(a[i + 1] - a[i]));
  }
  for (int i = 0; i < q; i++){
    int t;
    cin >> t;
    if (t == 1){
      int x, y;
      cin >> x >> y;
      x--;
      a[x] = y;
      if (x > 0){
        ST.update(x - 1, monoid(a[x] - a[x - 1]));
      }
      if (x < n - 1){
        ST.update(x, monoid(a[x + 1] - a[x]));
      }
    }
    if (t == 2){
      int l, r;
      cin >> l >> r;
      l--;
      monoid res = ST.query(l, r - 1);
      cout << res.M[0][1] + res.M[1][1] + res.M[2][1] << "\n";
    }
  }
}