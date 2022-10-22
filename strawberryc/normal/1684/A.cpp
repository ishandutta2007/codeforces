#include <bits/stdc++.h>

const int N = 114514;

char s[N];

int main() {
  int T; std::cin >> T;
  while (T--) {
  	scanf("%s", s + 1);
  	int n = strlen(s + 1);
  	if (n == 2) {putchar(s[2]); puts(""); continue;}
  	char res = s[1];
  	for (int i = 2; i <= n; i++) if (s[i] < res) res = s[i];
  	putchar(res); puts("");
  }
  return 0;
}