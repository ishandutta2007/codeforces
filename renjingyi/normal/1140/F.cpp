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
namespace Input
{
	const int BUF = 1048576;
	char buf[BUF + 1];
	char *head = buf, *tail = buf;
	char inputchar()
	{
		if(head == tail)
			*(tail = (head = buf) + fread(buf, 1, BUF, stdin)) = 0;
		return *head ++;
	}
	void inputnum(int &ret)
	{
		char ch = inputchar();
		while(ch < '0' || ch > '9')
			ch = inputchar();
		ret = ch - '0';
		ch = inputchar();
		while(ch >= '0' && ch <= '9')
		{
			ret = ret * 10 + ch - '0';
			ch = inputchar();
		}
	}
}
typedef pair<int, int> pp;
const int maxn = 6e5 + 5;
const int limit = 300000;
int par[maxn];
long long t[maxn][2];
int getp(const int &x)
{
	return par[x] == x ? x : getp(par[x]);
}
int sum, h[maxn << 2];
vector<pp> pre[maxn << 2];
void init(const int &l, const int &r, const pp &e)
{
	for(int s = l + sum - 1, t = r + sum + 1; s ^ t ^ 1; s >>= 1, t >>= 1)
	{
		if(~s & 1)
			pre[s ^ 1].push_back(e);
		if(t & 1)
			pre[t ^ 1].push_back(e);
	}
}
map<pp, int> tmp;
int q;
long long ans = 0;
void work(const int &p)
{
	for(int i = 0; i < pre[p].size(); i ++)
	{
		int x = getp(pre[p][i].first), y = getp(pre[p][i].second);
		if(x == y)
		{
			pre[p][i] = mp(0, 0);
			continue;
		}
		if(t[x][0] + t[x][1] > t[y][0] + t[y][1])
			swap(x, y);
		pre[p][i] = mp(x, y);
		ans -= t[x][0] * t[x][1] + t[y][0] * t[y][1];
		par[x] = y;
		t[y][0] += t[x][0];
		t[y][1] += t[x][1];
		ans += t[y][0] * t[y][1];
	}
	if(p >= sum + 1 && p <= sum + q)
		cout << ans << " ";
	else if(p >= sum)
		return;
	else
	{
		work(p << 1);
		work(p << 1 | 1);
	}
	for(int i = (int)pre[p].size() - 1; i >= 0; i --)
	{
		int x = pre[p][i].first, y = pre[p][i].second;
		if(x == y)
			continue;
		ans -= t[y][0] * t[y][1];
		t[y][0] -= t[x][0];
		t[y][1] -= t[x][1];
		par[x] = x;
		ans += t[x][0] * t[x][1];
		ans += t[y][0] * t[y][1];
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	Input::inputnum(q);
	for(sum = 1; sum < q + 2; sum <<= 1);
	for(int i = 1; i <= q; i ++)
	{
		pp e;
		Input::inputnum(e.first);
		Input::inputnum(e.second);
		e.second += limit;
		int last = tmp[e];
		if(last == 0)
			tmp[e] = i;
		else
		{
			init(last, i - 1, e);
			tmp[e] = 0;
		}
	}
	for(map<pp, int>::iterator it = tmp.begin(); it != tmp.end(); it ++)
		if(it->second)
			init(it->second, q, it->first);
	for(int i = 1; i <= 2 * limit; i ++)
		par[i] = i;
	for(int i = 1; i <= limit; i ++)
		t[i][0] = 1;
	for(int i = limit + 1; i <= 2 * limit; i ++)
		t[i][1] = 1;
	work(1);
	cout << endl << endl;
	
	return 0;
}