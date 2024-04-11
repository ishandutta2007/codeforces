#include <iostream>
using namespace std;

const int N = 1211111;
int cnt[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		int x;
		cin >> x;
		cnt[x] ++;
	}
	int ans = 0;
	for(int i = 0; i < N - 1; i ++)
	{
		if(cnt[i] & 1)
			ans ++;
		cnt[i + 1] += cnt[i] / 2;
	}
	cout << ans << '\n';
	return 0;
}