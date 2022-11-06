#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

void solve()
{
   ll a, b;
   scanf("%lld %lld", &a, &b);
   if(a < b) swap(a, b);

   ll z = min(b, a >> 1);
   ll ans = min(a - b, z);
   b -= ans, a -= ans << 1;

   z = min(a / 3, b / 3);
   ans += z << 1;
   a %= 3, b %= 3;

   if(a && b > 1) ans++;
   else if(b && a > 1) ans++;

   printf("%lld\n", ans);
}

int main()
{
   int t = 1;
   cin >> t;
   while(t--) solve();
}