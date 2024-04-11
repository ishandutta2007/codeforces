#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

const int N = 100011;
typedef long double doublel;
const doublel Eps = 1e-8;

struct Event
{
	int type; // 0: add 1: del 2: query
	int pos;
	int magic;
	doublel p;
	Event(int type, int pos, int magic, doublel p) : type(type), pos(pos), magic(magic), p(p) { }
	bool operator <(const Event &rhs) const
	{
		if(pos == rhs.pos)
			return type < rhs.type;
		return pos < rhs.pos;
	}
};

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector <Event> events;
	for(int i = 0; i < n; i ++)
	{
		int x, h, l, r;
		cin >> x >> h >> l >> r;
		events.push_back(Event(0, x - h, 0, l / 100.0));
		events.push_back(Event(1, x, 0, l / 100.0));
		events.push_back(Event(0, x + 1, 0, r / 100.0));
		events.push_back(Event(1, x + h + 1, 0, r / 100.0));
	}
	doublel ans = 0;
	for(int i = 0; i < m; i ++)
	{
		int p, x;
		cin >> p >> x;
		events.push_back(Event(2, p, x, 0));
	}
	sort(events.begin(), events.end());

	doublel now = 0;
	int cant = 0;
	for(auto &eve : events)
		if(eve.type == 0)
		{
			if(eve.p + Eps < 1)
				now += log1pl(-eve.p);
			else
				cant ++;
		}
		else if(eve.type == 1)
		{
			if(eve.p + Eps < 1)
				now -= log1pl(-eve.p);
			else cant --;
		}
		else if(cant == 0)
			ans += eve.magic * expl(now);

	cout << setprecision(12) << ans << '\n';
	return 0;
}