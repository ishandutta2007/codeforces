#include <iostream>
using namespace std;

const int N = 121111;

int a[N];
int ans[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	ans[n - 1] = 0;
	int last_max = a[n - 1];
	for(int i = n - 2; i >= 0; i --)
	{
		int tmp = last_max + 1;
		if(a[i] > tmp)
			ans[i] = 0;
		else
			ans[i] = tmp - a[i];

		last_max = max(last_max, a[i]);
	}

	for(int i = 0; i < n; i ++)
		cout << ans[i] << ' ';
	cout << '\n';

	return 0;
}