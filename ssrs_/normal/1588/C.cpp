#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000000;
template <typename T>
struct sparse_table_min{
	vector<vector<T>> ST;
	sparse_table_min(vector<T> &A){
		int N = A.size();
		int LOG = 32 - __builtin_clz(N);
		ST = vector<vector<T>>(LOG, vector<T>(N));
		for (int i = 0; i < N; i++){
			ST[0][i] = A[i];
		}
		for (int i = 0; i < LOG - 1; i++){
			for (int j = 0; j < N - (1 << i); j++){
				ST[i + 1][j] = min(ST[i][j], ST[i][j + (1 << i)]);
			}
		}
	}
	T range_min(int L, int R){
		int d = 31 - __builtin_clz(R - L);
		return min(ST[d][L], ST[d][R - (1 << d)]);
	}
};
template <typename T>
struct sparse_table_max{
	vector<vector<T>> ST;
	sparse_table_max(vector<T> &A){
		int N = A.size();
		int LOG = 32 - __builtin_clz(N);
		ST = vector<vector<T>>(LOG, vector<T>(N));
		for (int i = 0; i < N; i++){
			ST[0][i] = A[i];
		}
		for (int i = 0; i < LOG - 1; i++){
			for (int j = 0; j < N - (1 << i); j++){
				ST[i + 1][j] = max(ST[i][j], ST[i][j + (1 << i)]);
			}
		}
	}
	T range_max(int L, int R){
		int d = 31 - __builtin_clz(R - L);
		return max(ST[d][L], ST[d][R - (1 << d)]);
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
    }
    for (int j = 1; j < n; j += 2){
      a[j] *= -1;
    }
    vector<long long> S(n + 1);
    S[0] = 0;
    for (int j = 0; j < n; j++){
      S[j + 1] = S[j] + a[j];
    }
    map<long long, vector<int>> mp;
    for (int i = 0; i <= n; i++){
      mp[S[i]].push_back(i);
    }
    vector<vector<long long>> M(2);
    for (int j = 0; j <= n; j++){
      M[j % 2].push_back(S[j]);
    }
    sparse_table_max<long long> ST0(M[0]);
    sparse_table_min<long long> ST1(M[1]);
    long long ans = 0;
    for (int j = 0; j <= n; j++){
      int tv = j, fv = n + 1;
      while (fv - tv > 1){
        int mid = (tv + fv) / 2;
        bool ok = true;
        if (j % 2 == 0){
          if (ST0.range_max(j / 2, mid / 2 + 1) > S[j]){
            ok = false;
          }
          if (ST1.range_min(j / 2, (mid + 1) / 2) < S[j]){
            ok = false;
          }
        }
        if (j % 2 == 1){
          if (ST0.range_max((j + 1) / 2, mid / 2 + 1) > S[j]){
            ok = false;
          }
          if (ST1.range_min(j / 2, (mid + 1) / 2) < S[j]){
            ok = false;
          }
        }
        if (ok){
          tv = mid;
        } else {
          fv = mid;
        }
      }
      ans += upper_bound(mp[S[j]].begin(), mp[S[j]].end(), tv) - upper_bound(mp[S[j]].begin(), mp[S[j]].end(), j);
    }
    cout << ans << "\n";
  }
}