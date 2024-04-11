#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 121111;
int a[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, k;
	cin >> n >> k;

	int basic = 0;
	int last = 0;
	vector <int> vec;
	for(int i = 0; i < n; i ++)
	{
		cin >> a[i];
		basic += a[i] / 10;
		last += 10 - a[i] / 10;
		if(a[i] % 10 != 0)
		{
			vec.push_back(10 - a[i] % 10);
			a[i] = (a[i] / 10 + 1) * 10;
			last --;
		}
	}

	int ans = basic;
	sort(vec.begin(), vec.end());
	for(int i = 0; i < vec.size(); i ++)
		if(k >= vec[i])
		{
			k -= vec[i];
			ans ++;
		}
	for(int i = 0; i < last; i ++)
		if(k >= 10)
		{
			k -= 10;
			ans ++;
		}

	cout << ans << '\n';
	return 0;
}