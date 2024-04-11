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
int base[35];
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int s = 0, cnt = 0;
	for(int i = 1; i <= n; i ++)
	{
		int tmp;
		cin >> tmp;
		s ^= tmp;
		tmp = s;
		for(int j = 30; j >= 0; j --)
			if((tmp >> j) & 1)
			{
				if(base[j])
					tmp ^= base[j];
				else
				{
					base[j] = tmp;
					cnt ++;
					break;
				}
			}
	}
	cout << (s ? cnt : -1) << endl;
	
	return 0;
}