#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
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
		ST = vector<T>(N * 2 - 1, -INF);
		lazy = vector<T>(N * 2 - 1, -1);
	}
	void eval(int i){
		if (lazy[i] != -1){
			if (i < N - 1){
				lazy[i * 2 + 1] = lazy[i];
				lazy[i * 2 + 2] = lazy[i];
			}
			ST[i] = lazy[i];
			lazy[i] = -1;
		}
	}
	void range_update(int L, int R, T x, int i, int l, int r){
		eval(i);
		if (R <= l || r <= L){
			return;
		} else if (L <= l && r <= R){
			lazy[i] = x;
			eval(i);
		} else {
			int m = (l + r) / 2;
			range_update(L, R, x, i * 2 + 1, l, m);
			range_update(L, R, x, i * 2 + 2, m, r);
			ST[i] = max(ST[i * 2 + 1], ST[i * 2 + 2]);
		}
	}
	void range_update(int L, int R, T x){
		range_update(L, R, x, 0, 0, N);
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
};
int main(){
  int n;
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; i++){
    cin >> h[i];
  }
  int m;
  cin >> m;
  vector<int> l(m), r(m), w(m);
  for (int i = 0; i < m; i++){
    cin >> l[i] >> r[i] >> w[i];
    l[i]--;
  }
  vector<int> h2 = h;
  sort(h2.begin(), h2.end());
  h2.erase(unique(h2.begin(), h2.end()), h2.end());
  int cnt = h2.size();
  map<int, int> mp;
  for (int i = 0; i < cnt; i++){
    mp[h2[i]] = i;    
  }
  for (int i = 0; i < n; i++){
    h[i] = mp[h[i]];
  }
  vector<int> tv(m, 0);
  vector<int> fv(m, cnt);
  while (1){
    vector<vector<int>> fence(cnt);
    vector<vector<int>> query(cnt);
    for (int i = 0; i < n; i++){
      fence[h[i]].push_back(i);
    }
    bool ok = true;
    for (int i = 0; i < m; i++){
      if (fv[i] - tv[i] > 1){
        query[(tv[i] + fv[i]) / 2].push_back(i);
        ok = false;
      }
    }
    if (ok){
      break;
    }
    set<int> st;
    st.insert(-1);
    st.insert(n);
    lazy_segment_tree<int> ST(n);
    ST.range_update(0, n, n);
    for (int i = 0; i < cnt; i++){
      for (int j : query[i]){
        int mx;
        if (*st.lower_bound(l[j]) == *st.lower_bound(r[j])){
          mx = r[j] - l[j];
        } else {
          int L = *st.lower_bound(l[j]);
          int R = *prev(st.lower_bound(r[j]));
          mx = max(L - l[j], r[j] - 1 - R);
          if (R - L >= 1){
            mx = max(mx, ST.range_max(L + 1, R));
          }
        }
        if (mx >= w[j]){
          tv[j] = i;
        } else {
          fv[j] = i;
        }
      }
      for (int j : fence[i]){
        int left = *prev(st.lower_bound(j));
        int right = *st.lower_bound(j);
        if (j - left - 1 > 0){
          ST.range_update(left + 1, j, j - left - 1);
        }
        ST.range_update(j, j + 1, 0);
        if (right - j - 1 > 0){
          ST.range_update(j + 1, right, right - j - 1);
        }
        st.insert(j);
      }
    }
  }
  for (int i = 0; i < m; i++){
    cout << h2[tv[i]] << endl;
  }
}