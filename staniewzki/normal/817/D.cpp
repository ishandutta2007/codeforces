#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> h(n);
	for(int i = 0; i < n; i++)
		cin >> h[i];

	auto get = [&](function<bool(int, int)> bad)
	{
		vector<int> p(n);
		vector<pair<int, int>> Q;
		for(int i = 0; i < n; i++)
		{
			while(!Q.empty() && bad(Q.back().first, h[i]))
				Q.pop_back();
			p[i] = (Q.empty() ? -1 : Q.back().second);
			Q.emplace_back(h[i], i);
		}
		return p;
	};

	auto last_smaller = get([](int a, int b) { return a > b; });
	auto last_bigger = get([](int a, int b) { return a < b; });
	reverse(h.begin(), h.end());
	auto next_smaller = get([](int a, int b) { return a >= b; });
	auto next_bigger = get([](int a, int b) { return a <= b; });
	reverse(h.begin(), h.end());
	reverse(next_smaller.begin(), next_smaller.end());
	reverse(next_bigger.begin(), next_bigger.end());

	for(int i = 0; i < n; i++)
	{
		next_smaller[i] = n - 1 - next_smaller[i];
		next_bigger[i] = n - 1 - next_bigger[i];
	}

	long long ans = 0;
	for(int i = 0; i < n; i++)
	{
		ans -= (long long) h[i] * (i - last_smaller[i]) * (next_smaller[i] - i);
		ans += (long long) h[i] * (i - last_bigger[i]) * (next_bigger[i] - i);
	}

	//ans = ans / n / (n + 1) * 2;
	cout << ans << "\n";
}