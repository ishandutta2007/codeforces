#include <bits/stdc++.h>

using namespace std;

template <typename T>
pair<vector<int>, vector<int>> lyndon(const T& s, int n) {
  vector<int> p;
  vector<int> q;
  for (int i = 0; i < n; ) {
    int j = i, k = i + 1;
    while (k < n && s[j] <= s[k]) {
      if (s[j] < s[k]) {
        j = i;
      } else {
        ++j;
      }
      ++k;
    }
    p.push_back(i);
    q.push_back(k - j);
    while (i <= j) {
      i += k - j;
    }
  }
  return make_pair(p, q);
}

template <typename T>
vector<int> z_algorithm(const T& s, int n) {
  vector<int> z(n);
  z[0] = n;
  int l = -1, r = -1;
  for (int i = 1; i < n; ++i) {
    z[i] = i >= r ? 0 : min(r - i, z[i - l]);
    while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
      ++z[i];
    }
    if (i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }
  return z;
}

string reverse(string s) {
  reverse(s.begin(), s.end());
  return s;
}

string minimal(string s) {
  return min(s, reverse(s));
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  int m;
  cin >> s >> m;
  int n = s.size();
  s = reverse(s) + "#" + s;
  vector<int> z = z_algorithm(s, n * 2 + 1);
  vector<int> p, q;
  tie(p, q) = lyndon(s, n);
  p.push_back(n);
  string pref;
  while ((int) p.size() > 1 && m > 2) {
    pref += s.substr(p[p.size() - 2], p.back() - p[p.size() - 2]);
    int l = q.back();
    p.pop_back();
    q.pop_back();
    if (l == 1) {
      while ((int) p.size() > 1 && q.back() == 1) {
        pref += s.substr(p[p.size() - 2], p.back() - p[p.size() - 2]);
        p.pop_back();
        q.pop_back();
      }
    }
    --m;
  }
  string suff = minimal(s.substr(0, p.back()));
  if (m > 1 && (int) p.size() > 1) {
    for (int i = 0; i < 2 && i < (int) p.size() - 1; ++i) {
      int who = p[p.size() - 2 - i];
      suff = min(suff, minimal(s.substr(who, p.back() - who)) + minimal(s.substr(0, who)));
    }
    int who = 0;
    for (int i = 1; i < p.back(); ++i) {
      if (z[n * 2 - i] < i - who) {
        if (s[z[n * 2 - i]] < s[i - z[n * 2 - i]]) {
          who = i;
        }
      } else {
        if (s[i - who + z[i - who]] < s[z[i - who]]) {
          who = i;
        }
      }
    }
    ++who;
    suff = min(suff, minimal(s.substr(who, p.back() - who)) + minimal(s.substr(0, who)));
  }
  cout << pref + suff << "\n";
  return 0;
}