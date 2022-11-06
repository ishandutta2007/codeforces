#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

int fnc(int d) {
   if(d <= 1) return d;
   if(d == 2) return 5;
   if(d == 5) return 2;
   if(d == 8) return 8;
   return -1;
}

void solve() {
   int h, m;
   scanf("%d %d", &h, &m);
   int ch, cm;
   scanf("%d:%d", &ch, &cm);
   int t = ch * m + cm;
   while(1) {
      ch = t / m, cm = t % m;

      vector <int> a;
      a.push_back(cm % 10); cm /= 10;
      a.push_back(cm % 10);
      a.push_back(ch % 10); ch /= 10;
      a.push_back(ch % 10);
      auto b = a;
      bool yes = 1;
      for(int &x : a) x = fnc(x);
      for(int &x : a) if(x < 0) yes = 0;
      if(yes) {
         ch = a[0] * 10 + a[1];
         cm = a[2] * 10 + a[3];
         if(ch < h and cm < m) {
            reverse(b.begin(), b.end());
            a = b;
            printf("%d%d:%d%d\n", a[0], a[1], a[2], a[3]);
            return;
         }
      }

      t++;
      if(t == h * m) {
         puts("00:00");
         return;
      }
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}