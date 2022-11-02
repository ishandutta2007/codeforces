#include <iostream>
using namespace std;

const int N = 1211;

int a[N];
bool vis[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];

	int ans = 0;
	int cnt = 0;
	int collect = 0;
	for(int t = 0; t <= n; t ++)
	{
		int dir;
		int start;
		if(t & 1)
		{
			dir = -1;
			start = n;
		}
		else
		{
			dir = 1;
			start = 1;
		}

		int change = 0;
		for(int i = 0; i < n; i ++)
		{
			int tmp = start + i * dir;
			if(!vis[tmp] && collect >= a[tmp])
			{
				vis[tmp] = true;
				collect ++;
				change ++;
			}
		}

		if(!change)
		{
			cout << t - 1 << '\n';
			break;
		}
	}
	return 0;
}