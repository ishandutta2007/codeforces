#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> &b, vector<int> &L, vector<int> &R, vector<int> &l, vector<int> &r, int v){
  L[v] = b.size();
  if (l[v] != -1){
    dfs(b, L, R, l, r, l[v]);
  }
  b.push_back(v);
  if (r[v] != -1){
    dfs(b, L, R, l, r, r[v]);
  }
  R[v] = b.size();
}
template <typename T>
struct dual_segment_tree{
	int N;
	vector<T> ST;
	dual_segment_tree(int n){
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
			ans += ST[k];
		}
		return ans;
	}
	void range_add(int L, int R, T x, int i, int l, int r){
		if (R <= l || r <= L){
			return;
		} else if (L <= l && r <= R){
			ST[i] += x;
			return;
		} else {
			int m = (l + r) / 2;
			range_add(L, R, x, i * 2 + 1, l, m);
			range_add(L, R, x, i * 2 + 2, m, r);
			return;
		}
	}
	void range_add(int L, int R, T x){
		range_add(L, R, x, 0, 0, N);
	}
	void all_add(T x){
		ST[0] += x;
	}
};
int main(){
  int n, k;
  cin >> n >> k;
  string c;
  cin >> c;
  vector<int> l(n), r(n);
  for (int i = 0; i < n; i++){
    cin >> l[i] >> r[i];
    l[i]--;
    r[i]--;
  }
  vector<int> p(n);
  for (int i = 0; i < n; i++){
    if (l[i] != -1){
      p[l[i]] = i;
    }
    if (r[i] != -1){
      p[r[i]] = i;
    }
  }
  vector<int> b;
  vector<int> L(n), R(n);
  dfs(b, L, R, l, r, 0);
  vector<int> good(n, -1);
  for (int i = 0; i < n - 1; i++){
    if (c[b[i]] > c[b[i + 1]]){
      good[b[i]] = 0;
    }
    if (c[b[i]] < c[b[i + 1]]){
      good[b[i]] = 1;
    }
  }
  good[b[n - 1]] = 0;
  for (int i = n - 2; i >= 0; i--){
    if (good[b[i]] == -1){
      good[b[i]] = good[b[i + 1]];
    }
  }
  vector<int> d(n, -1);
  dual_segment_tree<int> ST1(n), ST2(n);
  for (int i = 0; i < n; i++){
    ST2.range_add(L[i], R[i], 1);
  }
  int cnt = 0;
  for (int i = 0; i < n; i++){
    if (d[b[i]] == -1){
      if (good[b[i]] == 0 || ST1[i] > 0 || cnt + ST2[i] > k){
        d[b[i]] = 0;
        ST2.range_add(L[b[i]], R[b[i]], -1);
        ST1.range_add(L[b[i]], R[b[i]], 1);
      } else {
        int v = b[i];
        while (true){
          if (d[v] == 1){
            break;
          }
          ST2.range_add(L[v], R[v], -1);
          d[v] = 1;
          cnt++;
          if (v == 0){
            break;
          }
          v = p[v];
        }
      }
    }
  }
  for (int i = 0; i < n; i++){
    cout << c[b[i]];
    if (d[b[i]] == 1){
      cout << c[b[i]];
    }
  }
  cout << endl;
}