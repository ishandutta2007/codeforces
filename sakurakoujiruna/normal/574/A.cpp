#include <iostream>
using namespace std;

const int N = 101;
int a[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	int ans = 0;
	while(true)
	{
		bool flag = true;
		for(int i = 1; i < n; i ++)
			if(a[0] <= a[i])
				flag = false;
		if(flag)
			break;
		int max_id = 0;
		for(int i = 1; i < n; i ++)
			if(a[max_id] <= a[i])
				max_id = i;
		a[max_id] --;
		a[0] ++;
		ans ++;
	}
	cout << ans << '\n';
	return 0;
}