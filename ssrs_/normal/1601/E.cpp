#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000;
template <typename T>
struct segment_tree_beats{
	int N;
	vector<T> max1, max2, sum;
	vector<int> maxc;
	void update_max(int i, T x){
		sum[i] += (x - max1[i]) * maxc[i];
		max1[i] = x;
	}
	void push(int i){
		if (i >= N - 1){
			return;
		}
		int l = i * 2 + 1;
		int r = i * 2 + 2;
		if (max1[i] < max1[l]){
			update_max(l, max1[i]);
		}
		if (max1[i] < max1[r]){
			update_max(r, max1[i]);
		}
	}
	void update(int i){
		int l = i * 2 + 1;
		int r = i * 2 + 2;
		sum[i] = sum[l] + sum[r];
		if (max1[l] > max1[r]){
			max1[i] = max1[l];
			max2[i] = max(max2[l], max1[r]);
			maxc[i] = maxc[l];
		} else if (max1[l] < max1[r]){
			max1[i] = max1[r];
			max2[i] = max(max1[l], max2[r]);
			maxc[i] = maxc[r];
		} else {
			max1[i] = max1[l];
			max2[i] = max(max2[l], max2[r]);
			maxc[i] = maxc[l] + maxc[r];
		}
	}
	segment_tree_beats(vector<T> A){
		int n = A.size();
		N = 1;
		while (N < n){
			N *= 2;
		}
		max1 = vector<T>(N * 2 - 1, -INF);
		max2 = vector<T>(N * 2 - 1, -INF);
		sum = vector<T>(N * 2 - 1, 0);
		maxc = vector<int>(N * 2 - 1, 0);
		for (int i = 0; i < n; i++){
			max1[N - 1 + i] = A[i];
			sum[N - 1 + i] = A[i];
			maxc[N - 1 + i] = 1;
		}
		for (int i = N - 2; i >= 0; i--){
			update(i);
		}
	}
	void range_chmin(int L, int R, T x, int i, int l, int r){
		if (r <= L || R <= l || x >= max1[i]){
			return;
		} else if (L <= l && r <= R && x > max2[i]){
			update_max(i, x);
			return;
		}
		push(i);
		int m = (l + r) / 2;
		range_chmin(L, R, x, i * 2 + 1, l, m);
		range_chmin(L, R, x, i * 2 + 2, m, r);
		update(i);
	}
	void range_chmin(int L, int R, T x){
		range_chmin(L, R, x, 0, 0, N);
	}
	T range_sum(int L, int R, int i, int l, int r){
		if (r <= L || R <= l){
			return 0;
		} else if (L <= l && r <= R){
			return sum[i];
		}
		push(i);
		int m = (l + r) / 2;
		return range_sum(L, R, i * 2 + 1, l, m) + range_sum(L, R, i * 2 + 2, m, r);
	}
	T range_sum(int L, int R){
		return range_sum(L, R, 0, 0, N);
	}
};
template <typename T>
struct sparse_table{
	vector<vector<T>> ST;
	sparse_table(vector<T> &A){
		int N = A.size();
		int LOG = 32 - __builtin_clz(N);
		ST = vector<vector<int>>(LOG, vector<int>(N));
		for (int i = 0; i < N; i++){
			ST[0][i] = A[i];
		}
		for (int i = 0; i < LOG - 1; i++){
			for (int j = 0; j < N - (1 << i); j++){
				ST[i + 1][j] = min(ST[i][j], ST[i][j + (1 << i)]);
			}
		}
	}
	int range_min(int L, int R){
		int d = 31 - __builtin_clz(R - L);
		return min(ST[d][L], ST[d][R - (1 << d)]);
	}
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q, k;
  cin >> n >> q >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> l(q), r(q);
  for (int i = 0; i < q; i++){
    cin >> l[i] >> r[i];
    l[i]--;
  }
  vector<vector<int>> id(n);
  for (int i = 0; i < q; i++){
    id[l[i]].push_back(i);
  }
  sparse_table<int> ST1(a);
  vector<long long> ans(q);
  for (int i = 0; i < k; i++){
    int cnt = (n - i + k - 1) / k;
    segment_tree_beats<long long> ST2(vector<long long>(cnt, 1100000000));
    for (int j = cnt - 1; j >= 0; j--){
      int p = i + j * k;
      ST2.range_chmin(j, cnt, a[p]);
      int mn = ST1.range_min(p, min(p + k, n));
      ST2.range_chmin(j + 1, cnt, mn);
      for (int x : id[p]){
        ans[x] = ST2.range_sum(j, j + (r[x] - l[x] + k - 1) / k);
      }
    }
  }
  for (int i = 0; i < q; i++){
    cout << ans[i] << "\n";
  }
}