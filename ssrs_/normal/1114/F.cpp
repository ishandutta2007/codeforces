#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 1000000007;
long long modpow(long long a, long long b){
	long long ans = 1;
	while (b > 0){
		if (b % 2 == 1){
			ans *= a;
			ans %= MOD;
		}
		a *= a;
		a %= MOD;
		b /= 2;
	}
	return ans;
}
long long modpow2(long long a, long long b){
	while (b > 1){
		a *= a;
		a %= MOD;
		b /= 2;
	}
	return a;
}
long long modinv(long long a){
	return modpow(a, MOD - 2);
}
template <typename T, typename F>
struct lazy_segment_tree{
  int N;
  vector<T> ST;
  vector<F> lazy;
  function<T(T, T)> op;
  function<T(T, F)> mp;
  function<F(F, F)> comp;
  T E;
  F id;
  lazy_segment_tree(vector<T> &A, function<T(T, T)> op, function<T(T, F)> mp, function<F(F, F)> comp, T E, F id): op(op), mp(mp), comp(comp), E(E), id(id){
    int n = A.size();
    N = 1;
    while (N < n){
      N *= 2;
    }
    ST = vector<T>(N * 2 - 1, E);
    lazy = vector<F>(N * 2 - 1, id);
    for (int i = 0; i < n; i++){
      ST[N - 1 + i] = A[i];
    }
    for (int i = N - 2; i >= 0; i--){
      ST[i] = op(ST[i * 2 + 1], ST[i * 2 + 2]);
    }
  }
  void eval(int i){
    if (i < N - 1){
      lazy[i * 2 + 1] = comp(lazy[i * 2 + 1], lazy[i]);
      lazy[i * 2 + 2] = comp(lazy[i * 2 + 2], lazy[i]);
    }
    ST[i] = mp(ST[i], lazy[i]);
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
tuple<long long, array<bool, 62>, int> op(tuple<long long, array<bool, 62>, int> A, tuple<long long, array<bool, 62>, int> B){
  get<0>(A) = get<0>(A) * get<0>(B) % MOD;
  for (int i = 0; i < 62; i++){
    get<1>(A)[i] |= get<1>(B)[i];
  }
  get<2>(A) += get<2>(B);
  return A;
}
tuple<long long, array<bool, 62>, int> mp(tuple<long long, array<bool, 62>, int> A, pair<long long, array<bool, 62>> f){
  get<0>(A) *= modpow2(f.first, get<2>(A));
  get<0>(A) %= MOD;
  for (int i = 0; i < 62; i++){
    get<1>(A)[i] |= f.second[i];
  }
  return A;
}
pair<long long, array<bool, 62>> comp(pair<long long, array<bool, 62>> f, pair<long long, array<bool, 62>> g){
  f.first *= g.first;
  f.first %= MOD;
  for (int i = 0; i < 62; i++){
    f.second[i] |= g.second[i];
  }
  return f;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> prime(301, true);
  vector<int> p;
  for (int i = 2; i <= 300; i++){
    if (prime[i]){
      p.push_back(i);
      for (int j = i * 2; j <= 300; j += i){
        prime[j] = false;
      }
    }
  }
  int cnt = p.size();
  vector<vector<int>> f(301);
  for (int i = 2; i <= 300; i++){
    for (int j = 0; j < cnt; j++){
      if (i % p[j] == 0){
        f[i].push_back(j);
      }
    }
  }
  vector<long long> M(cnt);
  for (int i = 0; i < cnt; i++){
    M[i] = (p[i] - 1) * modinv(p[i]) % MOD;
  }
  tuple<long long, array<bool, 62>, int> E;
  get<0>(E) = 1;
  for (int i = 0; i < 62; i++){
    get<1>(E)[i] = false;
  }
  get<2>(E) = 1;
  pair<long long, array<bool, 62>> id;
  id.first = 1;
  for (int i = 0; i < 62; i++){
    id.second[i] = false;
  }
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<tuple<long long, array<bool, 62>, int>> b(n, E);
  for (int i = 0; i < n; i++){
    get<0>(b[i]) = a[i];
    for (int j : f[a[i]]){
      get<1>(b[i])[j] = true;
    }
  }
  lazy_segment_tree<tuple<long long, array<bool, 62>, int>, pair<long long, array<bool, 62>>> ST(b, op, mp, comp, E, id);
  for (int i = 0; i < q; i++){
    string t;
    cin >> t;
    if (t == "MULTIPLY"){
      int l, r, x;
      cin >> l >> r >> x;
      l--;
      pair<long long, array<bool, 62>> F = id;
      F.first = x;
      for (int j : f[x]){
        F.second[j] = true;
      }
      ST.range_apply(l, r, F);
    }
    if (t == "TOTIENT"){
      int l, r;
      cin >> l >> r;
      l--;
      tuple<long long, array<bool, 62>, int> tmp = ST.range_fold(l, r);
      long long ans = get<0>(tmp);
      for (int j = 0; j < cnt; j++){
        if (get<1>(tmp)[j]){
          ans *= M[j];
          ans %= MOD;
        }
      }
      cout << ans << "\n";
    }
  }
}