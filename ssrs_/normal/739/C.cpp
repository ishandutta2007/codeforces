#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
long long INF = 1000000000000000000;
template <typename T>
struct range_add_range_minmax{
	int N;
	vector<T> ST_min;
	vector<T> ST_max;
	vector<T> lazy;
	range_add_range_minmax(vector<T> &A){
		int n = A.size();
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST_min = vector<T>(N * 2 - 1, INF);
		ST_max = vector<T>(N * 2 - 1, -INF);
		lazy = vector<T>(N * 2 - 1, 0);
		for (int i = 0; i < n; i++){
			ST_min[N - 1 + i] = A[i];
			ST_max[N - 1 + i] = A[i];
		}
		for (int i = N - 2; i >= 0; i--){
			ST_min[i] = min(ST_min[i * 2 + 1], ST_min[i * 2 + 2]);
			ST_max[i] = max(ST_max[i * 2 + 1], ST_max[i * 2 + 2]);
		}
	}
	void eval(int i){
		if (i < N - 1){
			lazy[i * 2 + 1] += lazy[i];
			lazy[i * 2 + 2] += lazy[i];
		}
		ST_min[i] += lazy[i];
		ST_max[i] += lazy[i];
		lazy[i] = 0;
	}
	void range_add(int L, int R, T x, int i, int l, int r){
		eval(i);
		if (R <= l || r <= L){
			return;
		} else if (L <= l && r <= R){
			lazy[i] += x;
			eval(i);
		} else {
			int m = (l + r) / 2;
			range_add(L, R, x, i * 2 + 1, l, m);
			range_add(L, R, x, i * 2 + 2, m, r);
			ST_min[i] = min(ST_min[i * 2 + 1], ST_min[i * 2 + 2]);
			ST_max[i] = max(ST_max[i * 2 + 1], ST_max[i * 2 + 2]);
		}
	}
	void range_add(int L, int R, int x){
		range_add(L, R, x, 0, 0, N);
	}
	T range_min(int L, int R, int i, int l, int r){
		eval(i);
		if (R <= l || r <= L){
			return INF;
		} else if (L <= l && r <= R){
			return ST_min[i];
		} else {
			int m = (l + r) / 2;
			return min(range_min(L, R, i * 2 + 1, l, m), range_min(L, R, i * 2 + 2, m, r));
		}
	}
	T range_min(int L, int R){
		return range_min(L, R, 0, 0, N);
	}
	T range_max(int L, int R, int i, int l, int r){
		eval(i);
		if (R <= l || r <= L){
			return -INF;
		} else if (L <= l && r <= R){
			return ST_max[i];
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
struct RAQ{
	int N;
	vector<T> ST;
	RAQ(vector<T> A){
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
struct segment_tree{
  int N;
  vector<int> all, left, right, mid;
  segment_tree(int n){
    N = 1;
    while (N < n){
      N *= 2;
    }
    all = vector<int>(N * 2 - 1, 0);
    left = vector<int>(N * 2 - 1, 0);
    right = vector<int>(N * 2 - 1, 0);
    mid = vector<int>(N * 2 - 1, 0);
  }
  void eval(int i){
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    if (all[l] != 0 && all[r] != 0){
      all[i] = all[l] + all[r];
    } else {
      all[i] = 0;
    }
    if (all[l] != 0){
      left[i] = all[l] + left[r];
    } else {
      left[i] = left[l];
    }
    if (all[r] != 0){
      right[i] = right[l] + all[r];
    } else {
      right[i] = right[r];
    }
    mid[i] = max({mid[l], right[l] + left[r], mid[r]});
  }
  void update(int i, int x){
    //cout << "update " << i << endl;
    i += N - 1;
    all[i] = x;
    left[i] = x;
    right[i] = x;
    mid[i] = x;
    while (i > 0){
      i = (i - 1) / 2;
      eval(i);
    }
  }
  int query(){
    return mid[0];
  }
  int operator [](int i){
    return all[i + N - 1];
  }
  void debug(int n){
    cout << "all:";
    for (int i = N - 1; i < N - 1 + n; i++){
      cout << ' ' << all[i];
    }
    cout << endl;
    cout << "left:";
    for (int i = N - 1; i < N - 1 + n; i++){
      cout << ' ' << left[i];
    }
    cout << endl;
    cout << "right:";
    for (int i = N - 1; i < N - 1 + n; i++){
      cout << ' ' << right[i];
    }
    cout << endl;
    cout << "mid:";
    for (int i = N - 1; i < N - 1 + n; i++){
      cout << ' ' << mid[i];
    }
    cout << endl;
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> a(n + 2, INF);
  for (int i = 1; i <= n; i++){
    cin >> a[i];
  }
  range_add_range_minmax<long long> ST1(a);
  RAQ<long long> ST2(a);
  segment_tree ST3(n);
  for (int i = 1; i < n - 1; i++){
    long long left = ST2[i];
    long long mid = ST2[i + 1];
    long long right = ST2[i + 2];
    if (left < mid && mid < right || left < mid && mid > right || left > mid && mid > right){
      ST3.update(i, 1);
    }
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++){
    int l, r;
    long long d;
    cin >> l >> r >> d;
    //add cubes
    r++;
    ST1.range_add(l, r, d);
    ST2.range_add(l, r, d);
    //update segment tree 2
    if (l > 2){
      //l-2
      long long left = ST2[l - 2];
      long long mid = ST2[l - 1];
      long long right = ST2[l];
      if (left < mid && mid < right || left < mid && mid > right || left > mid && mid > right){
        ST3.update(l - 2, 1);
      } else {
        ST3.update(l - 2, 0);
      }
    }
    if (l > 1 && l < n){
      //l-1
      long long left = ST2[l - 1];
      long long mid = ST2[l];
      long long right = ST2[l + 1];
      if (left < mid && mid < right || left < mid && mid > right || left > mid && mid > right){
        ST3.update(l - 1, 1);
      } else {
        ST3.update(l - 1, 0);
      }
    }
    if (r <= n && r > 2){
      //r-2
      long long left = ST2[r - 2];
      long long mid = ST2[r - 1];
      long long right = ST2[r];
      if (left < mid && mid < right || left < mid && mid > right || left > mid && mid > right){
        ST3.update(r - 2, 1);
      } else {
        ST3.update(r - 2, 0);
      }
    }
    if (r < n){
      //r-1
      long long left = ST2[r - 1];
      long long mid = ST2[r];
      long long right = ST2[r + 1];
      if (left < mid && mid < right || left < mid && mid > right || left > mid && mid > right){
        ST3.update(r - 1, 1);
      } else {
        ST3.update(r - 1, 0);
      }
    }
    /*
    for (int j = 0; j <= n + 1; j++){
      cout << ST2[j] << ' ';
    }
    cout << endl;
    ST3.debug(n);
    */
    if (ST1.range_min(1, n + 1) == ST1.range_max(1, n + 1)){
      cout << 1 << "\n";
    } else {
      cout << ST3.query() + 2 << "\n";
    }
  }
}