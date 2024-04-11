#include <bits/stdc++.h>

#ifndef LOCAL
#define LOCAL 0
#define DUMP(...) void(0)
#endif

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    string s;
    cin >> s;
    assert(int(size(s)) == a + b + 2 * c + 2 * d);
    if (int(count(begin(s), end(s), 'A')) != a + c + d) {
      cout << "NO\n";
      continue;
    }
    s = s[0] + s + s.back();
    int common = 0;
    vector<int> vc;
    vector<int> vd;
    for (int l = 1; l < int(size(s)) - 1;) {
      if (s[l] == s[l + 1]) {
        ++l;
        continue;
      }
      int r = l;
      while (s[r] != s[r + 1]) {
        ++r;
      }
      if ((r - l) & 1) {
        int t = (r - l) / 2;
        common += t;
        if (s[l - 1] == 'A') {
          vc.push_back(t);
        } else {
          vd.push_back(t);
        }
      } else {
        common += (r - l) / 2;
      }
      l = r;
    }
    sort(begin(vc), end(vc));
    sort(begin(vd), end(vd));
    DUMP(a, b, c, d);
    DUMP(s);
    DUMP(common);
    DUMP(vc);
    DUMP(vd);
    partial_sum(begin(vc), end(vc), begin(vc));
    partial_sum(begin(vd), end(vd), begin(vd));
    bool ok = false;
    for (int x = 0; x <= common; ++x) {
      int y = common - x;
      int cur_c = x + int(upper_bound(begin(vc), end(vc), x) - begin(vc));
      int cur_d = y + int(upper_bound(begin(vd), end(vd), y) - begin(vd));
      if (c <= cur_c && d <= cur_d) {
        ok = true;
        break;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}