#include <bits/stdc++.h>
using namespace std;

const int N = 1011;
bool prime[N];
bool vis[N];

int main()
{
	ios :: sync_with_stdio(false);

	memset(prime, true, sizeof(prime));
	memset(vis, false, sizeof(vis));
	int last = -1;
	for(int i = 2; i < N; i ++)
		if(prime[i])
		{
			if(last != -1 && last + i < N)
				vis[last + i] = true;
			last = i;
			for(int j = i * 2; j < N; j += i)
				prime[j] = false;
		}

	int n, k;
	cin >> n >> k;
	int cnt = 0;
	for(int i = 2; i <= n; i ++)
		if(prime[i] && vis[i - 1])
			cnt ++;
	if(cnt >= k)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}