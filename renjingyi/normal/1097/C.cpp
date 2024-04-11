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
const int maxn = 1e5 + 5;
string s[maxn];
int mn[maxn], add[maxn];
int state[maxn];
bool cmp(const int &a, const int &b)
{
	return add[a] == add[b] ? mn[a] > mn[b] : add[a] > add[b];
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> s[i];
		for(int j = 0; j < s[i].size(); j ++)
		{
			add[i] += s[i][j] == '(' ? 1 : -1;
			mn[i] = min(mn[i], add[i]);
		}
	}
	for(int i = 1; i <= n; i ++)
		state[i] = i;
	sort(state + 1, state + n + 1, cmp);
	int pos1 = 1, pos2 = n;
	int cnt = 0;
	while(pos1 < pos2)
	{
		if(add[state[pos1]] + add[state[pos2]] == 0)
		{
			if(mn[state[pos1]] >= 0 && add[state[pos1]] + mn[state[pos2]] >= 0)
			{
				cnt ++;
				pos1 ++;
				pos2 --;
			}
			else if(mn[state[pos1]] < 0)
				pos1 ++;
			else
				pos2 --;
		}
		else if(add[state[pos1]] + add[state[pos2]] > 0)
			pos1 ++;
		else
			pos2 --;
	}
	cout << cnt << endl;
	
	return 0;
}