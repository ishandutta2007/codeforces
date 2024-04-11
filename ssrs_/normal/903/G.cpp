#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
template <typename T>
struct lazy_segment_tree{
	int N;
	vector<T> ST;
	vector<T> lazy;
	lazy_segment_tree(vector<T> &A){
		int n = A.size();
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, INF);
		lazy = vector<T>(N * 2 - 1, 0);
		for (int i = 0; i < n; i++){
			ST[N - 1 + i] = A[i];
		}
		for (int i = N - 2; i >= 0; i--){
			ST[i] = min(ST[i * 2 + 1], ST[i * 2 + 2]);
		}
	}
	void eval(int i){
		if (i < N - 1){
			lazy[i * 2 + 1] += lazy[i];
			lazy[i * 2 + 2] += lazy[i];
		}
		ST[i] += lazy[i];
		lazy[i] = 0;
	}
	void range_add(int L, int R, T x, int i, int l, int r){
		eval(i);
		if (R <= l || r <= L){
			return;
		} else if (L <= l && r <= R){
			lazy[i] += x;
			eval(i);
		} else {
			int m = (l + r) / 2;
			range_add(L, R, x, i * 2 + 1, l, m);
			range_add(L, R, x, i * 2 + 2, m, r);
			ST[i] = min(ST[i * 2 + 1], ST[i * 2 + 2]);
		}
	}
	void range_add(int L, int R, T x){
		range_add(L, R, x, 0, 0, N);
	}
	T all(){
		eval(0);
		return ST[0];
	}
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> x(n - 1), y(n - 1);
  for (int i = 0; i < n - 1; i++){
    cin >> x[i] >> y[i];
  }
  vector<int> x2(m), y2(m), z2(m);
  for (int i = 0; i < m; i++){
    cin >> x2[i] >> y2[i] >> z2[i];
    x2[i]--;
    y2[i]--;
  }
  vector<long long> B(n);
  B[0] = 0;
  for (int i = 0; i < n - 1; i++){
    B[i + 1] = y[i];
  }
  vector<vector<int>> add(n);
  for (int i = 0; i < m; i++){
    add[x2[i]].push_back(i);
  }
  lazy_segment_tree<long long> ST1(B);
  vector<long long> mn(n);
  for (int i = 0; i < n; i++){
    for (int j : add[i]){
      ST1.range_add(0, y2[j] + 1, z2[j]);
    }
    mn[i] = ST1.all();
  }
  for (int i = 0; i < n - 1; i++){
    mn[i] += x[i];
  }
  lazy_segment_tree<long long> ST2(mn);
  for (int i = 0; i <= q; i++){
    cout << ST2.all() << "\n";
    if (i < q){
      int v, w;
      cin >> v >> w;
      v--;
      ST2.range_add(v, v + 1, w - x[v]);
      x[v] = w;
    }
  }
}