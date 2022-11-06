#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int main()
{
   int t;
   cin >> t;
   while(t--) {
      ll v, c, n, m;
      cin >> v >> c >> n >> m;

      if(min(v, c) >= m && (v + c) >= (n + m)) puts("Yes");
      else puts("No");
   }
}