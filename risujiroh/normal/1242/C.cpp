#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int k; cin >> k;
  V<> n(k);
  VV<> a(k);
  V<lint> s(k);
  lint sum = 0;
  struct Ij { int i, j; };
  map<int, Ij> mp;
  for (int i = 0; i < k; ++i) {
    cin >> n[i];
    a[i].resize(n[i]);
    for (auto&& e : a[i]) cin >> e;
    // sort(begin(a[i]), end(a[i]));
    s[i] = accumulate(begin(a[i]), end(a[i]), 0LL);
    sum += s[i];
    for (int j = 0; j < n[i]; ++j) {
      mp[a[i][j]] = {i, j};
    }
  }
  if (sum % k) {
    return cout << "No" << '\n', 0;
  }
  sum /= k;
  bitset<1 << 15> dp;
  dp[0] = true;
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < n[i]; ++j) {
      int ni = i, nj = j;
      bool ok = false;
      int S = 0;
      int lim = 20;
      while (lim--) {
        lint x = sum - (s[ni] - a[ni][nj]);
        if (mp.count(x)) {
          ni = mp[x].i;
          nj = mp[x].j;
          S |= 1 << ni;
        } else {
          ok = false;
          break;
        }
        if (ni == i) {
          ok = nj == j;
          break;
        }
      }
      if (ok) {
        dp[S] = true;
      }
    }
  }

  for (int S = 1; S < 1 << k; ++S) {
    for (int T = S; ; T = (T - 1) & S) {
      if (dp[T] and dp[S ^ T]) {
        dp[S] = true;
        break;
      }
      if (T == 0) break;
    }
  }
  if (not dp[~(~0U << k)]) {
    return cout << "No" << '\n', 0;
  }
  cout << "Yes" << '\n';
  V<> v;
  auto dfs = [&](auto& F, int S) -> void {
    for (int T = (S - 1) & S; T; T = (T - 1) & S) {
      if (dp[T] and dp[S ^ T]) {
        F(F, T);
        F(F, S ^ T);
        return;
      }
    }
    v.push_back(S);
  };
  dfs(dfs, ~(~0U << k));
  V< array<int, 2> > res(k);
  for (int S : v) {
    for (int i = 0; i < k; ++i) if (S >> i & 1) {
      for (int j = 0; j < n[i]; ++j) {
        int ni = i, nj = j;
        bool ok = false;
        int T = 0;
        int lim = 20;
        while (lim--) {
          lint x = sum - (s[ni] - a[ni][nj]);
          if (mp.count(x)) {
            ni = mp[x].i;
            nj = mp[x].j;
            T |= 1 << ni;
          } else {
            ok = false;
            break;
          }
          if (ni == i) {
            ok = nj == j;
            break;
          }
        }
        if (ok and T == S) {
          ni = i, nj = j;
          while (true) {
            lint x = sum - (s[ni] - a[ni][nj]);
            assert(mp.count(x));
            res[mp[x].i] = {(int)x, ni};
            ni = mp[x].i;
            nj = mp[x].j;
            if (ni == i) {
              assert(nj == j);
              break;
            }
          }
          break;
        }
      }
      break;
    }
  }
  for (const auto& e : res) {
    cout << e[0] << ' ' << e[1] + 1 << '\n';
  }
}