#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
template <typename T>
struct range_chmax{
	int N;
	vector<T> ST;
	range_chmax(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, 0);
	}
	T operator [](int k){
		k += N - 1;
		T ans = ST[k];
		while (k > 0){
			k = (k - 1) / 2;
			ans = max(ans, ST[k]);
		}
		return ans;
	}
	void chmax(int L, int R, T x, int i, int l, int r){
		if (R <= l || r <= L){
			return;
		} else if (L <= l && r <= R){
			ST[i] = max(ST[i], x);
			return;
		} else {
			int m = (l + r) / 2;
			chmax(L, R, x, i * 2 + 1, l, m);
			chmax(L, R, x, i * 2 + 2, m, r);
			return;
		}
	}
	void chmax(int L, int R, T x){
		chmax(L, R, x, 0, 0, N);
	}
};
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++){
    cin >> a[i] >> b[i];
  }
  vector<int> c(m), d(m);
  for (int i = 0; i < m; i++){
    cin >> c[i] >> d[i];
  }
  range_chmax<int> ST(1000001);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (c[j] >= a[i] && d[j] >= b[i]){
        ST.chmax(0, c[j] - a[i] + 1,  d[j] - b[i] + 1);
      }
    }
  }
  int ans = INF;
  for (int i = 0; i <= 1000000; i++){
    ans = min(ans, i + ST[i]);
  }
  cout << ans << endl;
}