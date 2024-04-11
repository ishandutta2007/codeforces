#include <bits/stdc++.h>
using namespace std;
string str;
int main() {
  int n;
  for (int i = 1; i < 1000; i++) {
    char s[10];
    sprintf(s, "%d", i);
    str += s;
  }
  scanf("%d", &n);
  printf("%c\n", str[n - 1]);
}