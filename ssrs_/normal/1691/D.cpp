#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
struct monoid{
  long long mx, sum, left, right, all;
  monoid(): mx(-INF), sum(0), left(0), right(0), all(0){
  }
  monoid(int x){
    mx = x;
    sum = x;
    left = max(x, 0);
    right = max(x, 0);
    all = max(x, 0);
  }
};
monoid f(monoid L, monoid R){
  monoid ans;
  ans.mx = max(L.mx, R.mx);
  ans.sum = L.sum + R.sum;
  ans.left = max(L.left, L.sum + R.left);
  ans.right = max(R.right, L.right + R.sum);
  ans.all = max({L.all, R.all, L.right + R.left});
  return ans;
}
template <typename T>
struct segment_tree{
	int N;
	vector<T> ST;
	function<T(T, T)> f;
	T E;
	segment_tree(vector<T> A, function<T(T, T)> f, T E): f(f), E(E){
		int n = A.size();
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, E);
		for (int i = 0; i < n; i++){
			ST[N - 1 + i] = A[i];
		}
		for (int i = N - 2; i >= 0; i--){
			ST[i] = f(ST[i * 2 + 1], ST[i * 2 + 2]);
		}
	}
	T query(int L, int R, int i, int l, int r){
		if (R <= l || r <= L){
			return E;
		} else if (L <= l && r <= R){
			return ST[i];
		} else {
			int m = (l + r) / 2;
			return f(query(L, R, i * 2 + 1, l, m), query(L, R, i * 2 + 2, m, r));
		}
	}
	T query(int L, int R){
		return query(L, R, 0, 0, N);
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
    vector<pair<int, int>> P(n);
    for (int j = 0; j < n; j++){
      P[j] = make_pair(a[j], j);
    }
    sort(P.begin(), P.end(), greater<pair<int, int>>());
    vector<monoid> b(n);
    for (int j = 0; j < n; j++){
      b[j] = monoid(a[j]);
    }
    segment_tree<monoid> ST(b, f, monoid());
    bool ok = true;
    set<int> st;
    st.insert(-1);
    st.insert(n);
    for (int j = 0; j < n; j++){
      int L = *prev(st.lower_bound(P[j].second)) + 1;
      int R = *st.lower_bound(P[j].second);
      monoid res = ST.query(L, R);
      long long ans;
      if (res.all == 0){
        ans = res.mx;
      } else {
        ans = res.all;
      }
      if (ans > P[j].first){
        ok = false;
      }
      st.insert(P[j].second);
    }
    if (ok){
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }
}