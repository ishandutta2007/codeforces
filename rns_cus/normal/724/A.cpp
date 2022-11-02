#include <bits/stdc++.h>
using namespace std;

map <string, int> mp;

char a[1000], b[1000];

void init() {
  mp["monday"] = 0;
  mp["tuesday"] = 1;
  mp["wednesday"] = 2;
  mp["thursday"] = 3;
  mp["friday"] = 4;
  mp["saturday"] = 5;
  mp["sunday"] = 6;
}

int main() {
  //freopen("in.txt", "r", stdin);
  init();
  scanf("%s %s", a, b);
  int x = mp[a], y = mp[b];
  if ((x + 3) % 7 == y || (x + 2) % 7 == y || x == y) {
    puts("YES");
  }
  else puts("NO");
}