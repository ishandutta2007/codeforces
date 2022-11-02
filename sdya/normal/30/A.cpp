#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <cstring>
#include <bitset>
#include <map>
#include <set>

using namespace std;

long long a, b, n;

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> a >> b >> n;
	for (long long i = -2000; i <= 2000; i ++)
	{
		long long c = a;
		for (long long j = 1; j <= n; j ++)
		{
			c *= i;
			if (abs(c) > abs(b)) break;
		}
		if (c == b)
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << "No solution" << endl;
	return 0;
}