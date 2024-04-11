#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
vector<int> suffix_array(const vector<int> &A, int mx){
  int N = A.size();
  vector<int> sum(mx + 1, 0);
  for (int i = 0; i < N; i++){
    sum[A[i] + 1]++;
  }
  for (int i = 0; i < mx; i++){
    sum[i + 1] += sum[i];
  }
  vector<bool> is_s(N);
  is_s[N - 1] = false;
  for (int i = N - 2; i >= 0; i--){
    is_s[i] = A[i] < A[i + 1] || A[i] == A[i + 1] && is_s[i + 1];
  }
  vector<int> id(N, -1);
  vector<int> pos;
  int M = 0;
  for (int i = 1; i < N; i++){
    if (is_s[i] && !is_s[i - 1]){
      id[i] = M;
      pos.push_back(i);
      M++;
    }
  }
  vector<int> sa(N);
  auto induce = [&](vector<int>& lms){
    sa = vector<int>(N, -1);
    vector<bool> used(N, false);
    vector<int> p(mx);
    vector<int> p2(mx);
    for (int i = 0; i < mx; i++){
      p[i] = sum[i + 1] - 1;
      p2[i] = sum[i];
    }
    for (int i = M - 1; i >= 0; i--){
      sa[p[A[lms[i]]]] = lms[i];
      p[A[lms[i]]]--;
      used[lms[i]] = true;
    }
    sa[p2[A[N - 1]]] = N - 1;
    p2[A[N - 1]]++;
    used[N - 1] = true;
    for (int i = 0; i < N; i++){
      if (sa[i] > 0){
        if (!is_s[sa[i] - 1] && !used[sa[i] - 1]){
          sa[p2[A[sa[i] - 1]]] = sa[i] - 1;
          p2[A[sa[i] - 1]]++;
          used[sa[i] - 1] = true;
        }
      }
    }
    for (int i = 0; i < N; i++){
      if (sa[i] != -1){
        if (id[sa[i]] != -1){
          used[sa[i]] = false;
          sa[i] = -1;
        }
      }
    }
    for (int i = 0; i < mx; i++){
      p[i] = sum[i + 1] - 1;
    }
    for (int i = N - 1; i >= 0; i--){
      if (sa[i] > 0){
        if (is_s[sa[i] - 1] && !used[sa[i] - 1]){
          sa[p[A[sa[i] - 1]]] = sa[i] - 1;
          p[A[sa[i] - 1]]--;
          used[sa[i] - 1] = true;
        }
      }
    }
  };
  induce(pos);
  if (M == 0){
    return sa;
  }
  vector<int> lms;
  for (int i = 0; i < N; i++){
    if (id[sa[i]] != -1){
      lms.push_back(sa[i]);
    }
  }
  vector<int> c(M);
  c[0] = 0;
  for (int i = 0; i < M - 1; i++){
    c[i + 1] = c[i];
    int x = lms[i];
    int y = lms[i + 1];
    bool ok = true;
    while (x < N && y < N){
      if (A[x] != A[y]){
        ok = false;
        break;
      }
      x++;
      y++;
      if (id[x] != -1){
        if (id[y] == -1){
          ok = false;
        }
        break;
      }
    }
    if (x == N || y == N){
      ok = false;
    }
    if (!ok){
      c[i + 1]++;
    }
  }
  vector<int> rec(M);
  for (int i = 0; i < M; i++){
    rec[id[lms[i]]] = c[i];
  }
  vector<int> sa2 = suffix_array(rec, c[M - 1] + 1);
  vector<int> pos2(M);
  for (int i = 0; i < M; i++){
    pos2[i] = pos[sa2[i]];
  }
  induce(pos2);
  return sa;
}
vector<int> suffix_array(const string &S){
  int N = S.size();
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    A[i] = S[i];
  }
  return suffix_array(A, 256);
}
template <typename T>
vector<int> lcp_array(const T &A, vector<int> &SA){
  int N = A.size();
  vector<int> rank(N);
  for (int i = 0; i < N; i++){
    rank[SA[i]] = i;
  }
  vector<int> lcp(N - 1, 0);
  int h = 0;
  for (int i = 0; i < N; i++){
    if (rank[i] > 0){
      int prev = SA[rank[i] - 1];
      if (h > 0){
        h--;
      }
      while (i + h < N && prev + h < N){
        if (A[i + h] != A[prev + h]){
          break;
        }
        h++;
      }
      lcp[rank[i] - 1] = h;
    }
  }
  return lcp;
}
template <typename T>
vector<int> manacher(const T &A){
  int N = A.size();
  vector<int> ans(N, 0);
  int i = 0, j = 0;
  while (i < N){
    while (i >= j && i + j < N && A[i - j] == A[i + j]){
      j++;
    }
    ans[i] = j;
    int k = 1;
    while (i >= k && i + k < N && k + ans[i - k] < j){
      ans[i + k] = ans[i - k];
      k++;
    }
    i += k;
    j -= k;
  }
  return ans;
}
#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder
namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder
int op_mn(int a, int b){
  return min(a, b);
}
int e_mn(){
  return INF;
}
int op_mx(int a, int b){
  return max(a, b);
}
int e_mx(){
  return -INF;
}
int query;
bool f(int x){
  return x >= query;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> q;
  vector<string> t(q);
  vector<char> c(q);
  for (int i = 0; i < q; i++){
    cin >> t[i];
    if (t[i] == "push"){
      cin >> c[i];
    }
  }
  string S;
  for (int i = 0; i < q; i++){
    if (t[i] == "push"){
      S += c[i];
    }
  }
  int N = S.size();
  string S2 = S;
  reverse(S2.begin(), S2.end());
  vector<int> SA = suffix_array(S);
  vector<int> SA2 = suffix_array(S2);
  vector<int> LCP = lcp_array(S, SA);
  vector<int> LCP2 = lcp_array(S2, SA2);
  atcoder::segtree<int, op_mn, e_mn> ST1(LCP);
  atcoder::segtree<int, op_mn, e_mn> ST2(LCP2);
  string T = "$";
  for (int i = 0; i < N; i++){
    T += S[i];
    T += '$';
  }
  vector<int> M = manacher(T);
  vector<int> left(N * 2 - 1), right(N * 2 - 1);
  for (int i = 0; i < N * 2 - 1; i++){
    left[i] = (i - M[i + 1] + 3) / 2;
    right[i] = (i + M[i + 1]) / 2;
  }
  vector<vector<int>> left_pos(N + 1);
  vector<vector<int>> right_pos(N + 1);
  for (int i = 0; i < N * 2 - 1; i++){
    left_pos[left[i]].push_back(i);
    right_pos[right[i]].push_back(i);
  }
  vector<int> I(N * 2 - 1);
  for (int i = 0; i < N * 2 - 1; i++){
    I[i] = i;
  }
  atcoder::segtree<int, op_mn, e_mn> ST3(I);
  atcoder::segtree<int, op_mx, e_mx> ST4(N * 2 - 1);
  vector<int> rank(N);
  for (int i = 0; i < N; i++){
    rank[SA[i]] = i;
  }
  vector<int> rank2(N);
  for (int i = 0; i < N; i++){
    rank2[SA2[i]] = i;
  }
  atcoder::segtree<int, op_mn, e_mn> ST5(SA);
  atcoder::segtree<int, op_mn, e_mn> ST6(N);
  int L = 0, R = 0;
  int ans = 0;
  for (int i : left_pos[0]){
    ST4.set(i, i);
  }
  for (int i = 0; i < q; i++){
    if (t[i] == "push"){
      int p = ST3.prod(L + R, R * 2 + 1);
      int pl = p - R;
      int len = R - pl + 1;
      query = len;
      int l = ST1.min_left<f>(rank[pl]);
      int r = ST1.max_right<f>(rank[pl]) + 1;
      int m = ST5.prod(l, r);
      if (m >= pl){
        ans++;
      }
      R++;
      for (int j : right_pos[R]){
        ST3.set(j, INF);
      }
      ST6.set(rank2[N - R], N - R);
    }
    if (t[i] == "pop"){
      int p = ST4.prod(L * 2, L + R);
      int pr = p + 1 - L;
      int len = pr - L;
      query = len;
      int l = ST2.min_left<f>(rank2[N - pr]);
      int r = ST2.max_right<f>(rank2[N - pr]) + 1;
      int m = ST6.prod(l, r);
      if (m == N - pr){
        ans--;
      }
      ST5.set(rank[L], INF);
      L++;
      for (int j : left_pos[L]){
        ST4.set(j, j);
      }
    }
    cout << ans << "\n";
  }
}