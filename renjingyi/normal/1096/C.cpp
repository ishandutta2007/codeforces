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
	while(t --)
	{
		int a;
		cin >> a;
		for(int i = 3; i <= 360; i ++)
			if(a <= 180 - 360 / i && 2 * i * a % 360 == 0)
			{
				cout << i << endl;
				break;
			}
	}
		
	return 0;
}