#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200011;
const int K = 20;
typedef long long intl;

int rmin[N][K];
int rmq(int l, int r)
{
	int log2 = 31 - __builtin_clz(r - l);
	return min(rmin[l][log2], rmin[r - (1 << log2)][log2]);
}

pair <int, int> station[N];
#define pos first
#define cost second

int main()
{
	ios :: sync_with_stdio(false);
	int d, n, m;
	cin >> d >> n >> m;
	for(int i = 0; i < m; i ++)
		cin >> station[i].pos >> station[i].cost;
	station[m ++] = make_pair(d, 0);

	sort(station, station + m);
	for(int i = 0; i < m; i ++)
		rmin[i][0] = station[i].cost;

	for(int j = 1; j < K; j ++)
		for(int i = 0; i < m; i ++)
			if(i + (1 << j) < N)
				rmin[i][j] = min(rmin[i][j - 1], rmin[i + (1 << (j - 1))][j - 1]);

	int now = n;
	if(station[0].pos > n)
	{
		cout << -1 << '\n';
		return 0;
	}
	now -= station[0].pos;
	int p = 0;
	intl ans = 0;
	
	while(p != m - 1)
	{
		int left = p + 1;
		int right = m;
		while(left + 1 < right)
		{
			int mid = (left + right) / 2;
			if(rmq(p + 1, mid - 1 + 1) < station[p].cost)
				right = mid;
			else
				left = mid;
		}

		int dis = station[left].pos - station[p].pos;
		if(now >= dis)
		{
			p = left;
			now -= dis;
		}
		else if(n >= dis)
		{
			ans += (intl)(dis - now) * station[p].cost;
			now = 0;
			p = left;
		}
		else
		{
			ans += (intl)(n - now) * station[p].cost;
			now = n;
			if(station[p + 1].pos - station[p].pos > n)
			{
				cout << -1 << '\n';
				return 0;
			}
			now -= station[p + 1].pos - station[p].pos;
			p ++;
		}
	}
	cout << ans << '\n';
	return 0;
}