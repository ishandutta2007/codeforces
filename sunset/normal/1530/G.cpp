#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    if (s == t) {
      cout << 0 << "\n";
      continue;
    }
    int cs = 0, ct = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        ++cs;
      }
      if (t[i] == '1') {
        ++ct;
      }
    }
    if (cs != ct || m == 0 || m > cs) {
      cout << -1 << "\n";
      continue;
    }
    auto solve = [&](string& s) {
      vector<pair<int, int>> res;
      auto flip = [&](int l, int r) {
        if (l < 0 || r >= n || l >= r) {
          return;
        }
        auto old_s = s;
        reverse(s.begin() + l, s.begin() + r + 1);
        if (s != old_s) {
          res.emplace_back(l, r);
        }
      };
      int c = 0;
      for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
          c++;
        }
      }
      if (c == m) {
        int p = 0;
        while (s[p] == '0') {
          ++p;
        }
        flip(p, n - 1);
        while (s[p] == '0') {
          ++p;
        }
        for (int i = p, j = n - 1; i < n; ++i, --j) {
          if (s[i] < s[j]) {
            break;
          } else if (s[i] > s[j]) {
            flip(p, n - 1);
            break;
          }
        }
      } else {
        for (int i = 0; i < c - m - 1; ++i) {
          int p = n - i, q = 0;
          while (q < m) {
            if (s[--p] == '1') {
              ++q;
            }
          }
          flip(p, n - 1 - i);
        }
        int z = n - (c - m - 1);
        while (true) {
          int p = 0;
          while (s[p] == '0') {
            ++p;
          }
          int q = z - 1;
          while (s[q] == '0') {
            --q;
          }
          int cp = 0;
          int cq = 0;
          for (int i = p; i <= q; ++i) {
            if (s[i] == '1') {
              ++cp;
            } else {
              break;
            }
          }
          for (int i = q; i >= p; --i) {
            if (s[i] == '1') {
              ++cq;
            } else {
              break;
            }
          }
          if (cq == m + 1 || (cq == m && m % 2 == 0)) {
            break;
          }
          if (cq >= cp) {
            flip(p + 1, q);
          } else {
            flip(p, q - 1);
          }
        }
        {
          int p = 0;
          while (s[p] == '0') {
            ++p;
          }
          int q = z - 1;
          while (s[q] == '0') {
            --q;
          }
          int cp = 0;
          int cq = 0;
          for (int i = p; i <= q; ++i) {
            if (s[i] == '1') {
              ++cp;
            } else {
              break;
            }
          }
          for (int i = q; i >= p; --i) {
            if (s[i] == '1') {
              ++cq;
            } else {
              break;
            }
          }
          flip(q - m + 1, z - 1);
        }
        while (true) {
          int p = 0;
          while (s[p] == '0') {
            ++p;
          }
          int q = z - 1;
          while (s[q] == '0') {
            --q;
          }
          int cp = 0;
          int cq = 0;
          for (int i = p; i <= q; ++i) {
            if (s[i] == '1') {
              ++cp;
            } else {
              break;
            }
          }
          for (int i = q; i >= p; --i) {
            if (s[i] == '1') {
              ++cq;
            } else {
              break;
            }
          }
          if (cq == m + 1 || (cq == m && m % 2 == 0)) {
            break;
          }
          if (cq % 2 != m % 2) {
            flip(p + 1, q);
          } else {
            flip(p, q - 1);
          }
        }
      }
      return res;
    };
    vector<pair<int, int>> os = solve(s);
    vector<pair<int, int>> ot = solve(t);
    if (s == t) {
      cout << os.size() + ot.size() << "\n";
      reverse(ot.begin(), ot.end());
      for (auto p : os) {
        cout << p.first + 1 << " " << p.second + 1 << "\n";
      }
      for (auto p : ot) {
        cout << p.first + 1 << " " << p.second + 1 << "\n";
      }
    } else {
      cout << -1 << "\n";
    }
  }
  return 0;
}