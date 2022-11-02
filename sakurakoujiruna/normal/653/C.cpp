#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 150011;

int t[N];

bool fit(int p)
{
	if(p & 1)
	{
		if(t[p] < t[p + 1])
			return true;
	}
	else
	{
		if(t[p] > t[p + 1])
			return true;
	}
	return false;
}

bool check(int n, int a, int b, int cnt)
{
	vector <int> v;
	for(int i = -1; i <= 1; i ++)
	{
		if(a + i >= 1 && a + i < n)
			v.push_back(a + i);
		if(b + i >= 1 && b + i < n)
			v.push_back(b + i);
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());

	for(auto &p : v)
		if(fit(p))
			cnt --;
	swap(t[a], t[b]);
	for(auto &p : v)
		if(fit(p))
			cnt ++;
	swap(t[a], t[b]);
	
	return cnt == n - 1;
}

void solve(int n, int a, int b, int cnt)
{
	int ans = 0;
	for(int i = 1; i <= n; i ++)
		if(i != a && i != b)
		{
			ans += check(n, a, i, cnt);
			ans += check(n, b, i, cnt);
		}
	ans += check(n, a, b, cnt);
	cout << ans << '\n';
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> t[i];

	int cnt = 0;
	for(int i = 1; i < n; i ++)
		cnt += fit(i);

	for(int i = 1; i < n; i ++)
		if(!fit(i))
		{
			solve(n, i, i + 1, cnt);
			return 0;
		}
	return 0;
}