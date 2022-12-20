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
	int ans = 0;
	for(int i = 0; i < s.size(); i ++)
	{
		if(s[i] != s[i + 1])
			i ++;
		ans ++;
	}
	cout << ans << endl;
	
	return 0;
}