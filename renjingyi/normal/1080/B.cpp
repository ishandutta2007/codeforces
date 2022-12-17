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
	int q;
	cin >> q;
	for(int i = 1; i <= q; i ++)
	{
		long long l, r;
		cin >> l >> r;
		long long st1 = l & 1 ? l : l + 1, ed1 = r & 1 ? r : r - 1;
		long long st2 = l & 1 ? l + 1 : l, ed2 = r & 1 ? r - 1 : r;
		cout << (st2 + ed2) * ((ed2 - st2) / 2 + 1) / 2 - (st1 + ed1) * ((ed1 - st1) / 2 + 1) / 2 << endl;
	}
	
	return 0;
}