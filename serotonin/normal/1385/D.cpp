#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

char s[sz];

int fnc(int l, int r, char c) {
   int d = r - l;
   if(d == 1) return s[l] != c;

   int now1 = fnc(l+d/2, r, c+1);
   for(int i=0; i<d/2; i++) {
      if(s[l+i] != c) now1++;
   }

   int now2 = fnc(l, r-d/2, c+1);
   for(int i=0; i<d/2; i++) {
      if(s[r-1-i] != c) now2++;
   }

   return min(now1, now2);
}

void solve() {
   int n;
   cin >> n;
   scanf("%s", s);
   printf("%d\n", fnc(0, n, 'a'));
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}