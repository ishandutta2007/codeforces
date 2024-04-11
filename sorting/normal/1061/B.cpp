#include<bits/stdc++.h>

using namespace std;

const long long N = 1e5 + 7;

long long a[N];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, m, mx = 0, sum = 0, res = 0;

	cin >> n >> m;

	for(long long i = 1; i <= n; i++)
	{
		cin >> a[i];
		//mx = max(a[i], mx);
		sum += a[i];
	}

	sort(a+1, a+n+1);

	int curr = 1;

	for(int i = 1; i <= n; i++)
	{
		if(a[i] >= curr)
		{
			res++;
			curr++;
		}
		else
			res++;
	}

	if(curr <= a[n])
		res += a[n]-curr+1;

	cout << sum - res << endl;

	return 0;
}