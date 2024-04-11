#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 400005
#define ld double
#define mod 998244353
using namespace std;
int main()
{
	int n, c, d;
	cin >> n >> c >> d;
	int ans = n;
	d *= 5;
	for (int i = 0; i * d <= n; i++)
		ans = min(ans, (n - i * d) % c);
	cout << ans << endl;
	return 0;
}