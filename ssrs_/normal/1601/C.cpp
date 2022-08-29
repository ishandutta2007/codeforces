#include <bits/stdc++.h>
using namespace std;
const int INF = 100000000;
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
  T sum(int L, int R){
    return sum(R) - sum(L);
  }
};
template <typename T>
struct lazy_segment_tree{
	int N;
	vector<T> ST;
	vector<T> lazy;
	lazy_segment_tree(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, INF);
		lazy = vector<T>(N * 2 - 1, 0);
		for (int i = 0; i < n; i++){
			ST[N - 1 + i] = 0;
		}
		for (int i = N - 2; i >= 0; i--){
			ST[i] = min(ST[i * 2 + 1], ST[i * 2 + 2]);
		}
	}
	void eval(int i){
		if (i < N - 1){
			lazy[i * 2 + 1] += lazy[i];
			lazy[i * 2 + 2] += lazy[i];
		}
		ST[i] += lazy[i];
		lazy[i] = 0;
	}
	void range_add(int L, int R, T x, int i, int l, int r){
		eval(i);
		if (R <= l || r <= L){
			return;
		} else if (L <= l && r <= R){
			lazy[i] += x;
			eval(i);
		} else {
			int m = (l + r) / 2;
			range_add(L, R, x, i * 2 + 1, l, m);
			range_add(L, R, x, i * 2 + 2, m, r);
			ST[i] = min(ST[i * 2 + 1], ST[i * 2 + 2]);
		}
	}
	void range_add(int L, int R, T x){
		range_add(L, R, x, 0, 0, N);
	}
	T all(){
		eval(0);
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
    vector<int> b(m);
    for (int j = 0; j < m; j++){
      cin >> b[j];
    }
    sort(b.begin(), b.end());
    vector<int> c;
    for (int j = 0; j < n; j++){
      c.push_back(a[j]);
    }
    for (int j = 0; j < m; j++){
      c.push_back(b[j]);
    }
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    for (int j = 0; j < n; j++){
      a[j] = lower_bound(c.begin(), c.end(), a[j]) - c.begin();
    }
    for (int j = 0; j < m; j++){
      b[j] = lower_bound(c.begin(), c.end(), b[j]) - c.begin();
    }
    int cnt = c.size();
    binary_indexed_tree<int> BIT(cnt);
    long long ans = 0;
    for (int j = 0; j < n; j++){
      ans += BIT.sum(a[j] + 1, cnt);
      BIT.add(a[j], 1);
    }
    lazy_segment_tree<int> ST(n + 1);
    for (int j = 0; j < n; j++){
      ST.range_add(j + 1, n + 1, 1);
    }
    vector<vector<int>> upd(cnt);
    for (int j = 0; j < n; j++){
      upd[a[j]].push_back(j);
    }
    vector<int> query(cnt, 0);
    for (int j = 0; j < m; j++){
      query[b[j]]++;
    }
    for (int j = 0; j < cnt; j++){
      for (int k : upd[j]){
        ST.range_add(k + 1, n + 1, -1);
      }
      ans += (long long) ST.all() * query[j];
      for (int k : upd[j]){
        ST.range_add(0, k + 1, 1);
      }
    }
    cout << ans << "\n";
  }
}