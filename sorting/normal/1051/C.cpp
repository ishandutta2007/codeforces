#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;

const int N = 107;

int arr[N], cnt[N], cnt2[N];
bool res[N];

int main ()
{
	int n;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
		cnt[arr[i]]++;
		cnt2[arr[i]]++;
	}

	int force = 0, choice = 0;

	for(int i = 1; i <= 100; i++)
		if(cnt[i])
		{
			if(cnt[i] == 1)
				force++;
			else
				if(cnt[i] != 2)
					choice++;
		}

	if(force % 2 == 1 && !choice)
	{
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";

	int a = 0, b = 0;

	for(int i = 0; i < n; i++)
		if(cnt[arr[i]] == 1)
		{
			if(a<=b)
			{
				a++;
				res[i] = 0;
			}
			else
			{
				b++;
				res[i] = 1;
			}
		}
		else
		{
			res[i] = 0;
		}

	if(a > b)
	{
		for(int i = 0; i < n; i++)
			if(cnt[arr[i]] > 2)
			{
				res[i] = 1;
				b++;
				break;
			}
	}

	for(int i = 0; i < n; i++)
		if(res[i])
			cout << "B";
		else
			cout << "A";
	cout << "\n";

	return 0;
}