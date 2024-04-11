#include <bits/stdc++.h>
#define maxn 200005
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
int main()
{
	int b, g, n;
	cin >> b >> g >> n;
	int ans = 0;
	for (int i = 0; i <= n; i++)
		if (i <= b && n - i <= g) ans++;
	cout << ans << endl;
 	return 0;
}