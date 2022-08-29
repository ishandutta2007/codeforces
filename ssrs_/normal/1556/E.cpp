#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct sparse_table{
	vector<vector<T>> ST1;
	vector<vector<T>> ST2;
	sparse_table(vector<T> &A){
		int N = A.size();
		int LOG = 32 - __builtin_clz(N);
		ST1 = vector<vector<T>>(LOG, vector<T>(N));
		ST2 = vector<vector<T>>(LOG, vector<T>(N));
		for (int i = 0; i < N; i++){
			ST1[0][i] = A[i];
			ST2[0][i] = A[i];
		}
		for (int i = 0; i < LOG - 1; i++){
			for (int j = 0; j < N - (1 << i); j++){
				ST1[i + 1][j] = min(ST1[i][j], ST1[i][j + (1 << i)]);
				ST2[i + 1][j] = max(ST2[i][j], ST2[i][j + (1 << i)]);
			}
		}
	}
	T range_min(int L, int R){
		int d = 31 - __builtin_clz(R - L);
		return min(ST1[d][L], ST1[d][R - (1 << d)]);
	}
	T range_max(int L, int R){
		int d = 31 - __builtin_clz(R - L);
		return max(ST2[d][L], ST2[d][R - (1 << d)]);
	}
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++){
    cin >> b[i];
  }
  vector<long long> d(n);
  for (int i = 0; i < n; i++){
    d[i] = b[i] - a[i];
  }
  vector<long long> s(n + 1);
  s[0] = 0;
  for (int i = 0; i < n; i++){
    s[i + 1] = s[i] + d[i];
  }
  sparse_table<long long> ST(s);
  for (int i = 0; i < q; i++){
    int l, r;
    cin >> l >> r;
    l--;
    long long mn = ST.range_min(l, r);
    long long mx = ST.range_max(l, r);
    if (s[l] != s[r]){
      cout << -1 << "\n";
    } else if (mn != s[l]){
      cout << -1 << "\n";
    } else {
      cout << mx - mn << endl;
    }
  }
}