#include <bits/stdc++.h>

using namespace std;

template<typename T> vector<int> kmp(const T &a) {
  int n = a.size();
  vector<int> fail(n);
  fail[0] = -1;
  for (int i = 1; i < n; ++i) {
    fail[i] = fail[i - 1];
    while (~fail[i] && a[fail[i] + 1] != a[i]) {
      fail[i] = fail[fail[i]];
    }
    if (a[fail[i] + 1] == a[i]) {
      ++fail[i];
    }
  }
  return fail;
}

template<typename T> vector<int> kmp(const T &a, const T &b) {
  vector<int> fail = kmp(b);
  int n = a.size(), m = b.size();
  vector<int> result;
  for (int i = 0, j = -1; i < n; ++i) {
    while (~j && a[i] != b[j + 1]) {
      j = fail[j];
    }
    if (a[i] == b[j + 1]) {
      ++j;
    }
    if (j == m - 1) {
      result.push_back(i - m + 1);
      j = fail[j];
    }
  }
  return result;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> s(n), t(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }
  vector<int> p(n);
  string left = "", right = "", from = "", to = "";
  for (int i = 0; i < n; ++i) {
    if (s[i] == t[i]) {
      p[i] = s[i].length();
      continue;
    }
    int l = s[i].length(), r = -1;
    for (int j = 0; j < s[i].length(); ++j) {
      if (s[i][j] != t[i][j]) {
        l = min(l, j);
        r = max(r, j);
      }
    }
    p[i] = l;
    if (from == "") {
      from = s[i].substr(l, r - l + 1);
      to = t[i].substr(l, r - l + 1);
      left = s[i].substr(0, l);
      reverse(left.begin(), left.end());
      right = s[i].substr(r + 1, s[i].length() - r - 1);
    } else {
      if (from != s[i].substr(l, r - l + 1)) {
        cout << "NO" << endl;
        return 0;
      }
      if (to != t[i].substr(l, r - l + 1)) {
        cout << "NO" << endl;
        return 0;
      }
      string foo = s[i].substr(0, l);
      reverse(foo.begin(), foo.end());
      int pl = 0;
      while (pl < left.length() && pl < foo.length() && left[pl] == foo[pl]) {
        ++pl;
      }
      left.resize(pl);
      string bar = s[i].substr(r + 1, s[i].length() - r - 1);
      int pr = 0;
      while (pr < right.length() && pr < bar.length() && right[pr] == bar[pr]) {
        ++pr;
      }
      right.resize(pr);
    }
  }
  reverse(left.begin(), left.end());
  from = left + from + right;
  to = left + to + right;
  for (int i = 0; i < n; ++i) {
    vector<int> all = kmp(s[i], from);
    if (!all.empty() && all[0] < p[i] - left.length()) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl << from << endl << to << endl;
  return 0;
}