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
map<long long, int> ans;
int n;
void work(const int &v)
{
	long long cnt = n / v;
	ans[cnt * (cnt - 1) / 2 * v + cnt] = 1;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i * i <= n; i ++)
		if(n % i == 0)
		{
			work(i);
			work(n / i);
		}
	for(map<long long, int>::iterator it = ans.begin(); it != ans.end(); it ++)
		cout << it->first << " ";
	cout << endl;
	
	return 0;
}