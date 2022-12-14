#include<iostream>
using namespace std;
int main()
{
	int a[100000];
	int n;
	cin >> n;
	int mn = 1000000000;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] < mn)
			mn = a[i];
	}
	int last = -1;
	int ans = 10000000;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == mn)
		{
			if (last != -1)
			{
				int dif = i - last;
				if (dif < ans)
					ans = dif;
			}
			last = i;
		}
	}
	cout << ans << endl;
}