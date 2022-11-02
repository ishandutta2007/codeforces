#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 211111;

int a[N];

int gcd(int a, int b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

int legal[N];
long long sum[N];
bool vis[N * 2];
long long work(int n, int block)
{
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < block; i ++)
	{
		vector <int> vec;
		int tmp_max = 0;
		for(int j = 0; j < n / block; j ++)
			if(tmp_max < a[i + j * block])
				tmp_max = a[i + j * block];

		for(int j = 0; j < n / block; j ++)
			if(tmp_max == a[i + j * block])
				vis[i + j * block] = true;
	}
	for(int i = 0; i < n; i ++)
		vis[i + n] = vis[i];

	int start = 0;
	for(int i = 1; i < n; i ++)
		if(vis[i] && !vis[i - 1])
			start = i;

	memset(legal, 0, sizeof(legal));
	//memset(sum, 0, sizeof(sum));
	for(int i = 1; i < N; i ++)
	{
		//sum[i] = sum[i - 1];
		legal[i] = legal[i - 1];
		if(i % block == 0 && gcd(n, i) == block)
			legal[i] ++;
		//sum[i] += legal[i];
	}

	/*
	cout << n << ' ' << block << '\n';
	for(int i = 0; i < n; i ++)
		cout << vis[i];
	cout << '\n';
	*/
	int tmp = 0;
	long long ans = 0;
	for(int i = start; i < start + n; i ++)
		if(vis[i])
		{
			tmp ++;
			ans += legal[tmp];
		}
		else
			tmp = 0;

	
	if(tmp == n)
	{
		ans = (long long)n * legal[n];
	}
	
	//cout << ans << '\n';
	return ans;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	long long ans = 0;
	for(int i = 1; i < n; i ++)
		if(n % i == 0)
			ans += work(n, i);

	cout << ans << '\n';
	return 0;
}