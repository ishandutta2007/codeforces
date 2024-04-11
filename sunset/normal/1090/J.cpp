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

template<typename T> vector<int> z_algorithm(const T &a) {
  int n = a.size();
  vector<int> z(n);
  z[0] = n;
  int l = -1, r = -1;
  for (int i = 1; i < n; ++i) {
    z[i] = i >= r ? 0 : min(r - i, z[i - l]);
    while (i + z[i] < n && a[i + z[i]] == a[z[i]]) {
      ++z[i];
    }
    if (i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }
  return z;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  string foo, bar;
  cin >> foo >> bar;
  string foobar = bar + "#" + foo;
  vector<int> fail = kmp(bar);
  vector<int> z = z_algorithm(foobar);
  vector<int> cnt(bar.length() + 1);
  for (int i = 1; i < foo.length(); ++i) {
    ++cnt[z[bar.length() + i + 1]];
  }
  for (int i = bar.length() - 1; ~i; --i) {
    cnt[i] += cnt[i + 1];
  }
  long long answer = (long long)foo.length() * bar.length();
  for (int i = 1; i < bar.length(); ++i) {
    if (~fail[i]) {
      answer -= cnt[i - fail[i]];
    }
  }
  printf("%lld\n", answer);
  return 0;
}