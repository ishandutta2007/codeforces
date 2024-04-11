#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
const int M = 1000000007;
const long long LM = 1LL << 60;


struct manacher {
  vector<int> rads;
  static char get(const string &s, int i) {
    if (i & 1) return '$';
    else return s[i >> 1];
  }

public:
  manacher(const string &s) : rads((int)s.size() * 2 - 1){
    int size = rads.size();
    int i = 0, j = 0;
    while (i < size) {
      while (i - j >= 0 && i + j < size && get(s, i - j) == get(s, i + j)) {
        ++j;
      }
      rads[i] = j;
      int k = 1;
      while (i - k >= 0 && i + k < size && k + rads[i - k] < j) {
        rads[i + k] = rads[i - k], ++k;
      }
      i += k;
      j -= k;
    }
  }

  bool is_palindrome(int l, int r) {
    return rads[l + r - 1] >= r - l;
  }

};

vector<int> pal_length(const string& s_) {
    string s = "^" + s_;
    int n = s.length();
    vector<int> pl(n, M), gpl(n, n);
    pl[0] = 0;
    vector<tuple<int, int, int>> g;
    for (int j = 1; j < n; ++j) {
        vector<tuple<int, int, int>> g1, g2;
        for (auto [i, d, k] : g) {
            if (i > 0 && s[i - 1] == s[j]) {
                g1.emplace_back(i - 1, d, k);
            }
        }
        int r = -j;
        for (auto [i, d, k] : g1) {
            if (i - r != d) {
                g2.emplace_back(i, i - r, 1);
                if (k > 1) {
                    g2.emplace_back(i + d, d, k - 1);
                }
            }
            else {
                g2.emplace_back(i, d, k);
            }
            r = i + (k - 1) * d;
        }
        if (j > 1 && s[j - 1] == s[j]) {
            g2.emplace_back(j - 1, j - 1 - r, 1);
            r = j - 1;
        }
        // g2.emplace_back(j, j - r, 1);
        g.clear();
        for (auto [i, d, k] : g2) {
            if (g.empty() || get<1>(g[(int)g.size() - 1]) != d) {
                g.emplace_back(i, d, k);
            }
            else {
                get<2>(g[(int)g.size() - 1]) += k;
            }
        }
        // pl[j] = j;
        if (j > 1 && s[j - 1] == s[j]) {
            pl[j] = pl[j - 2];
        }
        for (auto [i, d, k] : g) {
            r = i + (k - 1) * d;
            int m = pl[r - 1] + 1;
            if (k > 1) {
                m = min(m, gpl[i - d]);
            }
            if (d <= i) {
                gpl[i - d] = m;
            }
            pl[j] = min(pl[j], m);
        }
    }
    return pl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    string s, t;
    cin >> s >> t;
    int n = s.length();
    string st = "";
    for (int i = 0; i < n; ++i) {
        st += s[i];
        st += t[i];
    }
    manacher man(st);
    vector<int> v = pal_length(st);
    if (v[n * 2] == M) {
        cout << -1 << '\n';
        return 0;
    }
    vector<P> ans;
    int j = n * 2;
    while (j > 0) {
        if (man.is_palindrome(j - 2, j) && v[j - 2] == v[j]) {
            j -= 2;
            continue;
        }
        for (int k = j - 4; k >= 0; --k) {
            if (man.is_palindrome(k, j) && v[k] + 1 == v[j]) {
                ans.emplace_back(k / 2, j / 2);
                j = k;
                break;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto& i : ans) {
        cout << i.first + 1 << ' ' << i.second << '\n';
    }
    return 0;
}