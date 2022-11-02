#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 401111;
int lowbit(int x)
{
	return x & (-x);
}

struct BIT
{
	set <pair <int, int> > b[N];
	void insert(int pos, pair <int, int> p)
	{
		pos += 2;
		for(int i = pos; i < N; i += lowbit(i))
			b[i].insert(p);
	}
	vector <int> query(int pos, int limit)
	{
		pos += 2;
		vector <int> ans;
		for(int i = pos; i > 0; i -= lowbit(i))
		{
			while(b[i].size() && (b[i].begin() -> first) <= limit)
			{
				ans.push_back(b[i].begin() -> second);
				b[i].erase(b[i].begin());
			}
		}
		return ans;
	}
}bit;

int a[N][4];
int from[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	map <int, int> disc;
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < 4; j ++)
		{
			cin >> a[i][j];
			disc[a[i][j]] = 0;
		}
	disc[0] = 0;
	int disc_cnt = 0;
	for(auto it = disc.begin(); it != disc.end(); it ++)
		disc[it -> first] = disc_cnt ++;
	for(int i = 0; i < n; i ++)
	{
		for(int j = 0; j < 4; j ++)
			a[i][j] = disc[a[i][j]];
		bit.insert(a[i][0], make_pair(a[i][1], i));
	}

	queue <int> que;
	que.push(n);
	memset(from, -1, sizeof(from));
	from[n] = n;
	a[n][0] = a[n][1] = a[n][2] = a[n][3] = 0;
	while(!que.empty())
	{
		int cur = que.front();
		que.pop();
		vector <int> vec = bit.query(a[cur][2], a[cur][3]);
		for(auto &x : vec)
			if(from[x] == -1)
			{
				from[x] = cur;
				que.push(x);
			}
	}
	if(from[n - 1] == -1)
		cout << -1 << '\n';
	else
	{
		vector <int> ans;
		for(int cur = n - 1; cur != n; cur = from[cur])
			ans.push_back(cur);
		reverse(ans.begin(), ans.end());
		cout << ans.size() << '\n';
		for(auto &x : ans)
			cout << x + 1 << ' ';
		cout << '\n';
	}
	return 0;
}