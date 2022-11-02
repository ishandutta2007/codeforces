#include <bits/stdc++.h>
using namespace std;

const int N = 511;
const double Eps = 1e-8;
typedef long long intl;
//#define intl double

struct Point
{
	int x, y;
	Point operator -(const Point &p) const {
		return {x - p.x, y - p.y};
	}
	intl cross(const Point &p) {
		return (intl)x * p.y - (intl)y * p.x;
	}
	long double arg() {
		return atan2l(y, x);
	}
	void print() {
		cout << x << ' ' << y << '\n';
	}
}red[N], blue[N];

intl xmul(const Point &a, const Point &b, const Point &c)
{
	return (b - a).cross(c - a);
}
//

Point o;
struct Event
{
	Point p;
	int type; // 0: red, 1: blue
	bool operator <(Event e) const {
		return (p - o).arg() < (e.p - o).arg();
	}
};

int main()
{
	ios :: sync_with_stdio(false);
	int r, b;
	cin >> r >> b;
	for(int i = 0; i < r; i ++)
		cin >> red[i].x >> red[i].y;
	for(int i = 0; i < b; i ++)
		cin >> blue[i].x >> blue[i].y;

	if(r < 3)
		cout << "0\n";
	else
	{
		int ans = 0;
		for(int i = 0; i < r; i ++)
		{
			vector <Event> events;
			events.reserve(r - i + b);
			for(int j = i + 1; j < r; j ++)
				events.push_back({red[j], 0});
			for(int j = 0; j < b; j ++)
				events.push_back({blue[j], 1});
			o = red[i];
			sort(events.begin(), events.end());

			int n = events.size();

			for(int j = 0; j < n; j ++)
				if(events[j].type == 0)
				{
					bool first = false;
					Point mb;
					for(int tk = j + 1; tk < j + n; tk ++)
					{
						int k = (tk >= n) ? tk - n : tk;
						if(xmul(o, events[j].p, events[k].p) < 0)
							break;
						if(events[k].type == 0)
						{
							if(!first)
								ans ++;
							else if(xmul(events[j].p, mb, events[k].p) > 0)
								ans ++;
						}
						else
						{
							if(!first)
							{
								first = true;
								mb = events[k].p;
							}
							else if(xmul(events[j].p, mb, events[k].p) > 0)
								mb = events[k].p;
						}
					}
				}
		}
		cout << ans << '\n';
	}

	return 0;
}