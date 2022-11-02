#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1000011;
const int M = 1011;

int x[N], y[N];
bool cmp(const int &lhs, const int &rhs)
{
	return y[lhs] < y[rhs];
}
vector <int> vec[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> x[i] >> y[i];
		vec[x[i] / 1000].push_back(i);
	}
	for(int i = 0; i < M; i ++)
	{
		sort(vec[i].begin(), vec[i].end(), cmp);
		if(i & 1)
			reverse(vec[i].begin(), vec[i].end());
		for(auto &x : vec[i])
			cout << x << ' ';
	}
	cout << '\n';
	return 0;
}