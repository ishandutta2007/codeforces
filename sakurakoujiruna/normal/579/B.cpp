#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 811;

int ans[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	vector <pair <int, pair <int, int> > > vec;
	for(int i = 2; i <= 2 * n; i ++)
		for(int j = 1; j < i; j ++)
		{
			int v;
			cin >> v;
			vec.push_back(make_pair(v, make_pair(i, j)));
		}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	memset(ans, -1, sizeof(ans));
	for(auto team: vec)
	{
		int a = team.second.first;
		int b = team.second.second;
		if(ans[a] == -1 && ans[b] == -1)
		{
			ans[a] = b;
			ans[b] = a;
		}
	}
	for(int i = 1; i <= 2 * n; i ++)
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}