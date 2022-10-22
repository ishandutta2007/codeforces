#include <bits/stdc++.h>

const int N = 2e5 + 5;

int n, cnt[26];
char s[N];

void yhjssa() {
  scanf("%s", s + 1); n = strlen(s + 1);
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; i++) cnt[s[i] - 'a']++;
  for (int i = 1; i <= n; i++) {
  	int c = s[i] - 'a';
  	if (cnt[c] == 1) {
  	  for (int j = i; j <= n; j++) putchar(s[j]);
  	  return (void) puts("");
	}
	cnt[c]--;
  }
}

int main() {
  int T; std::cin >> T;
  while (T--) yhjssa();
  return 0;
}