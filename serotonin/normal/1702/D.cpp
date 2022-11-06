#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

char s[sz];

void solve() {
   int p;
   scanf("%s %d", s, &p);
   int sum = 0, cnt[27] = {};
   for(int i=0; s[i]; i++) {
      int x = s[i] - 'a' + 1;
      cnt[x]++, sum += x;
   }
   for(int i=26; i; i--) {
      while(cnt[i] and sum > p) sum -= i, cnt[i]--;
   }
   for(int i=0; s[i]; i++) {
      int x = s[i] - 'a' + 1;
      if(cnt[x]) cnt[x]--, printf("%c", s[i]);
   }
   puts("");
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}