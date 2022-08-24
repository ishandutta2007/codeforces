#include <bits/stdc++.h>

using namespace std;

int main()
{
int n, ans = 0, cval = 1e9, ctot = 0;
cin >> n;
for (int i = 0; i < n; i++)
{
int x; cin >> x;
if (x >= cval) ctot++;
else ctot = 1;
cval = x;
ans = max (ans, ctot);
}
cout << ans << "\n";
return 0;
}