#include <iostream>
#include <vector>
using namespace std;

const int N = 101111;
vector <int> a[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		int x;
		cin >> x;
		a[x].push_back(i);
		a[x - 1].push_back(i);
	}
	int ans = 1;
	for(int i = 0; i < N; i ++)
	{
		int cnt = 0;
		for(int j = 0; j < a[i].size(); j ++)
			if(j == 0 || a[i][j] == a[i][j - 1] + 1)
			{
				cnt ++;
				ans = max(ans, cnt);
			}
			else
				cnt = 1;
	}
	cout << ans << '\n';
	return 0;
}