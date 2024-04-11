#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1005;

bool notprime(int n)
{
   for(int i=2; i*i<=n; i++) {
      if(n % i == 0) return 1;
   }
   return 0;
}

bool fnc(int n)
{
   if(n == 1) return 0;
   if(n == 2) return 1;
   if(n & 1) return 1;

   int k = 0;
   while(n % 2 == 0) n >>= 1, k++;
   if(k > 1) return n > 1;
   return notprime(n);
}

void solve()
{
   int n;
   scanf("%d", &n);
   if(fnc(n)) puts("Ashishgup");
   else puts("FastestFinger");
}

int main()
{
   int t;
   cin >> t;
   while(t--) solve();
}