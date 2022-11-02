#include <iostream>
#include <set>
#include <tuple>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

typedef long long intl;

struct Point
{
	int x, y;
	Point operator -(Point p) {
		return {x - p.x, y - p.y};
	}
	bool operator <(Point p) const {
		return tie(x, y) < tie(p.x, p.y);
	}
	bool operator ==(Point p) const {
		return tie(x, y) == tie(p.x, p.y);
	}
	intl dot(Point p) {
		return (intl)x * p.x + (intl)y * p.y;
	}
};

int q[4];

int main()
{
	ios :: sync_with_stdio(false);

	bool flag = true;
	vector <Point> p;
	set <pair <Point, Point> > his;
	for(int i = 0; i < 4; i ++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if(x1 == x2 && y1 == y2)
			flag = false;
		if(x1 != x2 && y1 != y2)
			flag = false;
		p.push_back({x1, y1});
		p.push_back({x2, y2});

		Point p1 = {x1, y1};
		Point p2 = {x2, y2};
		if(p1 < p2)
			swap(p1, p2);
		if(his.find({p1, p2}) != his.end())
			flag = false;
		his.insert({p1, p2});
	}
	sort(p.begin(), p.end());
	p.resize(unique(p.begin(), p.end()) - p.begin());
	if(p.size() != 4)
		flag = false;
	else
	{
		p.push_back(p[0]);
		iota(q, q + 4, 0);
		bool tmp = false;
		do
		{
			bool tt = true;
			for(int i = 1; i < 4; i ++)
				if((p[q[i]] - p[q[i - 1]]).dot(p[q[i + 1]] - p[q[i]]) != 0)
					tt = false;
			if(tt)
				tmp = true;
		}while(next_permutation(q + 1, q + 4));
		if(!tmp)
			flag = false;
	}

	cout << (flag ? "YES" : "NO") << '\n';
	return 0;
}