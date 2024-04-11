#include <bits/stdc++.h>
using namespace std;

const int N = 10000007;
const int Mod = (int)1e9 + 7;
typedef long long ll;
ll f[N], g[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	f[0] = 1;
	g[0] = 0;
	for(int i = 1; i <= n; i ++)
	{
		f[i] = 3 * g[i - 1] % Mod;
		g[i] = (2 * g[i - 1] + f[i - 1]) % Mod;
	}
	cout << f[n] << '\n';
	return 0;
}