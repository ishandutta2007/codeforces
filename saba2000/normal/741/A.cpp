#include <bits/stdc++.h>

using namespace std;

bool vis[105];
int n,go[105];
long long ans;

long long gcd(long long a,long long b)
{
	return b ? gcd(b,a % b) : a;
}

int main()
{
	cin >> n;
	for(int i = 1;i <= n;i ++) cin >> go[i];
	ans = 1;
	for(int i = 1;i <= n;i ++)
		if (!vis[i])
		{
			int j = i,l = 0;
			for(;!vis[j];)
			{
				vis[j] = 1,++ l;
				j = go[j];
				if (vis[j]) break;
			}
			if (j != i) {cout << -1 << endl;return 0;}
			if (l % 2 == 0) l /= 2;
			ans = ans * (l / gcd(ans,(long long)l));
		}
	cout << ans << endl;
	return 0;}