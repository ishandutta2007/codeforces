#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 101111;
pair <pair <int, int>, int> edges[N];
pair <int, int> a[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i ++)
	{
		cin >> edges[i].first.first >> edges[i].first.second;
		edges[i].first.second = 1 - edges[i].first.second;
		edges[i].second = i;
	}
	sort(edges, edges + m);
	vector <pair <int, int> > use;
	for(int i = 3; i < 500; i ++)
		for(int j = 1; j + 2 <= i; j ++)
			use.push_back(make_pair(j, i));
	int uid = 0;
	int cnt = 1;
	vector <pair <pair <int, int>, int> > ans;
	for(int i = 0; i < m; i ++)
		if(edges[i].first.second == 0)
		{
			ans.push_back(make_pair(make_pair(cnt, cnt + 1), edges[i].second));
			cnt ++;
		}
		else
		{
			if(use[uid].second > cnt)
			{
				cout << -1 << '\n';
				return 0;
			}
			ans.push_back(make_pair(use[uid], edges[i].second));
			uid ++;
		}
	for(auto &b : ans)
		a[b.second] = b.first;
	for(int i = 0; i < m; i ++)
		cout << a[i].first << ' ' << a[i].second << '\n';
	return 0;
}