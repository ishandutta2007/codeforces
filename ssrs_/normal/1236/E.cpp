#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct dual_segment_tree{
	int N;
	vector<T> ST;
	dual_segment_tree(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, 0);
	}
	dual_segment_tree(vector<T> A){
		int n = A.size();
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, 0);
		for (int i = 0; i < n; i++){
			ST[N - 1 + i] = A[i];
		}
	}
	T operator [](int k){
		k += N - 1;
		T ans = ST[k];
		while (k > 0){
			k = (k - 1) / 2;
			ans += ST[k];
		}
		return ans;
	}
	void range_add(int L, int R, T x, int i, int l, int r){
		if (R <= l || r <= L){
			return;
		} else if (L <= l && r <= R){
			ST[i] += x;
			return;
		} else {
			int m = (l + r) / 2;
			range_add(L, R, x, i * 2 + 1, l, m);
			range_add(L, R, x, i * 2 + 2, m, r);
			return;
		}
	}
	void range_add(int L, int R, T x){
		range_add(L, R, x, 0, 0, N);
	}
	void all_add(T x){
		ST[0] += x;
	}
};
int main(){
  int n, m;
  cin >> n >> m;
  if (n == 1){
    cout << 0 << endl;
    return 0;
  }
  vector<int> a(m);
  for (int i = 0; i < m; i++){
    cin >> a[i];
    a[i]--;
  }
  vector<int> tmp(n);
  for (int i = 0; i < n; i++){
    tmp[i] = i;
  }
  dual_segment_tree<int> L(tmp), R(tmp);
  for (int i = 0; i < m; i++){
    L.all_add(-1);
    int tv1 = n;
    int fv1 = -1;
    while (tv1 - fv1 > 1){
      int mid = (tv1 + fv1) / 2;
      if (L[mid] >= a[i]){
        tv1 = mid;
      } else {
        fv1 = mid;
      }
    }
    int tv2 = n;
    int fv2 = -1;
    while (tv2 - fv2 > 1){
      int mid = (tv2 + fv2) / 2;
      if (L[mid] > a[i]){
        tv2 = mid;
      } else {
        fv2 = mid;
      }
    }
    L.range_add(tv1, tv2, 1);
    R.all_add(1);
    int tv3 = n;
    int fv3 = -1;
    while (tv3 - fv3 > 1){
      int mid = (tv3 + fv3) / 2;
      if (R[mid] >= a[i]){
        tv3 = mid;
      } else {
        fv3 = mid;
      }
    }
    int tv4 = n;
    int fv4 = -1;
    while (tv4 - fv4 > 1){
      int mid = (tv4 + fv4) / 2;
      if (R[mid] > a[i]){
        tv4 = mid;
      } else {
        fv4 = mid;
      }
    }
    R.range_add(tv3, tv4, -1);
  }
  L.all_add(-1);
  R.all_add(1);
  long long ans = 0;
  for (int i = 0; i < n; i++){
    int l = max(L[i], 0);
    int r = min(R[i], n - 1);
    ans += r - l + 1;
  }
  cout << ans << endl;
}