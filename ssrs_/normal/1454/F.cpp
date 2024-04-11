#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000;
template <typename T>
struct segment_tree{
	int N;
	vector<T> ST1, ST2;
	segment_tree(vector<T> a){
		int n = a.size();
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST1 = vector<T>(N * 2 - 1, INF);
		ST2 = vector<T>(N * 2 - 1, -INF);
		for (int i = 0; i < n; i++){
			ST1[N - 1 + i] = a[i];
			ST2[N - 1 + i] = a[i];
		}
		for (int i = N - 2; i >= 0; i--){
			ST1[i] = min(ST1[i * 2 + 1], ST1[i * 2 + 2]);
			ST2[i] = max(ST2[i * 2 + 1], ST2[i * 2 + 2]);
		}
	}
	T range_min(int L, int R, int i, int l, int r){
		if (R <= l || r <= L){
			return INF;
		} else if (L <= l && r <= R){
			return ST1[i];
		} else {
			int m = (l + r) / 2;
			return min(range_min(L, R, i * 2 + 1, l, m), range_min(L, R, i * 2 + 2, m, r));
		}
	}
	T range_min(int L, int R){
		return range_min(L, R, 0, 0, N);
	}
	T range_max(int L, int R, int i, int l, int r){
		if (R <= l || r <= L){
			return -INF;
		} else if (L <= l && r <= R){
			return ST2[i];
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
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    segment_tree<int> ST(a);
    map<int, vector<int>> mp;
    for (int j = 0; j < n; j++){
      mp[a[j]].push_back(j);
    }
    int x = -1, y = -1, z = -1;
    set<int> st;
    st.insert(-1);
    st.insert(n);
    int L = 0, R = n;
    for (auto P : mp){
      for (int j : P.second){
        st.insert(j);
      }
      bool l_upd = false;
      while (st.count(L)){
        L++;
        l_upd = true;
      }
      bool r_upd = false;
      while (st.count(R - 1)){
        R--;
        r_upd = true;
      }
      if (R < 0){
        if (P.second.size() >= 3){
          x = P.second[1];
          y = 1;
          z = n - x - y;
        }
      } else {
        if (l_upd && r_upd){
          for (int l2 = L - 1; l2 <= L; l2++){
            for (int r2 = R; r2 <= R + 1; r2++){
              if (l2 > 0 && r2 < n){
                if (ST.range_max(0, l2) == P.first && ST.range_min(l2, r2) == P.first && ST.range_max(r2, n) == P.first){
                  x = l2;
                  y = r2 - l2;
                  z = n - r2;
                }
              }
            }
          }
        }
      }
    }
    if (x == -1 && y == -1 && z == -1){
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      cout << x << ' ' << y << ' ' << z << endl;
    }
  }
}