#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <complex>
#include <queue>
#include <stack>
#include <sstream>
#define mp(a, b) make_pair(a, b)
using namespace std;
typedef pair<int, int> pp;
const int maxn = 5e5 + 5;
vector<int> son1[maxn], son2[maxn];
int d[maxn], t[maxn];
bool mark[maxn];
int dfs(int p)
{
	d[p] = 1;
	t[p] = 1;
	mark[p] = 1;
	for(int i = 0; i < son1[p].size(); i ++)
	{
		int to = son1[p][i];
		if(!mark[to])
		{
			son2[p].push_back(to);
			dfs(to);
			d[p] = max(d[p], d[to] + 1);
			t[p] += t[to];
		}
	}
}
void getans1(int l, int p)
{
	cout << p << " ";
	if(l == 0)
		return;
	for(int i = 0; i < son2[p].size(); i ++)
	{
		int to = son2[p][i];
		if(d[to] >= l)
		{
			getans1(l - 1, to);
			break;
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T --)
	{
		int n, m;
		cin >> n >> m;
		int nnn = n + 1 >> 1;
		for(int i = 1; i <= n; i ++)
			son1[i].clear();
		for(int i = 1; i <= m; i ++)
		{
			int u, v;
			cin >> u >> v;
			son1[u].push_back(v);
			son1[v].push_back(u);
		}
		for(int i = 1; i <= n; i ++)
			mark[i] = 0;
		for(int i = 1; i <= n; i ++)
			son2[i].clear();
		priority_queue<pp> q;
		int mx = 0, mxp = 0;
		for(int i = 1; i <= n; i ++)
			if(!mark[i])
			{
				dfs(i);
				q.push(mp(t[i], i));
				if(d[i] > mx)
				{
					mx = d[i];
					mxp = i;
				}
			}
		if(mx >= nnn)
		{
			cout << "PATH" << endl;
			cout << nnn << endl;
			getans1(nnn - 1, mxp);
			cout << endl;
			continue;
		}
		cout << "PAIRING" << endl;
		cout << (nnn + 1 >> 1) << endl;
		int cnt = 0;
		while(!q.empty())
		{
			pp now1 = q.top();
			q.pop();
			int t1 = now1.first, p1 = now1.second;
			if(!q.empty())
			{
				pp now2 = q.top();
				q.pop();
				int t2 = now2.first, p2 = now2.second;
				cout << p1 << " " << p2 << endl;
				cnt ++;
				if(cnt * 2 >= nnn)
					break;
				for(int i = 0; i < son2[p2].size(); i ++)
				{
					int to = son2[p2][i];
					q.push(mp(t[to], to));
				}
			}
			for(int i = 0; i < son2[p1].size(); i ++)
			{
				int to = son2[p1][i];
				q.push(mp(t[to], to));
			}
		}
		if(cnt * 2 < nnn)
		{
			cout << "boom" << endl;
			break;
		}
	}
	
	return 0;
}