#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
template <typename T>
struct segment_tree{
	int N;
	vector<T> ST;
	segment_tree(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, 0);
	}
	void update(int k, T x){
		k += N - 1;
		ST[k] = x;
		while (k > 0){
			k = (k - 1) / 2;
			ST[k] = max(ST[k * 2 + 1], ST[k * 2 + 2]);
		}
	}
	T range_max(int L, int R, int i, int l, int r){
		if (R <= l || r <= L){
			return -INF;
		} else if (L <= l && r <= R){
			return ST[i];
		} else {
			int m = (l + r) / 2;
			return max(range_max(L, R, i * 2 + 1, l, m), range_max(L, R, i * 2 + 2, m, r));
		}
	}
	T range_max(int L, int R){
		return range_max(L, R, 0, 0, N);
	}
};
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    segment_tree<int> dp(n + 1);
    int p0 = -1, p1 = -1;
    for (int j = 0; j < n; j++){
      if (s1[j] == '0' || s2[j] == '0'){
        p0 = j;
      }
      if (s1[j] == '1' || s2[j] == '1'){
        p1 = j;
      }
      int mx = 0;
      if (p0 <= p1){
        mx = max(mx, dp.range_max(0, p0 + 1) + 2);
        mx = max(mx, dp.range_max(p0 + 1, j + 1));
      } else {
        mx = max(mx, dp.range_max(0, p1 + 1) + 2);
        mx = max(mx, dp.range_max(p1 + 1, p0 + 1) + 1);
        mx = max(mx, dp.range_max(p0 + 1, j + 1));
      }
      dp.update(j + 1, mx);
      if (j == n - 1){
        cout << mx << endl;
      }
    }
  }
}