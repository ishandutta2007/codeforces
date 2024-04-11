#include <bits/stdc++.h>
using namespace std;
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
		ST = vector<T>(N * 2 - 1, 0);
		lazy = vector<T>(N * 2 - 1, 0);
	}
	void eval(int i){
		if (i < N - 1){
			lazy[i * 2 + 1] += lazy[i] / 2;
			lazy[i * 2 + 2] += lazy[i] / 2;
		}
		ST[i] += lazy[i];
		lazy[i] = 0;
	}
	void range_add(int L, int R, T x, int i, int l, int r){
		eval(i);
		if (R <= l || r <= L){
			return;
		} else if (L <= l && r <= R){
			lazy[i] += (r - l) * x;
			eval(i);
		} else {
			int m = (l + r) / 2;
			range_add(L, R, x, i * 2 + 1, l, m);
			range_add(L, R, x, i * 2 + 2, m, r);
			ST[i] = ST[i * 2 + 1] + ST[i * 2 + 2];
		}
	}
	void range_add(int L, int R, T x){
		range_add(L, R, x, 0, 0, N);
	}
	T range_sum(int L, int R, int i, int l, int r){
		eval(i);
		if (R <= l || r <= L){
			return 0;
		} else if (L <= l && r <= R){
			return ST[i];
		} else {
			int m = (l + r) / 2;
			return range_sum(L, R, i * 2 + 1, l, m) + range_sum(L, R, i * 2 + 2, m, r);
		}
	}
	T range_sum(int L, int R){
		return range_sum(L, R, 0, 0, N);
	}
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> p(n);
  for (int i = 0; i < n; i++){
    cin >> p[i];
  }
  vector<int> l(q), r(q);
  for (int i = 0; i < q; i++){
    cin >> l[i] >> r[i];
    l[i]--;
  }
  vector<int> pos(n + 1);
  for (int i = 0; i < n; i++){
    pos[p[i]] = i;
  }
  set<int> st;
  st.insert(-1);
  st.insert(n);
  vector<int> left(n + 1), right(n + 1);
  for (int i = n; i >= 1; i--){
    left[i] = *prev(st.lower_bound(pos[i])) + 1;
    right[i] = *st.lower_bound(pos[i]);
    st.insert(pos[i]);
  }
  vector<vector<pair<int, int>>> F(n + 1);
  for (int i = 1; i * (i + 1) <= n; i++){
    for (int j = i + 1; i * j <= n; j++){
      int L = min({pos[i], pos[j], pos[i * j]});
      int R = max({pos[i], pos[j], pos[i * j]});
      if (left[i * j] <= L && R <= right[i * j]){
        F[i * j].push_back(make_pair(R, L));
      }
    }
  }
  vector<vector<pair<int, int>>> add(n + 1), sub(n + 1);
  for (int i = 1; i <= n; i++){
    int cnt = F[i].size();
    sort(F[i].begin(), F[i].end());
    int mx = 0;
    for (int j = 0; j < cnt; j++){
      mx = max(mx, F[i][j].second);
      int t = right[i];
      if (j < cnt - 1){
        t = F[i][j + 1].first;
      }
      add[mx].push_back(make_pair(F[i][j].first + 1, t + 1));
      if (left[i] > 0){
        sub[left[i] - 1].push_back(make_pair(F[i][j].first + 1, t + 1));
      }
    }
  }
  vector<vector<int>> query(n + 1);
  for (int i = 0; i < q; i++){
    query[l[i]].push_back(i);
  }
  vector<long long> ans(q);
  lazy_segment_tree<long long> ST1(n + 1), ST2(n + 1);
  for (int i = n; i >= 0; i--){
    for (auto P : add[i]){
      int L = P.first;
      int R = P.second;
      ST1.range_add(L, R, -1);
      ST2.range_add(L, R, i + 1);
    }
    for (auto P : sub[i]){
      int L = P.first;
      int R = P.second;
      ST1.range_add(L, R, 1);
      ST2.range_add(L, R, -1 - i);
    }
    for (int x : query[i]){
      ans[x] = ST1.range_sum(l[x] + 1, r[x] + 1) * i + ST2.range_sum(l[x] + 1, r[x] + 1);
    }
  }
  for (int i = 0; i < q; i++){
    cout << ans[i] << "\n";
  }
}