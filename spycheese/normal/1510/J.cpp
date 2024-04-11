#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = sz(s);
  
  int len0 = 0;
  int len1 = 0;
  while (len0 < n && s[len0] == '_') ++len0;
  if (len0 == n) {
    cout << "0\n";
    return 0;
  }
  while (len1 < n && s[n - 1 - len1] == '_') ++len1;

  vector<int> lens;
  for (int i = len0; i < n;) {
    if (s[i] == '#') {
      ++i;
      continue;
    }
    int j = i;
    while (i < n && s[i] == '_') ++i;
    if (i != n) lens.push_back(i - j);
  }

  sort(all(lens));
  int q = -1;
  for (int i = 0; i <= len1 && i <= len0 && (lens.empty() || i + 1 <= lens[0]); ++i) {
    if (i == 0) {
      if (!lens.empty() && lens.back() > 1) continue;
      if (len0 > 0) continue;
      if (len1 > 0) continue;
    } else if (i == 1) {
      if ((len0 - i) % 2 == 1) continue;
      if ((len1 - i) % 2 == 1) continue;
      bool ok = 1;
      for (int x : lens)
        if ((x - i) % 2 == 0)
          ok = 0;
      if (!ok) continue;
    } else {
      if (len1 - i == 1) continue;
      if (len0 - i == 1) continue;
      if (binary_search(all(lens), i + 2)) continue;
    }
    q = i;
    break;
  }
  if (q == -1) {
    cout << "-1\n";
    return 0;
  }

  vector<int> ans;
  auto addv = [&](int len) {
    if (len <= 0) return;
    assert(len > 0);
    if (len % 2 == 1) {
      for (int i = 0; i < len / 2 + 1; ++i)
        ans.push_back(1);
    } else {
      ans.push_back(2);
      for (int i = 0; i < (len - 2) / 2; ++i)
        ans.push_back(1);
    }
  };
  addv(len0 - q - 1);

  for (int i = len0; i < n;) {
    int j = i;
    while (j < n && s[j] == '#') ++j;
    ans.push_back(j - i + q);
    int k = j;
    while (k < n && s[k] == '_') ++k;
    if (k != n) {
      addv(k - j - q - 2);
    }
    i = k;
  }

  addv(len1 - q - 1);

  cout << sz(ans) << "\n";
  for (int x : ans) cout << x << " ";
  cout << "\n";
}