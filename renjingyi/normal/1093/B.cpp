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
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i ++)
	{
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		bool ok = 1;
		for(int i = 0; i < s.size(); i ++)
			if(s[i] != s[(int)s.size() - 1 - i])
			{
				ok = 0;
				break;
			}
		if(ok)
			cout << -1 << endl;
		else
			cout << s << endl;
	}
	
	return 0;
}