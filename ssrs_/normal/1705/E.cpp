#include <bits/stdc++.h>
using namespace std;
const int MAX = 200020;
const int e = -1;
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
		lazy = vector<T>(N * 2 - 1, e);
		for (int i = 0; i < n; i++){
			ST[N - 1 + i] = A[i];
		}
		for (int i = N - 2; i >= 0; i--){
			ST[i] = ST[i * 2 + 1] + ST[i * 2 + 2];
		}
	}
	void eval(int i, int l, int r){
		if (lazy[i] != e){
			if (i < N - 1){
				lazy[i * 2 + 1] = lazy[i];
				lazy[i * 2 + 2] = lazy[i];
			}
			ST[i] = lazy[i] * (r - l);
			lazy[i] = e;
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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> cnt(MAX, 0);
  for (int i = 0; i < n; i++){
    cnt[a[i]]++;
  }
  for (int i = 0; i < MAX - 1; i++){
    cnt[i + 1] += cnt[i] / 2;
    cnt[i] %= 2;
  }
  lazy_segment_tree<int> ST(cnt);
  for (int i = 0; i < q; i++){
    int k, l;
    cin >> k >> l;
    k--;
    if (ST.range_sum(a[k], a[k] + 1) == 1){
      ST.range_update(a[k], a[k] + 1, 0);
    } else {
      int tv = MAX, fv = a[k] + 1;
      while (tv - fv > 1){
        int mid = (tv + fv) / 2;
        if (ST.range_sum(a[k], mid) > 0){
          tv = mid;
        } else {
          fv = mid;
        }
      }
      ST.range_update(fv, fv + 1, 0);
      ST.range_update(a[k], fv, 1);
    }
    a[k] = l;
    if (ST.range_sum(a[k], a[k] + 1) == 0){
      ST.range_update(a[k], a[k] + 1, 1);
    } else {
      int tv = MAX, fv = a[k] + 1;
      while (tv - fv > 1){
        int mid = (tv + fv) / 2;
        if (ST.range_sum(a[k], mid) < mid - a[k]){
          tv = mid;
        } else {
          fv = mid;
        }
      }
      ST.range_update(fv, fv + 1, 1);
      ST.range_update(a[k], fv, 0);
    }
    int tv = 0, fv = MAX;
    while (fv - tv > 1){
      int mid = (tv + fv) / 2;
      if (ST.range_sum(mid, MAX) > 0){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    cout << tv << "\n";
  }
}