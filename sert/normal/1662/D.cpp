#include <bits/stdc++.h>
using namespace std;

const array<string, 5> v = {"AA", "BB", "CC", "ABAB", "BCBC"};

void dfs(const string &s, set<string> &u) {
  if (u.count(s) || s.length() > 9) return;
  u.insert(s);

  for (const auto &ss : v) {
    for (int pos = 0; pos <= static_cast<int>(s.length()); pos++) {
      dfs(s.substr(0, pos) + ss + s.substr(pos), u);
      if (pos + ss.length() <= s.length() && ss == s.substr(pos, ss.length())) {
        dfs(s.substr(0, pos) + s.substr(pos + ss.length()), u);
      }
    }
  }
}

bool stress(const string &x, const string &y) {
  set<string> u;
  dfs(x, u);
  return u.count(y);
}

string kek(const string &s) {
  string res;
  char cur = 'A';
  int num = 0;

  for (char ch : s) {
    if (ch == 'B') continue;
    if (ch == cur) num++;
    else {
      if (num % 2) {
        if (!res.empty() && res.back() == cur) {
          res.pop_back();
        } else {
          res.push_back(cur);
        }
      }
      cur = (cur == 'A' ? 'C' : 'A');
      num = 1;
    }
  }

  if (num % 2) {
    if (!res.empty() && res.back() == cur) {
      res.pop_back();
    } else {
      res.push_back(cur);
    }
  }
  //cout << s << " -> " << res << "\n";
  return res;
}

bool solve(string x = "", string y = "") {
  if (x.empty()) {
    cin >> x >> y;
  }
  if (count(x.begin(), x.end(), 'B') % 2 != count(y.begin(), y.end(), 'B') % 2) {
    return false;
  }

  return kek(x) == kek(y);
}

void test() {
  mt19937 rnd(3431);
  auto gen = [&](int len) {
    string res;
    for (int i = 0; i < len; i++) {
      res.push_back(char('A' + static_cast<int>(rnd() % 3)));
    }
    return res;
  };

  for (int i = 0; i < 1000; i++) {
    if ((i & (i + 1)) == 0) cout << i << endl;
    string x = gen(3 + static_cast<int>(rnd() % 4));
    string y = gen(3 + static_cast<int>(rnd() % 4));
    bool r1 = solve(x, y);
    bool r2 = stress(x, y);
    if (r1 != r2) {
      cout << x << " " << y << " " << r1 << " " << r2 << "\n";
      exit(11);
    }
  }

  exit(0);
}

#ifdef SERT
bool D = true;
#else
bool D = false;
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  if (D) {
    //test();
    freopen("../a.in", "r", stdin);
    //t = 4;
  }
  cin >> t;
  while (t--) {
    cout << (solve() ? "YES\n" : "NO\n");
  }
}