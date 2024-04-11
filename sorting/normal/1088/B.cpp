#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

int a[N];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;

	cin >> n >> k;

	for(int i = 1; i <= n; i++)
		cin >> a[i];

	sort(a+1, a+n+1);

	for(int i = 1; i <= n && k; i++)
	{
		if(a[i] != a[i-1])
		{
			cout << a[i]-a[i-1] << "\n";

			k--;
		}
	}

	while(k)
	{
		cout << "0\n";
		k--;
	}

	return 0;
}