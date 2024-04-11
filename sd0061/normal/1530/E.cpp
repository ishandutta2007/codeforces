#include <bits/stdc++.h>
const int N = 100005;

char s[N];
int n, cnt[26];
void work() {
  scanf("%s", s);
  n = strlen(s);
  std::sort(s, s + n);
  for (int i = 0; i < 26; ++i) {
    cnt[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    ++cnt[s[i] - 'a'];
  }
  for (int i = 0; i < 26; ++i) {
    if (cnt[i] == n) {
      puts(s);
      return;
    }
  }
  int single = -1;
  for (int i = 0; i < 26; ++i) {
    if (cnt[i] == 1) {
      single = i;
      putchar('a' + i);
      --cnt[i];
      break;
    }
  }
  if (single != -1) {
    for (int i = 0; i < n; ++i) {
      if (s[i] != single + 'a') {
        putchar(s[i]);
      }
    }
    puts("");
    return;
  }
  int mn = -1;
  for (int i = 0; i < 26; ++i) {
    if (cnt[i] > 0) {
      mn = i;
      break;
    }
  }
  std::string t;
  for (int i = 0; i < n; ++i) {
    if (s[i] != mn + 'a') {
      t += s[i];
    }
  }
  int a = cnt[mn];
  int b = t.size();
  if (a - b <= 2) {
    putchar('a' + mn);
    --cnt[mn];
    int k = 0;
    for (int i = 0; i < n - 1; ++i) {
      if (i % 2 == 0) {
        if (cnt[mn]) {
          putchar('a' + mn);
          --cnt[mn];
        } else {
          putchar(t[k++]);
        }
      } else {
        putchar(t[k++]);
      }
    }
  } else {
    std::vector<std::pair<char, int>> v;
    for (int i = 0; i < 26; ++i) {
      if (cnt[i]) {
        v.emplace_back('a' + i, cnt[i]);
      }
    }
    if (v.size() == 2) {
      putchar('a' + mn);
      printf("%s", t.c_str());
      for (int i = 1; i < cnt[mn]; ++i) {
        putchar('a' + mn);
      }
    } else {
      putchar(v[0].first);
      --v[0].second;
      putchar(v[1].first);
      --v[1].second;
      for (int i = 0; i < v[0].second; ++i) {
        putchar(v[0].first);
      }
      v[0].second = 0;
      putchar(v[2].first);
      --v[2].second;
      for (auto [a, b] : v) {
        while (b--) {
          putchar(a);
        }
      }
    }
  }
  puts("");
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    work();
  }

  return 0;
}

/*
5 1 | baaaaaaaaaaaaaaa : 0000000000000000 | mx = 0
14 2 | bbaaaaaaaaaaaaaa : 0100000000000000 | mx = 1
13 3 | bbabaaaaaaaaaaaa : 0101000000000000 | mx = 1
12 4 | abbbbaaaaaaaaaaa : 0000011111111111 | mx = 1
11 5 | abbbbbaaaaaaaaaa : 0000001111111111 | mx = 1
10 6 | abbbbbbaaaaaaaaa : 0000000111111111 | mx = 1
9 7 | abbbbbbbaaaaaaaa : 0000000011111111 | mx = 1
8 8 | abbbbbbbbaaaaaaa : 0000000001111111 | mx = 1
7 9 | abbbbbbbbbaaaaaa : 0000000000111111 | mx = 1
6 10 | abbbbbbbbbbaaaaa : 0000000000011111 | mx = 1
5 11 | abbbbbbbbbbbaaaa : 0000000000001111 | mx = 1
4 12 | abbbbbbbbbbbbaaa : 0000000000000111 | mx = 1
3 13 | abbbbbbbbbbbbbaa : 0000000000000011 | mx = 1
2 14 | abbbbbbbbbbbbbba : 0000000000000001 | mx = 1
1 15 | babbbbbbbbbbbbbb : 0011111111111111 | mx = 1
*/