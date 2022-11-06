#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

int n, p, a[sz], cnt[sz];

bool fnc(int b)
{
   memset(cnt, 0, sizeof cnt);
   for(int i=0; i<n; i++) cnt[max(0, a[i] - b)]++;
   for(int i=0, j=1; i<n; i++) {
      j += cnt[i] - 1;
      if(j % p == 0) return 0;
   }
   return 1;
}

int main()
{
   int b = 1;
   cin >> n >> p;
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   sort(a, a+n);
   for(int i=0; i<n; i++) b = max(b, a[i] - i);

   if(!fnc(b)) {
      puts("0");
      exit(0);
   }

   int lo = 0, hi = n-1;
   while(lo < hi) {
      int md = lo + hi + 1 >> 1;
      if(fnc(b + md)) lo = md;
      else hi = md - 1;
   }

   printf("%d\n", lo + 1);
   for(int i=0; i<=lo; i++) printf("%d ", b + i);
}