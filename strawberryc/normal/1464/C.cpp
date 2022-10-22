#include <bits/stdc++.h>

typedef long long ll;

const int N = 1e5 + 5;

int n, cnt[26];
char s[N];
ll T;

int main() {
  std::cin >> n >> T;
  scanf("%s", s + 1); n -= 2;
  T += 1 << s[n + 1] - 'a'; T -= 1 << s[n + 2] - 'a';
  for (int i = 1; i <= n; i++) cnt[s[i] - 'a']++;
  for (int c = 0; c < 26; c++) T += 1ll * cnt[c] << c;
  if (T < 0) return puts("No"), 0;
  for (int c = 25; c >= 0; c--)
    T -= std::min(T >> c + 1, 1ll * cnt[c]) << c + 1;
  return puts(T ? "No" : "Yes"), 0;
}