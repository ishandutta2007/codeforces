#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct dual_segment_tree{
	int N;
	vector<T> ST;
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
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> c(n);
    for (int j = 0; j < n; j++){
      cin >> c[j];
    }
    dual_segment_tree<int> ST(c);
    long long sum = 0;
    for (int j = 0; j < n; j++){
      sum += c[j];
    }
    vector<int> a(n);
    for (int j = n - 1; j >= 0; j--){
      if (sum == 0){
        a[j] = 0;
      } else {
        int cnt = sum / (j + 1);
        sum -= cnt;
        ST.range_add(j + 1 - cnt, j + 1, -1);
        if (ST[j] == j){
          a[j] = 1;
          sum -= j;
        } else {
          a[j] = 0;
        }
      }
    }
    for (int j = 0; j < n; j++){
      cout << a[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}