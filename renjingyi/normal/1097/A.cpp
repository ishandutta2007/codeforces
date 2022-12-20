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
	string s;
	cin >> s;
	bool ok = 0;
	for(int i = 1; i <= 5; i ++)
	{
		string t;
		cin >> t;
		if(t[0] == s[0] || t[1] == s[1])
			ok = 1;
	}
	cout << (ok ? "YES" : "NO") << endl;
	
	return 0;
}