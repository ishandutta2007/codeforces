#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <complex>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const int maxn = 1e5 + 5;
int gcd(const int &a, const int &b)
{
	if(!b)
		return a;
	return gcd(b, a % b);
}
vector<int> prime;
bool mark[maxn];
int mu[maxn];
int g[1005][1005];
int main()
{
	std::ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	if(m < n - 1)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	for(int i = 2; i <= n; i ++)
	{
		if(!mark[i])
		{
			prime.push_back(i);
			mu[i] = i - 1;
		}
		for(int j = 0; j < prime.size() && i * prime[j] <= n; j ++)
		{
			mark[i * prime[j]] = 1;
			mu[i * prime[j]] = i % prime[j] ? mu[i] * mu[prime[j]] : mu[i] * prime[j];
			if(!(i % prime[j]))
				break;
		}
	}
	long long sum = 0;
	for(int i = 1; i <= n; i ++)
		sum += mu[i];
	if(sum < m)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	cout << "Possible" << endl;
	for(int i = 2; i <= n; i ++)
		cout << 1 << " " << i << endl;
	sum = m - n + 1;
	for(int i = 1; i <= 1000; i ++)
		for(int j = 1; j <= 1000; j ++)
			g[i][j] = gcd(i, j);
	if(sum)
		for(int i = 2; i <= n; i ++)
			for(int j = 2; j < i; j ++)
				if(g[i][j] == 1)
				{
					cout << j << " " << i << endl;
					if(!-- sum)
						return 0;
				}
		
	return 0;
}