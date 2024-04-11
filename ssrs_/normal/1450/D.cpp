#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
template <typename T>
struct segment_tree{
	int N;
	vector<T> ST;
	segment_tree(vector<T> a){
		int n = a.size();
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, INF);
		for (int i = 0; i < n; i++){
			ST[N - 1 + i] = a[i];
		}
		for (int i = N - 2; i >= 0; i--){
			ST[i] = min(ST[i * 2 + 1], ST[i * 2 + 2]);
		}
	}
	T range_min(int L, int R, int i, int l, int r){
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
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
      a[j]--;
    }
    segment_tree<int> ST(a);
    vector<int> ans(n, 1);
    vector<int> b = a;
    sort(b.begin(), b.end());
    for (int j = 0; j < n; j++){
      if (b[j] != j){
        ans[0] = 0;
      }
    }
    int tv = n + 1;
    int fv = 1;
    while (tv - fv > 1){
      int mid = (tv + fv) / 2;
      vector<int> p(n - mid + 1);
      for (int j = 0; j <= n - mid; j++){
        p[j] = ST.range_min(j, j + mid);
      }
      sort(p.begin(), p.end());
      bool ok = true;
      for (int j = 0; j <= n - mid; j++){
        if (p[j] != j){
          ok = false;
        }
      }
      if (ok){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    for (int j = 1; j < fv; j++){
      ans[j] = 0;
    }
    for (int j = fv; j < n; j++){
      ans[j] = 1;
    }
    for (int j = 0; j < n; j++){
      cout << ans[j];
    }
    cout << "\n";
  }
}