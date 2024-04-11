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
	long long totx = 0, toty = 0;
	for(int i = 1; i <= n; i ++)
	{
		long long a, b;
		cin >> a >> b;
		totx += a;
		toty += b;
	}
	for(int i = 1; i <= n; i ++)
	{
		long long a, b;
		cin >> a >> b;
		totx += a;
		toty += b;
	}
	cout << totx / n << " " << toty / n << endl;
	
	return 0;
}