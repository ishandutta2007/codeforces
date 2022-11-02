#include <iostream>
using namespace std;

const int N = 511111;

int num[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> num[i];

	int ans = 0;
	int last = 1;
	for(int i = 2; i <= n + 1; i ++)
		if(i == n + 1 || num[i] == num[i - 1])
		{
			int s = last;
			int t = i - 1;
			last = i;
			//cout << s << ' ' << t << '\n';
			if((t - s + 1) & 1)
				ans = max(ans, (t - s + 1) / 2);
			else
				ans = max(ans, (t - s + 1) / 2 - 1);
			if((t - s + 1) & 1)
				for(int i = s + 1; i <= t; i ++)
					num[i] = num[s];
			else
			{
				int mid = (s + t) / 2;
				for(int i = s + 1; i <= mid; i ++)
					num[i] = num[s];
				for(int i = mid + 1; i < t; i ++)
					num[i] = num[t];
			}
		}

	cout << ans << '\n';
	for(int i = 1; i <= n; i ++)
		cout << num[i] << ' ';
	cout << '\n';
	return 0;
}