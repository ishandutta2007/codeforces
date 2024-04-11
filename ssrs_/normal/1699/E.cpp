#include <bits/stdc++.h>
using namespace std;
const int INF = 100000000;
template <typename T>
struct segment_tree{
	int N;
	vector<T> ST;
	segment_tree(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, -INF);
		for (int i = 0; i < n; i++){
			ST[N - 1 + i] = INF;
		}
		for (int i = N - 2; i >= 0; i--){
			ST[i] = max(ST[i * 2 + 1], ST[i * 2 + 2]);
		}
	}
	void update(int k, T x){
		k += N - 1;
		ST[k] = x;
		while (k > 0){
			k = (k - 1) / 2;
			ST[k] = max(ST[k * 2 + 1], ST[k * 2 + 2]);
		}
	}
	T all(){
		return ST[0];
	}
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    n = a.size();
    vector<int> id(m + 1, -1);
    for (int j = 0; j < n; j++){
      id[a[j]] = j;
    }
    segment_tree<int> ST(n);
    vector<int> dp(m + 1, INF);
    int ans = INF;
    for (int j = m; j >= 1; j--){
      dp[j] = j;
      if (id[j] != -1){
        ST.update(id[j], j);
      }
      for (int k = 2; j * k <= m; k++){
        dp[j * k] = min(dp[j * k], max(dp[j], dp[k]));
        if (id[j * k] != -1){
          ST.update(id[j * k], dp[j * k]);
        }
      }
      ans = min(ans, ST.all() - j);
    }
    cout << ans << "\n";
  }
}