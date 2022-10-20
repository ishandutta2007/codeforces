#include <bits/extc++.h>

template <class T>
std::map<T, int> factorize(T n) {
  std::map<T, int> res;
  for (T i = 2; i * i <= n; ++i)
    while (n % i == 0) ++res[i], n /= i;
  if (n != 1) ++res[n];
  return res;
}

template <class T>
std::set<T> divisors(T n) {
  std::set<T> res;
  for (T d = 1; d * d <= n; ++d)
    if (n % d == 0) res.insert(d), res.insert(n / d);
  return res;
}

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    auto mp = factorize(n);
    if (size(mp) == 1) {
      int cur = 1;
      for (int i = 1; i <= begin(mp)->second; ++i) {
        cur *= begin(mp)->first;
        if (i > 1) cout << ' ';
        cout << cur;
      }
      cout << "\n0\n";
    } else if (size(mp) == 2) {
      int p0, e0, p1, e1;
      tie(p0, e0) = *begin(mp);
      tie(p1, e1) = *next(begin(mp));
      if (e0 == 1 and e1 == 1) {
        cout << p0 << ' ' << p1 << ' ' << p0 * p1 << '\n';
        cout << "1\n";
      } else {
        if (e0 == 1) {
          swap(p0, p1);
          swap(e0, e1);
        }
        assert(e0 >= 2);
        auto se = divisors(n);
        for (int e : {1, p0, p0 * p1, p1, p0 * p0 * p1, p0 * p0}) se.erase(e);
        vector<int> a, b;
        for (int e : se) {
          if (e % p0 == 0) {
            a.push_back(e);
          } else {
            assert(e % p1 == 0);
            b.push_back(e);
          }
        }
        vector<int> ans{p0};
        ans.insert(begin(ans), begin(a), end(a));
        ans.push_back(p0 * p1);
        ans.insert(begin(ans), begin(b), end(b));
        ans.push_back(p1);
        ans.push_back(p0 * p0 * p1);
        ans.push_back(p0 * p0);
        for (int i = 0; i < int(size(ans)); ++i) {
          if (i) cout << ' ';
          cout << ans[i];
        }
        cout << "\n0\n";
      }
    } else {
      assert(size(mp) >= 3);
      vector<int> primes;
      for (auto [p, e] : mp) {
        primes.push_back(p);
      }
      int m = size(primes);
      primes.push_back(primes[0]);
      auto se = divisors(n);
      se.erase(1);
      for (int i = 0; i < m; ++i) {
        se.erase(primes[i]);
        se.erase(primes[i] * primes[i + 1]);
      }
      vector<vector<int>> a(m);
      for (int e : se) {
        bool done = false;
        for (int i = 0; i < m; ++i) {
          if (e % primes[i] == 0) {
            a[i].push_back(e);
            done = true;
            break;
          }
        }
        assert(done);
      }
      vector<int> ans;
      for (int i = 0; i < m; ++i) {
        ans.push_back(primes[i]);
        ans.insert(end(ans), begin(a[i]), end(a[i]));
        ans.push_back(primes[i] * primes[i + 1]);
      }
      for (int i = 0; i < int(size(ans)); ++i) {
        if (i) cout << ' ';
        cout << ans[i];
      }
      cout << "\n0\n";
    }
  }
}