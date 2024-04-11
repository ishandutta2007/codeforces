#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000;
template <typename T>
struct segment_tree_beats{
	int N;
	vector<T> min1, min2;
	vector<T> add, sum;
	vector<int> minc, len;
	void update_min(int i, T x){
		sum[i] += (x - min1[i]) * minc[i];
		min1[i] = x;
	}
	void update_add(int i, T x){
		min1[i] += x;
		if (min2[i] != INF){
			min2[i] += x;
		}
		sum[i] += x * len[i];
		add[i] += x;
	}
	void push(int i){
		if (i >= N - 1){
			return;
		}
		int l = i * 2 + 1;
		int r = i * 2 + 2;
		if (add[i] != 0){
			update_add(l, add[i]);
			update_add(r, add[i]);
			add[i] = 0;
		}
		if (min1[i] > min1[l]){
			update_min(l, min1[i]);
		}
		if (min1[i] > min1[r]){
			update_min(r, min1[i]);
		}
	}
	void update(int i){
		int l = i * 2 + 1;
		int r = i * 2 + 2;
		sum[i] = sum[l] + sum[r];
		if (min1[l] < min1[r]){
			min1[i] = min1[l];
			min2[i] = min(min2[l], min1[r]);
			minc[i] = minc[l];
		} else if (min1[l] > min1[r]){
			min1[i] = min1[r];
			min2[i] = min(min1[l], min2[r]);
			minc[i] = minc[r];
		} else {
			min1[i] = min1[l];
			min2[i] = min(min2[l], min2[r]);
			minc[i] = minc[l] + minc[r];
		}
	}
	segment_tree_beats(vector<T> A){
		int n = A.size();
		N = 1;
		while (N < n){
			N *= 2;
		}
		min1 = vector<T>(N * 2 - 1, INF);
		min2 = vector<T>(N * 2 - 1, INF);
		add = vector<T>(N * 2 - 1, 0);
		sum = vector<T>(N * 2 - 1, 0);
		minc = vector<int>(N * 2 - 1, 0);
		len = vector<int>(N * 2 - 1, 1);
		for (int i = 0; i < n; i++){
			min1[N - 1 + i] = A[i];
			sum[N - 1 + i] = A[i];
			minc[N - 1 + i] = 1;
		}
		for (int i = N - 2; i >= 0; i--){
			len[i] = len[i * 2 + 1] + len[i * 2 + 2];
			update(i);
		}
	}
	void range_chmax(int L, int R, T x, int i, int l, int r){
		if (r <= L || R <= l || x <= min1[i]){
			return;
		} else if (L <= l && r <= R && x < min2[i]){
			update_min(i, x);
			return;
		}
		push(i);
		int m = (l + r) / 2;
		range_chmax(L, R, x, i * 2 + 1, l, m);
		range_chmax(L, R, x, i * 2 + 2, m, r);
		update(i);
	}
	void range_chmax(int L, int R, T x){
		range_chmax(L, R, x, 0, 0, N);
	}
	void range_add(int L, int R, T x, int i, int l, int r){
		if (r <= L || R <= l){	
			return;
		} else if (L <= l && r <= R){
			update_add(i, x);
			return;
		}
		push(i);
		int m = (l + r) / 2;
		range_add(L, R, x, i * 2 + 1, l, m);
		range_add(L, R, x, i * 2 + 2, m, r);
		update(i);
	}
	void range_add(int L, int R, T x){
		range_add(L, R, x, 0, 0, N);
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
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string s;
  cin >> s;
  segment_tree_beats<long long> ST(vector<long long>(n, 0));
  int prev = n;
  long long ans = 0;
  int curr = 0, mx = 0;
  for (int i = n - 1; i >= 0; i--){
    if (s[i] == '0'){
      curr = 0;
      prev = i;
    } else {
      curr++;
      ST.range_add(i, prev, 1);
      ST.range_chmax(prev, n, curr);
      mx = max(mx, curr);
    }
    ans += ST.range_sum(0, n);
  }
  cout << ans << endl;
}