#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 55;

void solve() {
   int n, f = 0;
   scanf("%d", &n);
   n--;
   if(!n) {
      puts("a");
      return;
   }
   if(~n & 1) f = 1, n--;
   int x = n >> 1;
   for(int i=0; i<=x; i++) printf("a");
   printf("b"); if(f) printf("c");
   for(int i=0; i<x; i++) printf("a"); puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}