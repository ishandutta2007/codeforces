#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
template <typename T>
struct segment_tree_max{
	int N;
	vector<T> ST;
	segment_tree_max(vector<T> A){
		int n = A.size();
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, -INF);
		for (int i = 0; i < n; i++){
			ST[N - 1 + i] = A[i];
		}
		for (int i = N - 2; i >= 0; i--){
			ST[i] = max(ST[i * 2 + 1], ST[i * 2 + 2]);
		}
	}
	T range_max(int L, int R, int i, int l, int r){
		if (R <= l || r <= L){
			return -INF;
		} else if (L <= l && r <= R){
			return ST[i];
		} else {
			int m = (l + r) / 2;
			return max(range_max(L, R, i * 2 + 1, l, m), range_max(L, R, i * 2 + 2, m, r));
		}
	}
	T range_max(int L, int R){
		return range_max(L, R, 0, 0, N);
	}
};
template <typename T>
struct segment_tree_min{
	int N;
	vector<T> ST;
	segment_tree_min(vector<T> A){
		int n = A.size();
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, INF);
		for (int i = 0; i < n; i++){
			ST[N - 1 + i] = A[i];
		}
		for (int i = N - 2; i >= 0; i--){
			ST[i] = min(ST[i * 2 + 1], ST[i * 2 + 2]);
		}
	}
	void update(int k, T x){
		k += N - 1;
		ST[k] = x;
		while (k > 0){
			k = (k - 1) / 2;
			ST[k] = min(ST[k * 2 + 1], ST[k * 2 + 2]);
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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
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
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      b[a[j]] = j;
    }
    segment_tree_min<int> STb(b);
    segment_tree_min<int> ST1(a);
    segment_tree_max<int> ST2(a);
    int ans = 0;
    int p = 0;
    STb.update(a[0], INF);
    while (p < n - 1){
      int p2;
      if (a[p] < a[p + 1]){
        int r = min(STb.range_min(0, a[p]), n);
        int x = ST2.range_max(p + 1, r);
        p2 = b[x];
      } else {
        int r = min(STb.range_min(a[p] + 1, n), n);
        int x = ST1.range_min(p + 1, r);
        p2 = b[x];
      }
      for (int j = p + 1; j <= p2; j++){
        STb.update(a[j], INF);
      }
      p = p2;
      ans++;
    }
    cout << ans << endl;
  }
}