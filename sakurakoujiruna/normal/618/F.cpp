#include <iostream>
#include <cstring>
using namespace std;

const int N = 1000011;
typedef long long intl;

intl a[N];
intl b[N];

int last_a[N];
int last_b[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		a[i] += a[i - 1];
	}
	for(int i = 1; i <= n; i ++)
	{
		cin >> b[i];
		b[i] += b[i - 1];
	}
	bool reverse = false;
	if(a[n] < b[n])
	{
		reverse = true;
		for(int i = 1; i <= n; i ++)
			swap(a[i], b[i]);
	}

	memset(last_a, -1, sizeof(last_a));
	int p = 0;
	for(int i = 0; i <= n; i ++)
	{
		while(p != n && b[p + 1] <= a[i])
			p ++;
		int delta = a[i] - b[p];
		if(last_a[delta] == -1)
		{
			last_a[delta] = i;
			last_b[delta] = p;
		}
		else
		{
			if(!reverse)
			{
				cout << i - last_a[delta] << '\n';
				for(int j = last_a[delta] + 1; j <= i; j ++)
					cout << j << ' ';
				cout << '\n';
			}
			cout << p - last_b[delta] << '\n';
			for(int j = last_b[delta] + 1; j <= p; j ++)
				cout << j << ' ';
			cout << '\n';
			if(reverse)
			{
				cout << i - last_a[delta] << '\n';
				for(int j = last_a[delta] + 1; j <= i; j ++)
					cout << j << ' ';
				cout << '\n';
			}
			return 0;
		}
	}

	return 0;
}