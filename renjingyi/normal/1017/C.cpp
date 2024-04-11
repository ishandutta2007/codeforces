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
	int x = sqrt(n);
	int now = n;
	while(now)
	{
		int st = max(now - x + 1, 1);
		for(int i = st; i <= now; i ++)
			cout << i << " ";
		now = st - 1;
	}
	cout << endl;
	
	return 0;
}