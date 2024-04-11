#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int n = s.size();
  vector<int> idx;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '?') {
      idx.push_back(i);
      s[i] = ')';
    }
  }
  int res = 0;
  {
    vector<int> cnt(2 * n + 1);
    int h = n;
    cnt[h] = 1;
    for (char c : s) {
      if (c == '(') {
        ++h;
        cnt[h] = 1;
      } else {
        --h;
        res += cnt[h];
        ++cnt[h];
      }
    }
  }
  for (int p : idx) {
    s[p] = '(';
    vector<int> cnt(2 * n + 1);
    int h = n;
    cnt[h] = 1;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(') {
        ++h;
        cnt[h] = i < p;
      } else {
        --h;
        if (i >= p) {
          res += cnt[h];
        }
        cnt[h] += i < p;
      }
    }
  }
  cout << res << '\n';
}