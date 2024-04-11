#include <iostream>
#include <cstring>
using namespace std;

const int N = 512;
int sg[N];
bool vis[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	int ans = 0;
	if(k & 1)
	{
		sg[0] = 0;
		for(int i = 1; i <= 256; i ++)
		{
			memset(vis, 0, sizeof(vis));
			vis[sg[i - 1]] = true;
			if(!(i & 1))
				vis[sg[i / 2]] = true;
			for(int j = 0; ; j ++)
				if(!vis[j])
				{
					sg[i] = j;
					break;
				}
			/*
			if(sg[i] == 2)
				cout << i / 4 << '\n';
			*/
			//cout << i << ' ' << sg[i] << '\n';
		}
		for(int i = 0; i < n; i ++)
		{
			int x;
			cin >> x;
			if(x > 128)
				x -= (x - 128) / 32 * 32;
			ans ^= sg[x];
		}
	}
	else
	{
		for(int i = 0; i < n; i ++)
		{
			int x;
			cin >> x;
			if(x == 1)
				ans ^= 1;
			else if(x == 2)
				ans ^= 2;
			else if(x > 2 && !(x & 1))
				ans ^= 1;

		}
	}
	if(ans)
		cout << "Kevin\n";
	else
		cout << "Nicky\n";
	return 0;
}