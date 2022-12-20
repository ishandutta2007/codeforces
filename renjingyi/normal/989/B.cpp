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
	int n, p;
	cin >> n >> p;
	string s;
	cin >> s;
	for(int i = 0; i < (int)s.size() - p; i ++)
	{
		if(s[i] == '.' || s[i + p] == '.' || s[i] != s[i + p])
		{
			if(s[i] == '.' && s[i + p] == '.')
				s[i] = '1', s[i + p] = '0';
			else if(s[i] == '.')
				s[i] = '0' + '1' - s[i + p];
			else if(s[i + p] == '.')
				s[i + p] = '0' + '1' - s[i];
			for(int j = 0; j < s.size(); j ++)
				if(s[j] == '.')
					s[j] = '0';
			cout << s << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	
	return 0;
}