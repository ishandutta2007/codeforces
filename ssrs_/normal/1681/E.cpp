#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000;
struct monoid{
  long long d11, d12, d21, d22;
  monoid(): d11(0), d12(INF), d21(INF), d22(0){
  }
};
monoid f(monoid L, monoid R){
  monoid ans;
  ans.d11 = min(L.d11 + R.d11, L.d12 + R.d21);
  ans.d12 = min(L.d11 + R.d12, L.d12 + R.d22);
  ans.d21 = min(L.d21 + R.d11, L.d22 + R.d21);
  ans.d22 = min(L.d21 + R.d12, L.d22 + R.d22);
  return ans;
}
template <typename T>
struct segment_tree{
	int N;
	vector<T> ST;
	function<T(T, T)> f;
	T E;
	segment_tree(vector<T> A, function<T(T, T)> f, T E): f(f), E(E){
		int n = A.size();
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, E);
		for (int i = 0; i < n; i++){
			ST[N - 1 + i] = A[i];
		}
		for (int i = N - 2; i >= 0; i--){
			ST[i] = f(ST[i * 2 + 1], ST[i * 2 + 2]);
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
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> d1x(n - 1), d1y(n - 1), d2x(n - 1), d2y(n - 1);
  for (int i = 0; i < n - 1; i++){
    cin >> d1x[i] >> d1y[i] >> d2x[i] >> d2y[i];
    d1x[i]--;
    d1y[i]--;
    d2x[i]--;
    d2y[i]--;
  }
  vector<monoid> A(n - 2);
  for (int i = 0; i < n - 2; i++){
    A[i].d11 = abs(d1x[i] + 1 - d1x[i + 1]) + abs(d1y[i] - d1y[i + 1]) + 1;
    A[i].d12 = abs(d1x[i] + 1 - d2x[i + 1]) + abs(d1y[i] - d2y[i + 1]) + 1;
    A[i].d21 = abs(d2x[i] - d1x[i + 1]) + abs(d2y[i] + 1 - d1y[i + 1]) + 1;
    A[i].d22 = abs(d2x[i] - d2x[i + 1]) + abs(d2y[i] + 1 - d2y[i + 1]) + 1;
  }
  segment_tree<monoid> ST(A, f, monoid());
  int m;
  cin >> m;
  for (int i = 0; i < m; i++){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--;
    y1--;
    x2--;
    y2--;
    int p1 = max(x1, y1);
    int p2 = max(x2, y2);
    if (p1 == p2){
      cout << abs(x1 - x2) + abs(y1 - y2) << "\n";
    } else {
      if (p1 > p2){
        swap(x1, x2);
        swap(y1, y2);
        swap(p1, p2);
      }
      if (p2 == p1 + 1){
        long long ans = INF;
        ans = min(ans, (long long) abs(x1 - d1x[p1]) + abs(y1 - d1y[p1]) + 1 + abs(d1x[p1] + 1 - x2) + abs(d1y[p1] - y2));
        ans = min(ans, (long long) abs(x1 - d2x[p1]) + abs(y1 - d2y[p1]) + 1 + abs(d2x[p1] - x2) + abs(d2y[p1] + 1 - y2));
        cout << ans << "\n";
      } else {
        monoid R = ST.query(p1, p2 - 1);
        long long ans = INF;
        ans = min(ans, abs(x1 - d1x[p1]) + abs(y1 - d1y[p1]) + R.d11 + 1 + abs(d1x[p2 - 1] + 1 - x2) + abs(d1y[p2 - 1] - y2));
        ans = min(ans, abs(x1 - d1x[p1]) + abs(y1 - d1y[p1]) + R.d12 + 1 + abs(d2x[p2 - 1] - x2) + abs(d2y[p2 - 1] + 1 - y2));
        ans = min(ans, abs(x1 - d2x[p1]) + abs(y1 - d2y[p1]) + R.d21 + 1 + abs(d1x[p2 - 1] + 1 - x2) + abs(d1y[p2 - 1] - y2));
        ans = min(ans, abs(x1 - d2x[p1]) + abs(y1 - d2y[p1]) + R.d22 + 1 + abs(d2x[p2 - 1] - x2) + abs(d2y[p2 - 1] + 1 - y2));
        cout << ans << "\n";
      }
    }
  }
}