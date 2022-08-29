#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000001;
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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> l(n), r(n);
  for (int i = 0; i < n; i++){
    l[i] = max(a[i] - k, 1);
    r[i] = a[i] + 1;
  }
  vector<vector<int>> L(MAX);
  for (int i = 0; i < n; i++){
    L[r[i] - l[i]].push_back(i);
  }
  int cnt = 0;
  dual_segment_tree<int> ST(MAX);
  int ans = 0;
  for (int i = 1; i < MAX; i++){
    for (int j : L[i]){
      ST.range_add(l[j], r[j], 1);
      cnt++;
    }
    int c = n - cnt;
    for (int j = i; j < MAX; j += i){
      c += ST[j];
    }
    if (c == n){
      ans = i;
    }
  }
  cout << ans << endl;
}