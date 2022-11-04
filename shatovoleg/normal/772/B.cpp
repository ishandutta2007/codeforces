#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using ll = long long;
using point = pair<ld, ld>;

int n;
vector <point> arr;

point dec(point a, point b)
{
	return {a.first - b.first, a.second - b.second};
}

ld get_vector_mul(point a, point b)
{
	return a.first * b.second - a.second * b.first;
}

ld get_dist(point a, point b)
{
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

ld get_dist(point a, point b, point c)
{
	return fabs(get_vector_mul(dec(a, b), dec(c, a)) / get_dist(a, b));
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	arr.resize(n + 2);
	for (int i = 0; i < n; ++i)
		cin >> arr[i].first >> arr[i].second;
	arr[n] = arr[0];
	arr[n + 1] = arr[1];
	long double ans = 4e9;
	for (int i = 1; i <= n; ++i)
	{
		ld d = get_dist(arr[i - 1], arr[i + 1], arr[i]);
		ans = min(ans, d / 2);
	}
	cout << fixed << setprecision(8) << ans << endl;
}