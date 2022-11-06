#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5e5+5;

char s[sz];

int main() {
   int t;
   cin >> t;
   while(t--) {
      int n;
      scanf("%d %s", &n, s);
      int cnt = 0;
      for(int i=0; s[i]; i++) cnt += s[i] == '0';
      if(!cnt) puts("DRAW");
      else if(cnt & 1) {
         if(cnt == 1) puts("BOB");
         else puts("ALICE");
      }
      else puts("BOB");
   }
}