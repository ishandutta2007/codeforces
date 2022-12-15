#include<bits/stdc++.h>

using namespace std;

const long long N = 2e5 + 7;

long long a[N], n;
long long prefix[N], suffix[N];

long long binary_search(long long ind, long long val)
{
	long long l = ind, r = n, mid;

	while(l != r)
	{
		mid = (l+r+1) / 2;

		if(suffix[mid] >= val)
			l = mid;
		else
			r = mid - 1;
	}

	return l;
}

int main ()
{
	string s, tmp = "aeiouAEIOU";

	cin >> s;

	n = s.size();

	for(long long i = 0; i < n; i++)
	{
		if(tmp.find(s[i]) < tmp.size())
			a[i+1] = -1;
		else
			a[i+1] = 2;

		//cout << a[i+1] << endl;
	}

	for(long long i = 1; i <= n; i++)
		prefix[i] = prefix[i-1] + a[i];

	suffix[n] = prefix[n];
	for(long long i = n-1; i >= 1; i--)
		suffix[i] = max(prefix[i], suffix[i+1]);

	pair<long long, long long> res;

	for(long long i = 0; i <= n; i++)
	{
		int ind = binary_search(i, prefix[i]);

		if(ind == i)
			continue;
		
		//cout << ind << " " << i << endl;

		if(res.first == ind - i)
			res.second++;
		else
			res = max(res, {ind-i, 1ll});
	} 

	if(!res.first)
	{
		cout << "No solution\n";

		return 0;
	}

	cout << res.first << " " << res.second << "\n";

	return 0;
}