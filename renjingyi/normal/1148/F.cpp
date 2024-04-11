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
typedef pair<long long, long long> pp;
vector<pp> con[105];
int getbit(long long x)
{
	int s = 0;
	while(x)
	{
		if(x & 1)
			return s;
		s ++;
		x >>= 1;
	}
}
int bitcount(long long x)
{
	int s = 0;
	while(x)
	{
		s += x & 1;
		x >>= 1;
	}
	return s;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	long long tot = 0;
	for(int i = 1; i <= n; i ++)
	{
		long long v, m;
		cin >> v >> m;
		tot += v;
		con[getbit(m)].push_back(mp(v, m));
	}
	long long s = 0;
	for(int i = 62; i >= 0; i --)
		if(con[i].size())
		{
			long long s0 = 0, s1 = 0;
			for(int j = 0; j < con[i].size(); j ++)
			{
				if(bitcount(con[i][j].second & s) & 1)
					s1 += con[i][j].first;
				else
					s0 += con[i][j].first;
			}
			if(tot > 0 && s0 > s1)
				s += 1ll << i;
			else if(tot < 0 && s0 < s1)
				s += 1ll << i;
		}
	cout << s << endl;
	
	return 0;
}