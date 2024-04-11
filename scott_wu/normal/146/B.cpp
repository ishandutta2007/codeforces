#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
typedef long long ll;

int mask (int x)
{
	int arr[11];
	int ncount = 0;
	
	while (x)
	{
		if (x % 10 == 4 || x % 10 == 7)
		{
			arr[ncount] = x % 10;
			ncount++;
		}
		
		x /= 10;
	}
	
	int res = 0;
	for (int i = ncount - 1; i >= 0; i--)
		res = 10 * res + arr[i];
	return res;
}

int main()
{
	int a, b;
	cin >> a >> b;
	
	for (int i = a + 1; i <= 1000000; i++)
		if (mask (i) == b)
		{
			cout << i << "\n";
			break;
		}
	return 0;
}