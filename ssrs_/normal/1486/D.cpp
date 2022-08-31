#include <bits/stdc++.h>
using namespace std;
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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int tv = 1, fv = n + 1;
  while (fv - tv > 1){
    int mid = (tv + fv) / 2;
    vector<int> b(n);
    for (int i = 0; i < n; i++){
      if (a[i] >= mid){
        b[i] = 1;
      } else {
        b[i] = -1;
      }
    }
    vector<int> s(n + 1);
    s[0] = 0;
    for (int i = 0; i < n; i++){
      s[i + 1] = s[i] + b[i];
    }
    sparse_table<int> ST(s);
    bool ok = false;
    for (int i = k; i <= n; i++){
      if (ST.range_min(0, i - k + 1) < s[i]){
        ok = true;
      }
    }
    if (ok){
      tv = mid;
    } else {
      fv = mid;
    }
  }
  cout << tv << endl;
}