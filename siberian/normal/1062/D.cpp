#include <bits/stdc++.h>
 using namespace std;
 #define int long long
 signed main()
 {
     
     int n;
     cin >> n;
     
     
     int ans = 0;
     for (int i = 2; i <= n; i++)
     {
         for (int x = 2; x*x <= i; x++)
         {
             if (i % x == 0)
             {
                 ans += x;
                 ans += i / x;
             }
             if (x*x == i)
                ans -= x;
         }
     }
     cout << ans * 4;
     return 0;
 }