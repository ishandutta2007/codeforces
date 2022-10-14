#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;

struct arbidol {
  string pref, suf;
  int q;
};

arbidol merger(arbidol a, arbidol b) {
  arbidol c;
  c.pref = a.pref;
  if (a.pref.size() < 4) {
    for (int i = 0; i < min((int) b.pref.size(), 4 - (int) a.pref.size()); i++) {
      c.pref += b.pref[i];
    }
  }
  c.suf = b.suf;
  if (b.pref.size() < 4) {
    for (int i = 0; i < min((int) a.suf.size(), 4 - (int) b.suf.size()); i++) {
      c.suf += a.suf[i];
    }
  }
  c.q = a.q + b.q;
  string ra = a.suf;
  reverse(all(ra));
  ra += b.pref;
  for (int i = 0; i < (int) ra.size() - 3; i++) {
    if (ra[i] == ra[i + 2] && ra[i + 1] == ra[i + 3] && ra[i] == 'h' && ra[i + 1] == 'a') {
      c.q++;
    }
  }
  if (a.suf == "ahah") {
    c.q--;
  }
  if (b.pref == "haha") {
    c.q--;
  }
  return c;
}

void solve() {
  string _;
  map<string, arbidol> roflan;
  int n;
  cin >> n;
  string x, cm;
  for (int i = 0; i < n; i++) {
    cin >> x >> cm;
    if (cm == "=") {
      string a, b;
      cin >> a >> _ >> b;
      roflan[x] = merger(roflan[a], roflan[b]);
    } else {
      string s;
      cin >> s;
      arbidol a;
      a.q = 0;
      for (int i = 0; i < min(4LL, (int) s.size()); i++) {
        a.pref += s[i];
        a.suf += s[(int) s.size() - 1 - i];
      }
      for (int i = 0; i < (int) s.size() - 3; i++) {
        if (s[i] == s[i + 2] && s[i + 1] == s[i + 3] && s[i] == 'h' && s[i + 1] == 'a') {
          a.q++;
        }
      }
      roflan[x] = a;
    }
  }
  cout << roflan[x].q << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}