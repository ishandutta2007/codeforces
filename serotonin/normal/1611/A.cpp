#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   vector <int> a;
   while(n) a.push_back(n % 10), n /= 10;
   if(~a[0] & 1) puts("0");
   else if(~a.back() & 1) puts("1");
   else {
      for(int x : a) if(~x & 1) {
         puts("2");
         return;
      }
      puts("-1");
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}