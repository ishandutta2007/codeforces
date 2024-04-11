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
	int n, a, b;
	cin >> n >> a >> b;
	if(n == 1)
	{
		cout << "YES" << endl;
		cout << 0 << endl;
		return 0;
	}
	if(a > 1 && b > 1)
	{
		cout << "NO" << endl;
		return 0;
	}
	if(a == 1 && b == 1)
	{
		if(n == 2 || n == 3)
		{
			cout << "NO" << endl;
			return 0;
		}
		cout << "YES" << endl;
		for(int i = 1; i <= n; i ++)
		{
			for(int j = 1; j <= n; j ++)
			{
				if(abs(i - j) == 1)
					cout << 1;
				else
					cout << 0;
			}
			cout << endl;
		}
		cout << endl;
		return 0;
	}
	cout << "YES" << endl;
	if(b == 1)
	{
		for(int i = 1; i <= n; i ++)
		{
			for(int j = 1; j <= n; j ++)
			{
				if(i < a || j < a || i == j)
					cout << 0;
				else
					cout << 1;
			}
			cout << endl;
		}
	}
	else if(a == 1)
	{
		for(int i = 1; i <= n; i ++)
		{
			for(int j = 1; j <= n; j ++)
			{
				if((i < b || j < b) && i != j)
					cout << 1;
				else
					cout << 0;
			}
			cout << endl;
		}
	}
	
	return 0;
}