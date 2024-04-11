#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
long long modpow(long long a, long long b){
	long long ans = 1;
	while (b > 0){
		if (b % 2 == 1){
			ans *= a;
			ans %= MOD;
		}
		a *= a;
		a %= MOD;
		b /= 2;
	}
	return ans;
}
long long modinv(long long a){
	return modpow(a, MOD - 2);
}
vector<long long> mf = {1};
vector<long long> mfi = {1};
long long modfact(int n){
	if (mf.size() > n){
		return mf[n];
	} else {
		for (int i = mf.size(); i <= n; i++){
			long long next = mf.back() * i % MOD;
			mf.push_back(next);
			mfi.push_back(modinv(next));
		}
		return mf[n];
	}
}
long long modfactinv(int n){
	if (mfi.size() > n){
		return mfi[n];
	} else {
		return modinv(modfact(n));
	}
}
long long modbinom(int n, int k){
	if (n < 0 || k < 0 || k > n){
		return 0;
	} else {
		return modfact(n) * modfactinv(k) % MOD * modfactinv(n - k) % MOD;
	}
}
template <typename T>
struct lazy_segment_tree{
	int N;
	vector<T> ST;
	vector<T> lazy;
	lazy_segment_tree(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, 0);
		lazy = vector<T>(N * 2 - 1, -1);
	}
	void eval(int i, int l, int r){
		if (lazy[i] != -1){
			if (i < N - 1){
				lazy[i * 2 + 1] = lazy[i];
				lazy[i * 2 + 2] = lazy[i];
			}
			ST[i] = lazy[i] * (r - l);
			lazy[i] = -1;
		}
	}
	void range_update(int L, int R, T x, int i, int l, int r){
		eval(i, l, r);
		if (R <= l || r <= L){
			return;
		} else if (L <= l && r <= R){
			lazy[i] = x;
			eval(i, l, r);
		} else {
			int m = (l + r) / 2;
			range_update(L, R, x, i * 2 + 1, l, m);
			range_update(L, R, x, i * 2 + 2, m, r);
			ST[i] = ST[i * 2 + 1] + ST[i * 2 + 2];
		}
	}
	void range_update(int L, int R, T x){
		range_update(L, R, x, 0, 0, N);
	}
	T range_sum(int L, int R, int i, int l, int r){
		eval(i, l, r);
		if (R <= l || r <= L){
			return 0;
		} else if (L <= l && r <= R){
			return ST[i];
		} else {
			int m = (l + r) / 2;
			return range_sum(L, R, i * 2 + 1, l, m) + range_sum(L, R, i * 2 + 2, m, r);
		}
	}
	T range_sum(int L, int R){
		return range_sum(L, R, 0, 0, N);
	}
};
template <typename T>
struct dual_segment_tree{
	int N;
	vector<pair<T, int>> ST;
	int t;
	dual_segment_tree(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<pair<T, int>>(N * 2 - 1, make_pair(0, 0));
		t = 1;
	}
	T operator [](int k){
		k += N - 1;
		T ans = ST[k].first;
		T time = ST[k].second;
		while (k > 0){
			k = (k - 1) / 2;
			if (ST[k].second > time){
				ans = ST[k].first;
				time = ST[k].second;
			}
		}
		return ans;
	}
	void range_update(int L, int R, T x, int i, int l, int r){
		if (R <= l || r <= L){
			return;
		} else if (L <= l && r <= R){
			ST[i] = make_pair(x, t);
		} else {
			int m = (l + r) / 2;
			range_update(L, R, x, i * 2 + 1, l, m);
			range_update(L, R, x, i * 2 + 2, m, r);
		}
	}
	void range_update(int L, int R, T x){
		range_update(L, R, x, 0, 0, N);
		t++;
	}
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  lazy_segment_tree<int> ST1(200000);
  dual_segment_tree<int> ST2(200000);
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> x(m), y(m);
    for (int j = 0; j < m; j++){
      cin >> x[j] >> y[j];
      x[j]--;
      y[j]--;
    }
    int lt = 0;
    if (m == 0){
      lt = 0;
    } else {
      int n2 = x[m - 1] + 1;
      ST1.range_update(0, n2, 1);
      vector<int> b(m);
      b[0] = x[0];
      for (int j = 1; j < m; j++){
        b[j] = x[j] - x[j - 1] - 1;
      }
      vector<int> val(m);
      for (int j = m - 1; j >= 0; j--){
        int tv = 0, fv = n2;
        while (fv - tv > 1){
          int mid = (tv + fv) / 2;
          if (ST1.range_sum(0, mid) <= y[j]){
            tv = mid;
          } else {
            fv = mid;
          }
        }
        //insert = tv
        val[j] = tv;
        ST1.range_update(val[j], val[j] + 1, 0);
        if (b[j] > 0){
          int mx_rem;
          int tv2 = n2, fv2 = 0;
          while (tv2 - fv2 > 1){
            int mid = (tv2 + fv2) / 2;
            if (ST1.range_sum(mid, n2) == 0){
              tv2 = mid;
            } else {
              fv2 = mid;
            }
          }
          mx_rem = fv2;
          int tv3 = 0, fv3 = mx_rem + 1;
          while (fv3 - tv3 > 1){
            int mid = (tv3 + fv3) / 2;
            if (ST1.range_sum(mid, mx_rem + 1) >= b[j]){
              tv3 = mid;
            } else {
              fv3 = mid;
            }
          }
          //[tv3,mx_rem]
          ST1.range_update(tv3, mx_rem + 1, 0);
          ST2.range_update(tv3, mx_rem + 1, j * 2);
        }
      }
      for (int j = 0; j < m; j++){
        ST2.range_update(val[j], val[j] + 1, j * 2 + 1);
      }
      for (int j = 0; j < m; j++){
        if (val[j] < n2){
          if (ST2[val[j]] > ST2[val[j] + 1]){
            lt++;
          }
        }
      }
    }
    cout << modbinom(n + (n - 1 - lt), n) << "\n";
  }
}