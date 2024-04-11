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
string s[2005];
int cot[2005];
int main()
{
	std::ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		cin >> s[i];
		for(int j = 1; j <= m; j ++)
			if(s[i][j - 1] == '1')
				cot[j] ++;
	}
	for(int i = 1; i <= n; i ++)
	{
		bool ok = 1;
		for(int j = 1; j <= m; j ++)
			if(s[i][j - 1] == '1' && cot[j] == 1)
			{
				ok = 0;
				break;
			}
		if(ok)
		{
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	
	return 0;
}