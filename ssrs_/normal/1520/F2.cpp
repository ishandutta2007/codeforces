#include <bits/stdc++.h>
using namespace std;
const int B = 20;
template <typename T>
struct dual_segment_tree{
	int N;
	vector<T> ST;
	dual_segment_tree(){
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
};
int main(){
  int n, t;
  cin >> n >> t;
  dual_segment_tree<int> ST;
  for (int i = 0; i < t; i++){
    int k;
    cin >> k;
    if (i == 0){
      vector<int> sum(n / B + 1);
      sum[0] = 0;
      for (int j = 0; j < n / B; j++){
        cout << "? 1 " << B * (j + 1) << endl;
        cin >> sum[j + 1];
      }
      ST = dual_segment_tree<int>(sum);
    }
    int tv1 = 0, fv1 = n / B + 1;
    while (fv1 - tv1 > 1){
      int mid = (tv1 + fv1) / 2;
      if (mid * B - ST[mid] < k){
        tv1 = mid;
      } else {
        fv1 = mid;
      }
    }
    int tv2 = tv1 * B, fv2 = min(tv1 * B + B, n);
    while (fv2 - tv2 > 1){
      int mid = (tv2 + fv2) / 2;
      cout << "? 1 " << mid << endl;
      int res;
      cin >> res;
      if (mid - res < k){
        tv2 = mid;
      } else {
        fv2 = mid;
      }
    }
    cout << "! " << fv2 << endl;
    ST.range_add(fv1, n / B + 1, 1);
  }
}