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
char a[3];
int main()
{
	std::ios::sync_with_stdio(false);
	string s;
	cin >> s;
	for(int i = 1; i < (int)s.size() - 1; i ++)
	{
		a[0] = s[i - 1];
		a[1] = s[i];
		a[2] = s[i + 1];
		sort(a + 0, a + 3);
		if(a[0] == 'A' && a[1] == 'B' && a[2] == 'C')
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	
	return 0;
}