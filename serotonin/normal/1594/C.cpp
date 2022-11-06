#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+7;

char s[sz];
vector <int> dv[sz];
bool ya[sz];

void solve() {
   int n; char ch;
   scanf("%d %c %s", &n, &ch, s);
   for(int i=1; i<=n; i++) ya[i] = 1;

   int c = 0;
   for(int i=0; i<n; i++) if(s[i] != ch) {
      for(int &j : dv[i+1]) ya[j] = 0;
      c++;
   }

   if(!c) {
      puts("0");
      return;
   }

   for(int i=1; i<=n; i++) if(ya[i]) {
      puts("1");
      printf("%d\n", i);
      return;
   }

   puts("2");
   printf("%d %d\n", n - 1, n);
}

int main() {
   for(int i=1; i<sz; i++) {
      for(int j=i; j<sz; j+=i) dv[j].push_back(i);
   }

   int t;
   cin >> t;
   while(t--) solve();
}