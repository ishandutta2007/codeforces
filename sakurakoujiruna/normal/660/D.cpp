#include <iostream>
#include <map>
#include <tuple>
using namespace std;

const int N = 2011;
typedef long long intl;

struct Point
{
	int x, y;
	Point operator +(Point p) {
		return {x + p.x, y + p.y};
	}
	bool operator <(Point p) const {
		return tie(x, y) < tie(p.x, p.y);
	}
}p[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> p[i].x >> p[i].y;
	map <Point, int> mp;
	for(int i = 0; i < n; i ++)
		for(int j = i + 1; j < n; j ++)
			mp[p[i] + p[j]] ++;

	intl ans = 0;
	for(auto &p : mp)
		ans += (intl)(p.second - 1) * p.second / 2;
	cout << ans << '\n';
	return 0;
}