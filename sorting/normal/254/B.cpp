#include<bits/stdc++.h>

using namespace std;

const int N = 107;

struct olymp
{
	int m, d, p, t;
};

olymp ol[N];

bool cmp(olymp val1, olymp val2)
{
	return val1.d < val2.d;
}

int arr[1007];

int main ()
{
	int n;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> ol[i].m >> ol[i].d >> ol[i].p >> ol[i].t;

	for(int i = 0; i < n; i++)
	{
		for(int j = ol[i].m - 1; j >= 1; j--)
		{
			if(j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 10 || j == 12)
				ol[i].d += 31;
			else
			{
				if(j == 2)
					ol[i].d += 28;
				else
					ol[i].d += 30; 
			}
		}
	}

	sort(ol, ol+n, cmp);

	for(int i = 0; i < n; i++)
		for(int j = 1; j <= ol[i].t; j++)
			arr[ ol[n-1].d - ol[i].d + j ] += ol[i].p;

	int res = 0;

	for(int i = 0; i < 1000; i++)
		res = max(arr[i], res);

	cout << res << "\n";

	return 0;
}