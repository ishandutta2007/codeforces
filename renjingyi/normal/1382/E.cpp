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
const int maxn = 1e5 + 5;
int b[maxn], cnt[maxn], pos[maxn];
vector<int> ans[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t --)
	{
		int n, x, y;
		cin >> n >> x >> y;
		for(int i = 1; i <= n + 1; i ++)
			cnt[i] = 0;
		for(int i = 1; i <= n; i ++)
		{
			cin >> b[i];
			cnt[b[i]] ++;
		}
		int s = 0;
		for(int i = 1; i <= n + 1; i ++)
			if(!cnt[i])
			{
				s = i;
				break;
			}
		priority_queue<pp> q1, q2;
		for(int i = 1; i <= n + 1; i ++)
			if(cnt[i])
				q1.push(mp(cnt[i], i));
		for(int i = 1; i <= n + 1; i ++)
			ans[i].clear();
		for(int i = 1; i <= x; i ++)
		{
			pp now = q1.top();
			q1.pop();
			int t = now.first, p = now.second;
			ans[p].push_back(p);
			if(t > 1)
				q1.push(mp(t - 1, p));
			cnt[p] --;
		}
		for(int i = 1; i <= n + 1; i ++)
			if(cnt[i])
				q2.push(mp(cnt[i], -i));
		bool boom = 0;
		int last = n - y;
		for(int i = 1; i <= y - x; i ++)
		{
			pp now = q1.top();
			q1.pop();
			int t = now.first, p = now.second;
			pp now2 = q2.top();
			q2.pop();
			int t2 = now2.first, p2 = -now2.second;
			if(p2 == p)
			{
				if(q2.empty())
				{
					if(last)
					{
						ans[p].push_back(s);
						if(t > 1)
							q1.push(mp(t - 1, p));
						q2.push(now2);
						last --;
						i --;
						continue;
					}
					else
					{
						boom = 1;
						break;
					}
				}
				pp now3 = q2.top();
				q2.pop();
				int t3 = now3.first, p3 = -now3.second;
				ans[p].push_back(p3);
				if(t > 1)
					q1.push(mp(t - 1, p));
				q2.push(now2);
				if(t3 > 1)
					q2.push(mp(t3 - 1, -p3));
			}
			else
			{
				ans[p].push_back(p2);
				if(t > 1)
					q1.push(mp(t - 1, p));
				if(t2 > 1)
					q2.push(mp(t2 - 1, -p2));
			}
		}
		if(boom)
			cout << "NO" << endl;
		else
		{
			while(!q1.empty())
			{
				pp now = q1.top();
				q1.pop();
				int t = now.first, p = now.second;
				for(int i = 1; i <= t; i ++)
					ans[p].push_back(s);
			}
			cout << "YES" << endl;
			for(int i = 1; i <= n + 1; i ++)
				pos[i] = 0;
			for(int i = 1; i <= n; i ++)
				cout << ans[b[i]][pos[b[i]] ++] << " ";
			cout << endl;
		}
	}
	
	return 0;
}