#include <iostream>
#include <algorithm>
using namespace std;

const int N = 3;

int a[N][2];
bool vis[N];

const int M = 311;
char ans[M][M];

int main()
{
	ios :: sync_with_stdio(false);
	int area = 0;
	for(int i = 0; i < 3; i ++)
	{
		for(int j = 0; j < 2; j ++)
			cin >> a[i][j];
		area += a[i][0] * a[i][1];
	}

	int side_length = -1;
	for(int i = 1; i <= 300; i ++)
		if(i * i == area)
		{
			side_length = i;
			break;
		}

	if(side_length == -1)
		cout << -1 << '\n';
	else
	{
		int cnt = 0;
		for(int i = 0; i < 3; i ++)
			if(a[i][0] != side_length && a[i][1] != side_length)
				cnt ++;

		if(cnt == 0)
		{
			int last = 0;
			for(int i = 0; i < 3; i ++)
			{
				int tmp = a[i][0];
				if(tmp == side_length)
					tmp = a[i][1];

				for(int j = last; j < last + tmp; j ++)
					for(int k = 0; k < side_length; k ++)
						ans[j][k] = (char)('A' + i);

				last = last + tmp;
			}
		}
		else if(cnt == 2)
		{
			//cout << "!\n";
			int last = 0;
			for(int i = 0; i < 3; i ++)
			{
				int tmp = a[i][0];
				if(tmp != side_length)
					tmp = a[i][1];
				if(tmp != side_length)
					continue;

				//cout << i << ' ' << tmp << '\n';
				for(int j = 0; j < (a[i][0] + a[i][1] - tmp); j ++)
					for(int k = 0; k < side_length; k ++)
						ans[j][k] = (char)('A' + i);
				last = (a[i][0] + a[i][1] - tmp);
				vis[i] = true;
			}
			//cout << last << '\n';

			int cc = 0;
			int ll = 0;
			for(int i = 0; i < 3; i ++)
			{
				if(vis[i])
					continue;
				int tmp = a[i][0];
				if(tmp != side_length - last)
					tmp = a[i][1];
				if(tmp != side_length - last)
				{
					cout << -1 << '\n';
					return 0;
				}

				for(int j = last; j < side_length; j ++)
					for(int k = ll; k < ll + a[i][0] + a[i][1] - tmp; k ++)
						ans[j][k] = (char)('A' + i);

				ll = ll + (a[i][0] + a[i][1] - tmp);
			}
		}
		else
		{
			cout << -1 << '\n';
			return 0;
		}

		cout << side_length << '\n';
		for(int i = 0; i < side_length; i ++)
		{
			for(int j = 0; j < side_length; j ++)
				cout << ans[i][j];
			cout << '\n';
		}
	}

	return 0;
}