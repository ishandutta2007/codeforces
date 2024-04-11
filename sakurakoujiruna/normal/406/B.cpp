#include <iostream>
#include <vector>
using namespace std;

const int N = 1000011;

bool vis[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		int x;
		cin >> x;
		vis[x] = true;
	}
	int cnt = 0;
	vector <int> ans;
	for(int i = 1; i <= 1000000; i ++)
		if(vis[i])
		{
			if(!vis[1000000 - i + 1])
				ans.push_back(1000000 - i + 1);
			else
				cnt ++;
		}
	for(int i = 1; i <= 1000000; i ++)
		if(cnt && !vis[i] && !vis[1000000 - i + 1])
		{
			ans.push_back(i);
			ans.push_back(1000000 - i + 1);
			cnt -= 2;
		}

	cout << ans.size() << '\n';
	for(auto &x : ans)
		cout << x << ' ';
	cout << '\n';
	return 0;
}