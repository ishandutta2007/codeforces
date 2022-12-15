#include<bits/stdc++.h>

using namespace std;

map<long long, vector<long long> > Div;

long long Left = 100000;

void dfs(long long n, long long k)
{
	if(n == 1)
	{
		cout << "1 ";
		Left--;

		if(Left == 0)
			exit(0);

		return;
	}

	if(k == 0)
	{
		cout << n << " ";
		Left--;

		if(Left == 0)
			exit(0);

		return;
	}

	for(auto i: Div[n])
		dfs(i, k-1);

	return;
}

int main ()
{
	long long n, k;

	cin >> n >> k;

	for(long long i = 1; i*i <= n; i++)
		if(n % i == 0)
		{
			Div[n].push_back(i);

			if(i*i !=n)
				Div[n].push_back(n/i);
		}

	sort(Div[n].begin(), Div[n].end());

	for(auto i: Div[n])
		for(auto j: Div[n])
			if(i % j == 0)
				if(i != n)
					Div[i].push_back(j);

	dfs(n, k);

	return 0;
}