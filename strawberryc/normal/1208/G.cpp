#include <bits/stdc++.h>

typedef long long ll;

const int N = 1e6 + 5;

int n, k, tot, pri[N], phi[N], d[N], cnt[N];
bool mark[N];

struct node
{
	int x;
	
	friend inline bool operator < (node a, node b)
	{
		return phi[a.x] > phi[b.x];
	}
};

std::priority_queue<node> pq;

ll ans;

void sieve()
{
	mark[0] = mark[phi[1] = 1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (!mark[i]) phi[pri[++tot] = i] = i - 1;
		for (int j = 1; j <= tot; j++)
		{
			if (1ll * i * pri[j] > n) break;
			mark[i * pri[j]] = 1;
			if (i % pri[j] == 0)
			{
				phi[i * pri[j]] = phi[i] * pri[j];
				break;
			}
			else phi[i * pri[j]] = phi[i] * (pri[j] - 1);
		}
	}
	for (int i = 3; i <= n; i++)
		for (int j = i; j <= n; j += i)
			d[j]++;
}

int main()
{
	std::cin >> n >> k;
	if (k == 1) return puts("3"), 0;
	sieve();
	for (int i = 3; i <= n; i++)
		if (!mark[i] || i == 4) pq.push((node) {i});
	while (k--)
	{
		node it = pq.top(); pq.pop();
		int x = it.x; ans += phi[x];
		for (int i = x; i <= n; i += x)
			if ((++cnt[i]) == d[i] - 1) pq.push((node) {i});
	}
	return std::cout << ans + 2 << std::endl, 0;
}