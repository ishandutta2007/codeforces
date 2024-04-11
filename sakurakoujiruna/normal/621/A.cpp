#include <iostream>
using namespace std;

typedef long long intl;

int main()
{
	ios :: sync_with_stdio(false);
	int odd_min = 0x3f3f3f3f;
	int odd_cnt = 0;
	intl sum = 0;

	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		int x;
		cin >> x;
		sum += x;
		if(x & 1)
		{
			odd_min = min(odd_min, x);
			odd_cnt ++;
		}
	}
	if(odd_cnt & 1)
		sum -= odd_min;
	cout << sum << '\n';
	return 0;
}