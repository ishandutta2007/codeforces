#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct A
{
	int w, h, id;

	A(int w, int h, int id)
		: w(w), h(h), id(id)
	{}

	bool operator <(const A& x)
	{
		return w < x.w;
	}
};

const int INF = INT_MIN / 4;

int main()
{
	int n, w, h;
	cin >> n >> w >> h;
	vector<A> arr;
	for (int i = 1; i < n + 1; ++i)
	{
		int w1, h1;
		cin >> w1 >> h1;
		arr.push_back(A(w1, h1, i));
	}
	sort(arr.begin(), arr.end());
	++n;
	arr.insert(arr.begin(), A(w, h, 0));
	vector<int> d(n), prev(n);
	d[0] = 1;
	prev[0] = -1;
	for (int i = 1; i < n; ++i)
	{
		d[i] = INF * 2;
		for (int j = 0; j < i; ++j)
		{
			if (d[j] <= INF)
				continue;
			if (arr[i].h > arr[j].h && arr[i].w > arr[j].w && d[i] < d[j] + 1)
			{
				d[i] = max(d[i], d[j] + 1);
				prev[i] = j;
			}
		}
	}
	int maxi = 0;
	for (int i = 1; i < n; ++i)
	{
		if (d[i] > d[maxi])
		{
			maxi = i;
		}
	}
	cout << d[maxi] - 1 << endl;
	vector<int> ans;
	while (prev[maxi] != -1)
	{
		ans.push_back(arr[maxi].id);
		maxi = prev[maxi];
	}
	reverse(ans.begin(), ans.end());
	for (int x = 0; x < ans.size(); ++x)
		cout << ans[x] << ' ';
	cout << endl;
}