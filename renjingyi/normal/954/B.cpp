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
	int n;
	cin >> n;
	string s;
	cin >> s;
	int mn = s.size();
	for(int i = 1; i <= (int)s.size() / 2; i ++)
		if(s.substr(0, i << 1) == s.substr(0, i) + s.substr(0, i))
			mn = min(mn, i + 1 + (int)s.size() - 2 * i);
	cout << mn << endl;
	
	return 0;
}