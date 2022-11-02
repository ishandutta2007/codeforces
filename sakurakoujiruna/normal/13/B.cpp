#include <iostream>
#include <tuple>
#include <numeric>
#include <algorithm>
using namespace std;

typedef long long intl;

struct Point
{
	intl x, y;
	Point operator -(Point p) {
		return {x - p.x, y - p.y};
	}
	bool operator ==(Point p) {
		return tie(x, y) == tie(p.x, p.y);
	}
	intl dot(Point p) {
		return x * p.x + y * p.y;
	}
	intl cross(Point p) {
		return x * p.y - y * p.x;
	}
	intl length2() {
		return dot(*this);
	}
	bool on_seg(Point p, Point q) {
		intl x_min = min(p.x, q.x);
		intl x_max = max(p.x, q.x);
		intl y_min = min(p.y, q.y);
		intl y_max = max(p.y, q.y);
		if(x_min > x || x_max < x)
			return false;
		if(y_min > y || y_max < y)
			return false;
		return (*this - p).cross(*this - q) == 0;
	}
};

struct Seg
{
	Point s, t;
}seg[3], ch[3];
int p[3];

bool check(Seg *ch)
{
	if(!(ch[0].s == ch[1].s))
		return false;
	if(!ch[2].s.on_seg(ch[0].s, ch[0].t) || !ch[2].t.on_seg(ch[1].s, ch[1].t))
		return false;
	Point p = ch[0].t - ch[0].s;
	Point q = ch[1].t - ch[1].s;
	if(p.cross(q) == 0 || p.dot(q) < 0)
		return false;
	intl la = (ch[2].s - ch[0].s).length2();
	intl lb = (ch[2].s - ch[0].t).length2();
	if(la * 16 < lb || lb * 16 < la)
		return false;
	intl lc = (ch[2].t - ch[1].s).length2();
	intl ld = (ch[2].t - ch[1].t).length2();
	if(lc * 16 < ld || ld * 16 < lc)
		return false;
	return true;
}

int main()
{
	ios :: sync_with_stdio(false);
	int kase;
	cin >> kase;
	while(kase --)
	{
		for(int i = 0; i < 3; i ++)
			cin >> seg[i].s.x >> seg[i].s.y >> seg[i].t.x >> seg[i].t.y;
		iota(p, p + 3, 0);
		bool flag = false;
		do
		{
			for(int k = 0; k < 8; k ++)
			{
				for(int i = 0; i < 3; i ++)
				{
					ch[i] = seg[p[i]];
					if((k >> i) & 1)
						swap(ch[i].s, ch[i].t);
				}
				flag |= check(ch);
			}
		}while(next_permutation(p, p + 3));
		cout << (flag ? "YES" : "NO") << '\n';
	}
	return 0;
}