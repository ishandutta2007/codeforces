#include <bits/stdc++.h>
using namespace std;
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
		ST = vector<T>(N * 2 - 1, 0);
		lazy = vector<T>(N * 2 - 1, -1);
		for (int i = 0; i < n; i++){
			ST[N - 1 + i] = A[i];
		}
		for (int i = N - 2; i >= 0; i--){
			ST[i] = ST[i * 2 + 1] + ST[i * 2 + 2];
		}
	}
	void eval(int i, int l, int r){
		if (lazy[i] != -1){
			if (i < N - 1){
				lazy[i * 2 + 1] = lazy[i];
				lazy[i * 2 + 2] = lazy[i];
			}
			ST[i] = lazy[i] * (r - l);
			lazy[i] = -1;
		}
	}
	void range_update(int L, int R, T x, int i, int l, int r){
		eval(i, l, r);
		if (R <= l || r <= L){
			return;
		} else if (L <= l && r <= R){
			lazy[i] = x;
			eval(i, l, r);
		} else {
			int m = (l + r) / 2;
			range_update(L, R, x, i * 2 + 1, l, m);
			range_update(L, R, x, i * 2 + 2, m, r);
			ST[i] = ST[i * 2 + 1] + ST[i * 2 + 2];
		}
	}
	void range_update(int L, int R, T x){
		range_update(L, R, x, 0, 0, N);
	}
	T range_sum(int L, int R, int i, int l, int r){
		eval(i, l, r);
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
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    string f;
    cin >> f;
    vector<int> l(q), r(q);
    for (int j = 0; j < q; j++){
      cin >> l[j] >> r[j];
      l[j]--;
    }
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      a[j] = f[j] - '0';
    }
    lazy_segment_tree<int> ST(a);
    bool ok = true;
    for (int j = q - 1; j >= 0; j--){
      int d = r[j] - l[j];
      int s = ST.range_sum(l[j], r[j]);
      if (s * 2 == d){
        ok = false;
        break;
      }
      if (s <= d / 2){
        ST.range_update(l[j], r[j], 0);
      } else {
        ST.range_update(l[j], r[j], 1);
      }
    }
    for (int j = 0; j < n; j++){
      if (ST.range_sum(j, j + 1) != s[j] - '0'){
        ok = false;
      }
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}