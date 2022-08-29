#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
long long calc(vector<long long> &sum, vector<long long> &odd, vector<long long> &even, int L, int R){
  long long P = 0, C = 0;
  C += sum[L];
  if (L % 2 == 0){
    P += even[R] - even[L];
    C += odd[R] - odd[L];
  } else {
    P += odd[R] - odd[L];
    C += even[R] - even[L];
  }
  P += sum.back() - sum[R];
  return P - C;
}
template <typename T>
struct binary_indexed_tree{
	int N;
	vector<T> BIT;
	binary_indexed_tree(int N): N(N), BIT(N + 1, 0){
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
    }
    vector<long long> sum(n + 1, 0), odd(n + 1, 0), even(n + 1, 0);
    for (int j = 0; j < n; j++){
      sum[j + 1] = sum[j] + a[j];
      odd[j + 1] = odd[j];
      if (j % 2 == 1){
        odd[j + 1] += a[j];
      }
      even[j + 1] = even[j];
      if (j % 2 == 0){
        even[j + 1] += a[j];
      }
    }
    long long ans = 0;
    for (int j = 2; j <= n - 2; j++){
      long long P = sum[j], C = sum[n] - sum[j];
      if (C < P){
        ans++;
      }
    }
    for (int L = 0; L < min(n, 3); L++){
      for (int R = L; R <= n; R += 2){
        long long d = calc(sum, odd, even, L, R);
        if (d > 0){
          ans++;
          if (R <= n - 3){
            if (d > a[n - 1] * 2){
              ans++;
            }
          }
        }
      }
    }
    for (int L = 3; L <= n; L++){
      for (int R = max(n - 2, 0); R <= n; R++){
        if (L <= R && (R - L) % 2 == 0){  
          long long d = calc(sum, odd, even, L, R);
          if (d > 0){
            ans++;
          }
          if (d + a[0] * 2 > 0){
            ans++;
          }
        }
      }
    }
    for (int left = 0; left < 2; left++){
      for (int right = 0; right < 2; right++){
        for (int parity = 0; parity < 2; parity++){
          vector<long long> X, Y;
          int cnt = 0;
          for (int p = 3; p <= n - 3; p++){
            if (p % 2 == parity){
              long long x, y;
              if (parity == 0){
                x = sum[p] + even[p] - odd[p];
                y = sum[n] - sum[p] + even[p] - odd[p];
              }
              if (parity == 1){
                x = sum[p] + odd[p] - even[p];
                y = sum[n] - sum[p] + odd[p] - even[p];
              }
              if (left == 1){
                y += a[0] * 2;
              }
              if (right == 1){
                x += a[n - 1] * 2;
              }
              X.push_back(x);
              Y.push_back(y);
              cnt++;
            }
          }
          vector<long long> C;
          for (int j = 0; j < cnt; j++){
            C.push_back(X[j]);
            C.push_back(Y[j]);
          }
          sort(C.begin(), C.end());
          C.erase(unique(C.begin(), C.end()), C.end());
          for (int j = 0; j < cnt; j++){
            X[j] = lower_bound(C.begin(), C.end(), X[j]) - C.begin();
            Y[j] = lower_bound(C.begin(), C.end(), Y[j]) - C.begin();
          }
          int cnt2 = C.size();
          binary_indexed_tree<int> BIT(cnt2);
          for (int j = 0; j < cnt; j++){
            BIT.add(X[j], 1);
            ans += BIT.sum(Y[j]);
          }
        }
      }
    }
    ans %= MOD;
    cout << ans << endl;
  }
}