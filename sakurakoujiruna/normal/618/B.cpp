#include <iostream>
using namespace std;

const int N = 53;

int a[N][N];
int ans[N];
bool vis[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			cin >> a[i][j];

	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
		if(!vis[j])
		{
			int cnt = 0;
			for(int k = 1; k <= n; k ++)
				if(a[j][k] == i)
					cnt ++;
			if(cnt == n - i)
			{
				ans[j] = i;
				vis[j] = true;
				//cout << j << ' ' << i << '\n';
				for(int k = 1; k <= n; k ++)
					a[k][j] = a[j][k] = -1;
				break;
			}
		}

	for(int i = 1; i <= n; i ++)
		cout << ans[i] << ' ';

	cout << '\n';
}