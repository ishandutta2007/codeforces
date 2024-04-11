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
	}
	T operator [](int k){
		return ST[N - 1 + k];
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
	T all(){
		return ST[0];
	}
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<long long> S(n + 1);
    S[0] = 0;
    for (int j = 0; j < n; j++){
      S[j + 1] = S[j] + a[j];
    }
    vector<long long> S2 = S;
    sort(S2.begin(), S2.end());
    S2.erase(unique(S2.begin(), S2.end()), S2.end());
    vector<int> ps(n + 1);
    for (int j = 0; j <= n; j++){
      ps[j] = lower_bound(S2.begin(), S2.end(), S[j]) - S2.begin();
    }
    int cnt = S2.size();
    segment_tree<int> ST1(cnt), ST2(cnt);
    ST1.update(ps[0], 0);
    ST2.update(ps[0], 0);
    vector<int> mx(cnt, -INF);
    mx[ps[0]] = 0;
    map<long long, int> mp;
    for (int j = 1; j <= n; j++){
      int dp = -INF;
      dp = max(dp, mx[ps[j]]);
      dp = max(dp, ST1.range_max(0, ps[j]) + j);
      dp = max(dp, ST2.range_max(ps[j] + 1, cnt) - j);
      if (j == n){
        cout << dp << "\n";
      }
      mx[ps[j]] = max(mx[ps[j]], dp);
      ST1.update(ps[j], max(ST1[ps[j]], dp - j));
      ST2.update(ps[j], max(ST2[ps[j]], dp + j));
    }
  }
}