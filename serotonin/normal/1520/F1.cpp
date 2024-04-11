#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+5;

int ask(int l, int r) {
   int sum;
   printf("? %d %d\n", l, r); fflush(stdout);
   scanf("%d", &sum);
   return sum;
}

int main() {
   int n, t, k;
   cin >> n >> t >> k;

   int lo = 1, hi = n;
   while(lo < hi) {
      int md = lo + hi >> 1;
      int sum = md - ask(1, md);
      if(sum < k) lo = md + 1;
      else hi = md;
   }
   printf("! %d\n", lo); fflush(stdout);
}