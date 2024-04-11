#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct sparse_table{
	vector<vector<T>> ST;
	sparse_table(vector<T> &A){
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
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<long long> S(n + 1);
    S[0] = 0;
    for (int j = 0; j < n; j++){
      S[j + 1] = S[j] + a[j];
    }
    sparse_table<long long> ST(S);
    int L = 0, R = -1;
    for (int j = 0; j < n; j++){
      int tv = j, fv = n + 1;
      while (fv - tv > 1){
        int mid = (tv + fv) / 2;
        if (ST.range_min(j, mid + 1) >= S[j] - s){
          tv = mid;
        } else {
          fv = mid;
        }
      }
      if (tv - j - 1 > R - L){
        L = j + 1;
        R = tv;
      }
    }
    if (L == 0 && R == -1){
      cout << -1 << endl;
    } else {
      cout << L << ' ' << R << endl;
    }
  }
}