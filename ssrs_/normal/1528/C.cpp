#include <bits/stdc++.h>
using namespace std;
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
};
void dfs1(vector<vector<int>> &c, vector<int> &in, vector<int> &out, int &t, int v = 0){
  in[v] = t;
  t++;
  for (int w : c[v]){
    dfs1(c, in, out, t, w);
  }
  out[v] = t;
}
void dfs2(vector<vector<int>> &c, dual_segment_tree<int> &ST, int &ans, int &cnt, vector<int> &in, vector<int> &out, int v = 0){
  int id = -1;
  if (ST[in[v]] > 0){
    id = ST[in[v]] - 1;
    ST.range_add(in[id], out[id], -(id + 1));
    cnt--;
  }
  ST.range_add(in[v], out[v], v + 1);
  cnt++;
  ans = max(ans, cnt);
  for (int w : c[v]){
    dfs2(c, ST, ans, cnt, in, out, w);
  }
  ST.range_add(in[v], out[v], -(v + 1));
  cnt--;
  if (id != -1){
    ST.range_add(in[id], out[id], id + 1);
    cnt++;
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n, -1);
    for (int j = 1; j < n; j++){
      cin >> a[j];
      a[j]--;
    }
    vector<int> b(n, -1);
    for (int j = 1; j < n; j++){
      cin >> b[j];
      b[j]--;
    }
    vector<vector<int>> c1(n), c2(n);
    for (int j = 1; j < n; j++){
      c1[a[j]].push_back(j);
      c2[b[j]].push_back(j);
    }
    vector<int> in(n), out(n);
    int t = 0;
    dfs1(c2, in, out, t);
    dual_segment_tree<int> ST(n);
    int cnt = 0, ans = 0;
    dfs2(c1, ST, ans, cnt, in, out);
    cout << ans << "\n";
  }
}