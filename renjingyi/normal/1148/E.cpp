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
typedef pair<pp, int> ppp;
const int maxn = 3e5 + 5;
pp s[maxn], t[maxn];
int go[maxn];
priority_queue<pp, vector<pp>, greater<pp> > qq;
set<pp> ss;
vector<ppp> ans;
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> s[i].first;
		s[i].second = i;
	}
	for(int i = 1; i <= n; i ++)
	{
		cin >> t[i].first;
		t[i].second = i;
	}
	sort(s + 1, s + n + 1);
	sort(t + 1, t + n + 1);
	for(int i = 1; i <= n; i ++)
		go[s[i].second] = t[i].first - s[i].first;
	for(int i = 1; i <= n; i ++)
	{
		int now = s[i].second;
		if(go[now] > 0)
			qq.push(s[i]);
		else if(go[now] < 0)
		{
			ss.insert(s[i]);
			go[now] = -go[now];
		}
	}
	while(!qq.empty())
	{
		pp now = qq.top();
		qq.pop();
		set<pp>::iterator it = ss.upper_bound(now);
		if(it == ss.end())
		{
			cout << "NO" << endl;
			return 0;
		}
		int pos1 = now.first, pos2 = it->first;
		int id1 = now.second, id2 = it->second;
		ss.erase(it);
		if(go[id1] == go[id2])
			ans.push_back(mp(mp(id1, id2), go[id1]));
		else if(go[id1] < go[id2])
		{
			ans.push_back(mp(mp(id1, id2), go[id1]));
			go[id2] -= go[id1];
			ss.insert(mp(pos2 - go[id1], id2));
		}
		else
		{
			ans.push_back(mp(mp(id1, id2), go[id2]));
			go[id1] -= go[id2];
			qq.push(mp(pos1 + go[id2], id1));
		}
	}
	if(ss.size())
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i ++)
		cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second << endl;
	
	return 0;
}