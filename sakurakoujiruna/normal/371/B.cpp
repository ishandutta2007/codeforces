#include <bits/stdc++.h>
using namespace std;

int num[3] = {2, 3, 5};
int cnt[3];

int main()
{
	ios :: sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	for(int i = 0; i < 3; i ++)
	{
		while(a % num[i] == 0)
		{
			a /= num[i];
			cnt[i] ++;
		}
		while(b % num[i] == 0)
		{
			b /= num[i];
			cnt[i] --;
		}
	}
	if(a != b)
		cout << -1 << '\n';
	else
		cout << abs(cnt[2]) + abs(cnt[1]) + abs(cnt[0]) << '\n';
	return 0;
}