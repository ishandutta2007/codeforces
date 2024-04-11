#include <bits/stdc++.h>
using namespace std;
const int INF = 1100000000;
template <typename T>
struct lazy_segtree{
	int N;
	vector<T> ST;
	vector<T> lazy;
	lazy_segtree(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, 0);
		lazy = vector<T>(N * 2 - 1, 0);
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
			ST[i] = max(ST[i * 2 + 1], ST[i * 2 + 2]);
		}
	}
	void range_add(int L, int R, T x){
		range_add(L, R, x, 0, 0, N);
	}
	T range_max(int L, int R, int i, int l, int r){
		eval(i);
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
	  eval(0);
	  return ST[0];
	}
	T operator [](int k){
	  return range_max(k, k + 1);
	}
	void debug(int n){
	  for (int i = 0; i < n; i++){
	    cout << range_max(i, i + 1) << ' ';
	  }
	  cout << endl;
	}
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> h(n);
  for (int i = 0; i < n; i++){
    cin >> h[i];
  }
  vector<vector<pair<int, int>>> query(n);
  for (int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    query[a - 1].push_back(make_pair(b, i));
  }
  vector<int> hv;
  for (int i = 0; i < n; i++){
    hv.push_back(h[i]);
  }
  for (int i = 0; i < n; i++){
    int cnt = query[i].size();
    for (int j = 0; j < cnt; j++){
      hv.push_back(query[i][j].first);
    }
  }
  sort(hv.begin(), hv.end());
  hv.erase(unique(hv.begin(), hv.end()), hv.end());
  int cnt = hv.size();
  map<int, int> mp;
  for (int i = 0; i < cnt; i++){
    mp[hv[i]] = i * 2 + 1;
  }
  for (int i = 0; i < n; i++){
    h[i] = mp[h[i]];
  }
  for (int i = 0; i < n; i++){
    int sz = query[i].size();
    for (int j = 0; j < sz; j++){
      query[i][j].first = mp[query[i][j].first];
    }
  }
  cnt = cnt * 2 + 1;
  //LIS DP
  vector<int> dpL(cnt, INF);
  vector<int> dpR(cnt, - INF);
  //update dpR
  vector<pair<int, int>> upd(n);
  for (int i = n - 1; i >= 0; i--){
    int tv = -1;
    int fv = cnt;
    while (fv - tv > 1){
      int mid = (tv + fv) / 2;
      if (dpR[mid] > h[i]){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    upd[i] = make_pair(fv, dpR[fv]);
    dpR[fv] = h[i];
  }
  dpR[upd[0].first] = upd[0].second;
  //LST
  lazy_segtree<int> ST(cnt);
  for (int i = 0; i < cnt; i++){
    if (dpR[i] != -INF){
      ST.range_add(0, dpR[i], 1);
    }
  }
  vector<int> ans(m, -1);
  for (int i = 0; i < n; i++){
    int tmp = ST.all();
    tmp = max(tmp, (int) (lower_bound(dpL.begin(), dpL.end(), INF) - dpL.begin()));
    tmp = max(tmp, (int) (dpR.rend() - upper_bound(dpR.rbegin(), dpR.rend(), -INF)));
    int sz = query[i].size();
    for (int j = 0; j < sz; j++){
      int b = query[i][j].first;
      int id = query[i][j].second;
      int tmp2 = max(tmp, ST[b] + 1);
      ans[id] = tmp2;
    }
    if (i < n - 1){
      //update
      int pos = upd[i + 1].first;
      int prev = upd[i + 1].second;
      if (prev == -INF){
        ST.range_add(0, dpR[pos], -1);
      } else {
        ST.range_add(prev, dpR[pos], -1);
      }
      dpR[pos] = prev;
      auto itr = lower_bound(dpL.begin(), dpL.end(), h[i]);
      int pos2 = itr - dpL.begin();
      if (*itr == INF){
        ST.range_add(h[i] + 1, cnt, 1);
      } else {
        ST.range_add(h[i] + 1, *itr + 1, 1);
      }
      *itr = h[i];
    }
  }
  for (int i = 0; i < m; i++){
    cout << ans[i] << "\n";
  }
}