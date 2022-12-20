#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

pair<int, int> s[N];
int a[N], b[N];
int a2[N], b2[N];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> s[i].first;
		s[i].second = i;
	}

	sort(s, s+n);

	int i, one = 0, two = 0;

	if(n % 3 == 1)
	{
		one = 1;
		two = 1;
	}
	else
	{
		if(n % 3 == 2)
		{
			one = 1;
			two = 2;
		}
	}

	for(i = 0; i < n/3 + one; i++)
	{
		a[i] = i;
		b[i] = s[i].first - i;
	}

	for(; i < 2*(n/3) + two; i++)
	{
		b[i] = i;
		a[i] = s[i].first - i;
	}

	for(; i < n; i++)
	{
		b[i] = n - i - 1;
		a[i] = s[i].first - b[i];
	}

	for(int i = 0; i < n; i++)
	{
		a2[s[i].second] = a[i];
		b2[s[i].second] = b[i];
	}

	cout << "YES\n";

	for(int i = 0; i < n; i++)
		cout << a2[i] << " ";
	cout << "\n";

	for(int i = 0; i < n; i++)
		cout << b2[i] << " ";
	cout << "\n";

	return 0;
}