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
using namespace std;
const int maxn = 2e5 + 5;
namespace BIT
{
	#define lowbit(x) (x) & (-x)
	int s[maxn];
	int n;
	void add(const int &p, const int &x)
	{
		for(int i = p; i <= n; i += lowbit(i))
			s[i] += x;
	}
	int calc(const int &p)
	{
		int tot = 0;
		for(int i = p; i; i -= lowbit(i))
			tot += s[i];
		return tot;
	}
}
struct action
{
	int op, x, y, z;
	action(const int &op, const int &x, const int &y, const int &z) : op(op), x(x), y(y), z(z) {}
};
int ans[maxn];
void work(vector<action> act, const int &st, const int &ed)
{
	using namespace BIT;
	if(st == ed)
	{
		for(int i = 0; i < act.size(); i ++)
		{
			if(act[i].op == 0)
				act[i].z == 1 ? add(act[i].x, 1) : add(act[i].x, -1);
			else
			{
				int tmp = calc(act[i].y) - calc(act[i].x - 1);
				act[i].op > 0 ? ans[act[i].op] += tmp : ans[-act[i].op] -= tmp;
			}
		}
		return;
	}
	int mid = st + ed >> 1;
	vector<action> next1, next2;
	for(int i = 0; i < act.size(); i ++)
	{
		if(act[i].op == 0)
		{
			if(act[i].y <= mid)
			{
				act[i].z == 1 ? add(act[i].x, 1) : add(act[i].x, -1);
				next1.push_back(act[i]);
			}
			else
				next2.push_back(act[i]);
		}
		else
		{
			if(act[i].z <= mid)
				next1.push_back(act[i]);
			else
			{
				int tmp = calc(act[i].y) - calc(act[i].x - 1);
				act[i].op > 0 ? ans[act[i].op] += tmp : ans[-act[i].op] -= tmp;
				next2.push_back(act[i]);
			}
		}
	}
	work(next1, st, mid);
	work(next2, mid + 1, ed);
}
int pos[maxn], b[maxn];
bool mark[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	BIT::n = n;
	for(int i = 1; i <= n; i ++)
	{
		int x;
		cin >> x;
		pos[x] = i;
	}
	vector<action> act;
	for(int i = 1; i <= n; i ++)
	{
		cin >> b[i];
		b[i] = pos[b[i]];
		act.push_back(action(0, i, b[i], 1));
	}
	for(int i = 1; i <= m; i ++)
	{
		int op;
		cin >> op;
		if(op == 1)
		{
			int la, ra, lb, rb;
			cin >> la >> ra >> lb >> rb;
			act.push_back(action(i, lb, rb, ra));
			act.push_back(action(-i, lb, rb, la - 1));
			mark[i] = 1;
		}
		else if(op == 2)
		{
			int x, y;
			cin >> x >> y;
			act.push_back(action(0, x, b[x], 2));
			act.push_back(action(0, x, b[y], 1));
			act.push_back(action(0, y, b[y], 2));
			act.push_back(action(0, y, b[x], 1));
			swap(b[x], b[y]);
		}
	}
	for(int i = 1; i <= n; i ++)
		act.push_back(action(0, i, b[i], 2));
	work(act, 0, n);
	for(int i = 1; i <= m; i ++)
		if(mark[i])
			cout << ans[i] << endl;
	
	return 0;
}