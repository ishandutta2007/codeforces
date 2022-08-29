#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
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
			ans = max(ans, ST[k]);
		}
		return ans;
	}
	void range_chmax(int L, int R, T x, int i, int l, int r){
		if (R <= l || r <= L){
			return;
		} else if (L <= l && r <= R){
			ST[i] = max(ST[i], x);
			return;
		} else {
			int m = (l + r) / 2;
			range_chmax(L, R, x, i * 2 + 1, l, m);
			range_chmax(L, R, x, i * 2 + 2, m, r);
			return;
		}
	}
	void range_chmax(int L, int R, T x){
		range_chmax(L, R, x, 0, 0, N);
	}
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> l(m), r(m);
    for (int j = 0; j < m; j++){
      cin >> l[j] >> r[j];
      l[j]--;
    }
    vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (int j = 0; j < n; j++){
      a[j] = lower_bound(b.begin(), b.end(), a[j]) - b.begin();
    }
    vector<vector<int>> p(n);
    for (int j = 0; j < n; j++){
      p[a[j]].push_back(j);
    }
    vector<int> mx(n, 0);
    for (int j = 0; j < m; j++){
      mx[l[j]] = max(mx[l[j]], r[j]);
    }
    for (int j = 0; j < n - 1; j++){
      mx[j + 1] = max(mx[j + 1], mx[j]);
    }
    dual_segment_tree<int> ST(n);
    for (int j = 0; j < n; j++){
      int cnt = p[j].size();
      for (int k = 0; k < cnt; k++){
        auto itr = lower_bound(p[j].begin(), p[j].end(), mx[p[j][k]]);
        if (itr != p[j].begin()){
          if (itr != p[j].begin() + 1){
            int x = *prev(itr, 2);
            ST.range_chmax(0, p[j][k] + 1, x + 1);
          }
          int x = *prev(itr);
          ST.range_chmax(p[j][k] + 1, n, x + 1);
        }
        if (k < cnt - 1){
          if (p[j][k + 1] < mx[p[j][k]]){
            ST.range_chmax(p[j][k + 1] + 1, n, INF);
          }
        }
      }
    }
    int ans = INF;
    for (int j = 0; j < n; j++){
      ans = min(ans, max(ST[j] - j, 0));
    }
    cout << ans << endl;
  }
}