#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>

#include <string.h>

using namespace std;


typedef long long LL;


int main()
{
	int n;
	string s;
	cin >> n;
	cin >> s;
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		int dx = 0, dy = 0;
		for (int j = i; j < n; j++)
		{
			if (s[j] == 'R') dx++;
			else if (s[j] == 'L') dx--;
			else if (s[j] == 'U') dy--;
			else dy++;
			if (dx == 0 && dy == 0) num++;
		}
	}
	cout << num << endl;
}