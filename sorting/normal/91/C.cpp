#include <bits/stdc++.h>

const long long N = 1e5 + 7;
const long long mod = 1e9 + 9;

long long parent[N], parent_size[N];
long long res;

long long fast_pow(long long base, long long exp)
{
	if(exp == 0ll)
		return 1ll;

	long long ret = 1ll;

	if(exp & 1)
		ret = base;

	long long tmp = fast_pow(base, exp >> 1ll);

	ret *= tmp;
	ret %= mod;

	ret *= tmp;
	ret %= mod;

	return ret;
}

long long find_parent(long long x)
{
	if(parent[x] == x)
		return x;

	parent[x] = find_parent(parent[x]);

	return parent[x];
}

void unite(long long v1, long long v2)
{
	if(find_parent(v1) == find_parent(v2))
	{
		res++;

		return ;
	}

	if(parent_size[ parent[v1] ] < parent_size[ parent[v2] ])
		std::swap(v1, v2);

	parent_size[ parent[v1] ] += parent_size[ parent[v2] ];

	parent[ parent[v2] ] = parent[v1];

	return ;
}

int main ()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	long long n, m;

	std::cin >> n >> m;

	for(long long i = 1; i <= n; i++)
	{
		parent[i] = i;
		parent_size[i] = 1ll;
	}

	for(long long i = 0; i < m; i++)
	{
		long long u, v;

		std::cin >> u >> v;

		unite(u, v);

		std::cout << fast_pow(2ll, res) - 1ll << "\n";
	}

	return 0;
}