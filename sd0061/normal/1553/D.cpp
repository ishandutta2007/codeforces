#include <bits/stdc++.h>
const int N = 100005;
char s[N], t[N];
int n, m;

bool check(std::string& a, std::string b) {
  int j = 0;
  for (int i = 0; i < a.size(); ++i) {
    if (j < b.size() && a[i] == b[j]) {
      ++j;
    }
  }
  return j == b.size();
}

void work() {
  scanf("%s%s", s, t);
  n = strlen(s);
  m = strlen(t);

  std::reverse(t, t + m);
  std::reverse(s, s + n);
  int i = 0, j = 0;
  int cnt = 0;

  while (i < m) {
    while (j < n && s[j] != t[i]) {
      j += 2;
    }
    if (j >= n) {
      break;
    }
    ++j;
    ++i;
  }

  puts(i >= m ? "YES" : "NO");
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}