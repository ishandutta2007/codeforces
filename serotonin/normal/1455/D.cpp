#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+5;

typedef pair <int,int> pii;
#define x first
#define y second

void solve() {
   int n, x;
   scanf("%d %d", &n, &x);
   vector <int> b(n);
   for(int i=0; i<n; i++) scanf("%d", &b[i]);

   bool yes = 1;
   for(int i=1; i<n; i++) if(b[i] < b[i-1]) yes = 0;
   if(yes) {
      puts("0");
      return;
   }

   vector <pii> ord;
   for(int i=0; i<n; i++) ord.emplace_back(b[i], i);
   sort(ord.begin(), ord.end());

   int ans = n + 1;
   for(int k=0; k<n; k++) {
      vector <int> a = b;
      vector <int> now = b;
      a[k] = x;
      sort(a.begin(), a.end());

      int cnt = 0, cx = x;
      for(auto p : ord) {
         int i = p.y;
         if(a[i] == now[i] || now[i] <= cx) continue;

         if(a[i] == cx) swap(now[i], cx), cnt++;
         else break;

         if(i == k) break;
      }

      bool yes = 1;
      for(int i=1; i<n; i++) if(now[i] < now[i-1]) yes = 0;
      if(yes) ans = min(ans, cnt);
   }
   if(ans > n) ans = -1;
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}