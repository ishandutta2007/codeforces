#include <iostream>
#include <algorithm>
using namespace std;

const int N = 101111;

int m[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	int sum = 0;
	for(int i = 0; i < n; i ++)
	{
		cin >> m[i];
		sum += m[i];
	}
	int less = sum / n;
	int less_cnt = n - sum % n;
	int ans = 0;
	sort(m, m + n);
	for(int i = 0; i < n; i ++)
		if(i < less_cnt && m[i] < less)
			ans += less - m[i];
		else if(i >= less_cnt && m[i] < less + 1)
			ans += less + 1 - m[i];
	cout << ans << '\n';
	return 0;
}