#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
template <typename T>
struct segment_tree{
	int N;
	vector<T> ST;
	segment_tree(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, INF);
	}
	void update(int k, T x){
		k += N - 1;
		ST[k] = x;
		while (k > 0){
			k = (k - 1) / 2;
			ST[k] = min(ST[k * 2 + 1], ST[k * 2 + 2]);
		}
	}
	T range_min(int L, int R, int i, int l, int r){
		if (R <= l || r <= L){
			return INF;
		} else if (L <= l && r <= R){
			return ST[i];
		} else {
			int m = (l + r) / 2;
			return min(range_min(L, R, i * 2 + 1, l, m), range_min(L, R, i * 2 + 2, m, r));
		}
	}
	T range_min(int L, int R){
		return range_min(L, R, 0, 0, N);
	}
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  set<int> st;
  for (int i = -1; i <= n; i++){
    st.insert(i);
  }
  vector<set<int>> R(n);
  segment_tree<int> ST(n);
  for (int i = 0; i < q; i++){
    int t;
    cin >> t;
    if (t == 0){
      int l, r, x;
      cin >> l >> r >> x;
      l--;
      int r2 = *st.lower_bound(r);
      if (x == 0){
        while (true){
          auto itr = st.lower_bound(l);
          if (*itr >= r){
            break;
          }
          int p = *itr;
          st.erase(*itr);
          if (r2 < n){
            while (!R[p].empty()){
              int t = *R[p].begin();
              if (t < r2){
                R[p].erase(R[p].begin());
              } else {
                break;
              }
            }
            if (R[r2].size() < R[p].size()){
              swap(R[p], R[r2]);
            }
            for (int a : R[p]){
              R[r2].insert(a);
            }
            if (R[r2].empty()){
              ST.update(r2, INF);
            } else {
              ST.update(r2, *R[r2].begin());
            }
          }
          R[p].clear();
          ST.update(p, INF);
        }
      }
      if (x == 1){
        l = *st.lower_bound(l);
        R[l].insert(r);
        ST.update(l, *R[l].begin());
      }
    }
    if (t == 1){
      int j;
      cin >> j;
      j--;
      if (st.count(j) == 0){
        cout << "NO" << "\n";
      } else {
        int l = *prev(st.lower_bound(j)) + 1;
        int r = *st.upper_bound(j);
        if (ST.range_min(l, j + 1) <= r){
          cout << "YES" << "\n";
        } else {
          cout << "N/A" << "\n";
        }
      }
    }
  }
}