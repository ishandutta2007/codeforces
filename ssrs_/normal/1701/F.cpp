#include <bits/stdc++.h>
using namespace std;
const int MAX = 200000;
template <typename T, typename F>
struct lazy_segment_tree{
	int N;
	vector<T> ST;
	vector<F> lazy;
	function<T(T, T)> op;
	function<T(F, T)> mp;
	function<F(F, F)> comp;
	T E;
	F id;
	lazy_segment_tree(vector<T> &A, function<T(T, T)> op, function<T(F, T)> mp, function<F(F, F)> comp, T E, F id): op(op), mp(mp), comp(comp), E(E), id(id){
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
			ST[i] = op(ST[i * 2 + 1], ST[i * 2 + 2]);
		}
		lazy = vector<F>(N * 2 - 1, id);
	}
	void eval(int i){
		if (i < N - 1){
			lazy[i * 2 + 1] = comp(lazy[i * 2 + 1], lazy[i]);
			lazy[i * 2 + 2] = comp(lazy[i * 2 + 2], lazy[i]);
		}
		ST[i] = mp(lazy[i], ST[i]);
		lazy[i] = id;
	}
	void range_apply(int L, int R, F f, int i, int l, int r){
		eval(i);
		if (r <= L || R <= l){
			return;
		} else if (L <= l && r <= R){
			lazy[i] = f;
			eval(i);
		} else {
			int m = (l + r) / 2;
			range_apply(L, R, f, i * 2 + 1, l, m);
			range_apply(L, R, f, i * 2 + 2, m, r);
			ST[i] = op(ST[i * 2 + 1], ST[i * 2 + 2]);
		}
	}
	void range_apply(int L, int R, F f){
		range_apply(L, R, f, 0, 0, N);
	}
	T range_fold(int L, int R, int i, int l, int r){
		eval(i);
		if (r <= L || R <= l){
			return E;
		} else if (L <= l && r <= R){
			return ST[i];
		} else {
			int m = (l + r) / 2;
			return op(range_fold(L, R, i * 2 + 1, l, m), range_fold(L, R, i * 2 + 2, m, r));
		}
	}
	T range_fold(int L, int R){
		return range_fold(L, R, 0, 0, N);
  }
};
struct monoid{
  int sz, on_cnt;
  long long on_sum, all_sum;
  monoid(): sz(0), on_cnt(0), on_sum(0), all_sum(0){
  }
};
monoid op(monoid L, monoid R){
  L.sz += R.sz;
  L.on_cnt += R.on_cnt;
  L.on_sum += R.on_sum;
  L.all_sum += R.all_sum;
  return L;
}
struct func{
  int turn;
  int add;
  func(): turn(0), add(0){
  }
  func(int turn, int add): turn(turn), add(add){
  }
};
monoid mp(func F, monoid A){
  A.on_sum += (long long) F.add * A.on_cnt;
  A.all_sum += (long long) F.add * A.sz;
  if (F.turn == 1){
    A.on_cnt = A.sz;
    A.on_sum = A.all_sum;
  }
  if (F.turn == -1){
    A.on_cnt = 0;
    A.on_sum = 0;
  }
  return A;
}
func comp(func f, func g){
  f.add += g.add;
  if (g.turn != 0){
    f.turn = g.turn;
  }
  return f;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q, d;
  cin >> q >> d;
  set<int> st;
  long long ans = 0;
  vector<monoid> tmp(MAX);
  for (int i = 0; i < MAX; i++){
    tmp[i].sz = 1;
  }
  lazy_segment_tree<monoid, func> ST1(tmp, op, mp, comp, monoid(), func());
  lazy_segment_tree<monoid, func> ST2(tmp, op, mp, comp, monoid(), func());
  for (int i = 0; i < q; i++){
    int a;
    cin >> a;
    a--;
    if (st.count(a) == 0){
      ans += ST1.range_fold(max(a - d, 0), MAX).on_sum;
      ans -= ST2.range_fold(min(a + d + 1, MAX), MAX).on_sum;
      ST1.range_apply(max(a - d, 0), a, func(0, 1));
      ST2.range_apply(a + 1, min(a + d + 1, MAX), func(0, 1));
      ST1.range_apply(a, a + 1, func(1, 0));
      ST2.range_apply(a, a + 1, func(1, 0));
      st.insert(a);
    } else {
      ST1.range_apply(max(a - d, 0), a, func(0, -1));
      ST2.range_apply(a + 1, min(a + d + 1, MAX), func(0, -1));
      ST1.range_apply(a, a + 1, func(-1, 0));
      ST2.range_apply(a, a + 1, func(-1, 0));
      ans -= ST1.range_fold(max(a - d, 0), MAX).on_sum;
      ans += ST2.range_fold(min(a + d + 1, MAX), MAX).on_sum;
      st.erase(a);
    }
    cout << ans << "\n";
  }
}