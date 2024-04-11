#include <bits/stdc++.h>

using namespace std;

#define len(v) ((int)v.size())
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;

template<class t1, class t2>
bool cmin(t1 &a, const t2 &b)
{
	if (a > b)
	{
		a = b;
		return false;
	}
	return true;
}

template<class t1, class t2>
bool cmax(t1 &a, const t2 &b)
{
	if (a < b)
	{
		a = b;
		return false;
	}
	return true;
}

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (auto &x : arr)
		cin >> x;
	for (int i = 0; i < n - 1; ++i)
		if (arr[i + 1] - arr[i] > k)
		{
			cout << -1 << endl;
			return 0;
		}
	int prv = arr[0];
	int cnt = 1;
	for (int i = 1; i < n; ++i)
		if (arr[i] - prv > k)
		{
			++cnt;
			prv = arr[i - 1];
		}
	cout << cnt << endl;}