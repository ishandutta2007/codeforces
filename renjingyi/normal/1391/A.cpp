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
		int n;
		cin >> n;
		for(int i = 1; i <= n; i ++)
			cout << i << " ";
		cout << endl;
	}
	
	return 0;
}