#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
template <typename T>
struct binary_indexed_tree{
	int N;
	vector<T> BIT;
	binary_indexed_tree(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		BIT = vector<T>(N + 1, 0);
	}
	void add(int i, T x){
		i++;
		while (i <= N){
			BIT[i] += x;
			i += i & -i;
		}
	}
	T sum(int i){
		T ans = 0;
		while (i > 0){
			ans += BIT[i];
			i -= i & -i;
		}
		return ans;
	}
	T sum(int L, int R){
		return sum(R) - sum(L);
	}
};
template <typename T>
struct binary_indexed_tree_mod{
	int N;
	vector<T> BIT;
	binary_indexed_tree_mod(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		BIT = vector<T>(N + 1, 0);
	}
	void add(int i, T x){
		i++;
		while (i <= N){
			BIT[i] += x;
			BIT[i] %= MOD;
			i += i & -i;
		}
	}
	T sum(int i){
		T ans = 0;
		while (i > 0){
			ans += BIT[i];
			i -= i & -i;
		}
		return ans % MOD;
	}
	T sum(int L, int R){
		return (sum(R) + MOD - sum(L)) % MOD;
	}
};
int main(){
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
    a[i] -= i;
  }
  vector<long long> w(n);
  for (int i = 0; i < n; i++){
    cin >> w[i];
  }
  binary_indexed_tree<long long> BIT1(n);
  binary_indexed_tree_mod<long long> BIT2(n);
  for (int i = 0; i < n; i++){
    BIT1.add(i, w[i]);
    BIT2.add(i, a[i] * w[i]);
  }
  for (int i = 0; i < q; i++){
    int x, y;
    cin >> x >> y;
    if (x < 0){
      int id = -x - 1;
      BIT1.add(id, y - w[id]);
      BIT2.add(id, a[id] * (y - w[id] + MOD) % MOD);
      w[id] = y;
    } else {
      int l = x - 1;
      int r = y;
      long long sum = BIT1.sum(l, r);
      int tv = l;
      int fv = r;
      while (fv - tv > 1){
        int mid = (tv + fv) / 2;
        if (BIT1.sum(l, mid) * 2 <= sum){
          tv = mid;
        } else {
          fv = mid;
        }
      }
      long long ans = 0;
      ans += a[tv] * (BIT1.sum(l, tv) % MOD) % MOD + MOD - BIT2.sum(l, tv);
      ans += BIT2.sum(tv, r) + MOD - a[tv] * (BIT1.sum(tv, r) % MOD) % MOD;
      cout << ans % MOD << endl;
    }
  }
}