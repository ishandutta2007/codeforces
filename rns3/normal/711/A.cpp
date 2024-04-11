#include <bits/stdc++.h>
using namespace std;

char s[2001][11];

int main() {
  ///freopen("1.in", "r", stdin);
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i ++) scanf("%s", s[i]);
  for(int i = 0; i < n; i ++) {
    if(s[i][0] == 'O' && s[i][1] == 'O') {
      puts("YES");
      s[i][0] = '+'; s[i][1] = '+';
      for(int j = 0; j < n; j ++) printf("%s\n", s[j]);
      return 0;
    }
    if(s[i][3] == 'O' && s[i][4] == 'O') {
      puts("YES");
      s[i][3] = s[i][4] = '+';
      for(int j = 0; j < n; j ++) printf("%s\n", s[j]);
      return 0;
    }
  }
  puts("NO");
  return 0;
}