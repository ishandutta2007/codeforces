#include <iostream>
using namespace std;

const int N = 121;

int a[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];

	int ans = 0;
	for(int i = 1; i <= n; i ++)
		if(a[i] == 1)
			ans ++;
		else if(i > 1 && i < n && a[i - 1] == 1 && a[i + 1] == 1)
			ans ++;

	cout << ans << '\n';
	return 0;
}