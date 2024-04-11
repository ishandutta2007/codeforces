#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
struct monoid{
  long long max1, max_id, max2;
  monoid(){
    max1 = -INF;
    max_id = -1;
    max2 = -INF;
  }
  monoid(long long x, int i){
    max1 = x;
    max_id = i;
    max2 = -INF;
  }
};
monoid op(monoid M1, monoid M2){
  monoid ans;
  if (M1.max1 >= M2.max1){
    ans.max1 = M1.max1;
    ans.max_id = M1.max_id;
    ans.max2 = max(M1.max2, M2.max1);
    return ans;
  } else {
    ans.max1 = M2.max1;
    ans.max_id = M2.max_id;
    ans.max2 = max(M1.max1, M2.max2);
    return ans;
  }
}
template <typename T>
struct segment_tree{
	int N;
	vector<T> ST;
	function<T(T, T)> f;
	T E;
	segment_tree(vector<T> &A, function<T(T, T)> f, T E): f(f), E(E){
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
		if (r <= L || R <= l){
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
  int n, m;
  cin >> n >> m;
  vector<int> d(n);
  for (int i = 0; i < n; i++){
    cin >> d[i];
  }
  vector<int> h(n);
  for (int i = 0; i < n; i++){
    cin >> h[i];
  }
  vector<long long> S(n * 2);
  S[0] = 0;
  for (int i = 0; i < n; i++){
    S[i + 1] = S[i] + d[i];
  }
  for (int i = n + 1; i < n * 2; i++){
    S[i] = S[i - n] + S[n];
  }
  vector<long long> H(n * 2);
  for (int i = 0; i < n * 2; i++){
    H[i] = h[i % n];
  }
  vector<monoid> tmp1(n * 2);
  for (int i = 0; i < n * 2; i++){
    tmp1[i] = monoid(H[i] * 2 - S[i], i);
  }
  vector<monoid> tmp2(n * 2);
  for (int i = 0; i < n * 2; i++){
    tmp2[i] = monoid(H[i] * 2 + S[i], i);
  }
  segment_tree<monoid> ST1(tmp1, op, monoid());
  segment_tree<monoid> ST2(tmp2, op, monoid());
  for (int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    a--;
    if (a <= b){
      a += n;
    }
    monoid res1 = ST1.query(b, a);
    monoid res2 = ST2.query(b, a);
    if (res1.max_id != res2.max_id){
      cout << res1.max1 + res2.max1 << endl;
    } else {
      cout << max(res1.max1 + res2.max2, res1.max2 + res2.max1) << endl;
    }
  }
}