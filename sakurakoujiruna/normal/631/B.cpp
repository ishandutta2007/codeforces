#include <iostream>
using namespace std;

const int N = 5011;

int pr[N], nr[N];
int pc[N], nc[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= k; i ++)
	{
		int t, x, a;
		cin >> t >> x >> a;
		if(t == 1)
		{
			pr[x] = a;
			nr[x] = i;
		}
		else
		{
			pc[x] = a;
			nc[x] = i;
		}
	}
	
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= m; j ++)
			if(nr[i] > nc[j])
				cout << pr[i] << ' ';
			else
				cout << pc[j] << ' ';
		cout << '\n';
	}
	return 0;
}