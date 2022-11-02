#include <iostream>
#include <cmath>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <string>

using namespace std;
#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)
struct vec 
{
	bool A;
	bool B;
	bool C;
	vec()
	{
		A = false;
		B = false;
		C = false;
	}
};

signed main()
{
	FAST;
	int n;
	cin >> n;
	vector<pair <int, vec> > a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first;
		a[i].second = vec();
		string s;
		cin >> s;
		for (auto j : s)
		{
			if (j == 'A')
			{
				a[i].second.A = true;
			}
			if (j == 'B')
			{
				a[i].second.B = true;
			}
			if (j == 'C')
			{
				a[i].second.C = true;
			}
		}
	}
	long long min = 1e14;

	for (int i = 0; i < n; i++)
	{
		if (a[i].second.A && a[i].second.B && a[i].second.C)
		{
			if (min > a[i].first)
			{
				min = a[i].first;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if ((a[i].second.A || a[j].second.A) && (a[i].second.B || a[j].second.B) && (a[i].second.C || a[j].second.C))
			{
				if (min > (a[i].first + a[j].first))
				{
					min = a[i].first +  a[j].first;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				if ((a[i].second.A || a[j].second.A || a[k].second.A) && (a[i].second.B || a[j].second.B || a[k].second.B) && (a[i].second.C || a[j].second.C || a[k].second.C))
				{
					if (min > (a[i].first + a[j].first + a[k].first))
					{
						min = a[i].first + a[j].first + a[k].first;
					}
				}
			}
		}
	}
	if (min == 1e14)
	{
		cout << -1;
	}
	else
	{
		cout << min;
	}
	return 0;
}