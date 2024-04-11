#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> pcounts;
	for(int i = 0; i < n; i++)
	{
		long long a;
		cin >> a;
		pcounts.push_back(__builtin_popcountll(a));
	}
	vector<int> sums;
	int sum = 0;
	sums.push_back(sum);
	for(int i = 0; i < n; i++)
	{
		sum += pcounts[i];
		sums.push_back(sum);
	}
	long long ans = 0, nOdds = 0, nEvens = 0;
	for(int i = 0; i < sums.size(); i++)
	{
		if(sums[i] % 2) nOdds++;
		else nEvens++;
	}
	ans += (nOdds)*(nOdds - 1)/2ll;
	ans += (nEvens)*(nEvens - 1)/2ll;
	for(int i = 0; i < sums.size() - 1; i++)
	{
		if((sums[i] - sums[i + 1])%2 == 0) ans--;
	}
	//cout << ans << endl;
	int mx = 0;
	for(int i = 0; i < n; i++)
	{
		mx = pcounts[i];
		sum = pcounts[i];
		for(int j = i + 1; j < min(i + 130, n); j++)
		{
			mx = max(mx, pcounts[j]);
			sum += pcounts[j];
			//cout << "i: " << i << " j: " << j << " mx: " << mx << " sum: " << sum << endl;
			if(sum % 2 == 0 && sum < 2*mx) ans--;
		}
	}
	cout << ans << endl;
}