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
	string a, b;
	cin >> a >> b;
	int cnt0 = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
	for(int i = 0; i < n; i ++)
	{
		if(a[i] == '0' && b[i] == '0')
			cnt0 ++;
		if(a[i] == '0' && b[i] == '1')
			cnt1 ++;
		if(a[i] == '1' && b[i] == '0')
			cnt2 ++;
		if(a[i] == '1' && b[i] == '1')
			cnt3 ++;
	}
	long long ans = 0;
	for(int i = 0; i < n; i ++)
	{
		if(a[i] == '0' && b[i] == '0')
			ans += cnt2 + cnt3;
		if(a[i] == '0' && b[i] == '1')
			ans += cnt2;
		if(a[i] == '1' && b[i] == '0')
			ans += cnt0 + cnt1;
		if(a[i] == '1' && b[i] == '1')
			ans += cnt0;
	}
	cout << ans / 2 << endl;
	
	return 0;
}