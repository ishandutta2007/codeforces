#include <bits/stdc++.h>
using namespace std;

struct Point
{
	int x, y;
	Point operator -(Point p) {
		return {x - p.x, y - p.y};
	}
	Point operator +(Point p) {
		return {x + p.x, y + p.y};
	}
	bool operator <(Point p) const {
		return tie(x, y) < tie(p.x, p.y);
	}
	int cross(Point p) {
		return x * p.y - y * p.x;
	}
	int len2() {
		return x * x + y * y;
	}
};
vector <Point> p;
int xmul(Point a, Point b, Point c) {
	return (b - a).cross(c - a);
}

vector <Point> convex(vector <Point> v)
{
	vector <Point> r;
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); i ++) {
		while(r.size() >= 2 && xmul(*++r.rbegin(), v[i], *r.rbegin()) >= 0)
			r.pop_back();
		r.push_back(v[i]);
	}
	int d = r.size();
	for(int i = (int)v.size() - 2; i >= 0; i --) {
		while(r.size() > d && xmul(*++r.rbegin(), v[i], *r.rbegin()) >= 0)
			r.pop_back();
		if(i != 0)
			r.push_back(v[i]);
	}
	return r;
}

int n, r;
int ans = 0;
vector <int> rec;
vector <int> now;
void dfs(int c, int pid, int sum, Point acc)
{
	if(c == n)
	{
		if(sum * n - acc.len2() > ans)
		{
			ans = sum * n - acc.len2();
			rec = now;
		}
		return;
	}
	if(pid == p.size())
		return;
	
	int mx = max(0, abs(acc.x) - (n - c) * r);
	int my = max(0, abs(acc.y) - (n - c) * r);
	if((sum + (n - c) * r * r * 2) * n - Point{mx, my}.len2() <= ans)
		return;
	dfs(c, pid + 1, sum, acc);
	now[c] = pid;
	dfs(c + 1, pid, sum + p[pid].len2(), acc + p[pid]);

}

int main()
{
	ios :: sync_with_stdio(false);
	cin >> n >> r;
	for(int x = -r; x <= r; x ++)
		for(int y = -r; y <= r; y ++)
			if(Point{x, y}.len2() <= r * r)
				p.push_back({x, y});
	p = convex(p);

	now.resize(n);
	dfs(0, 0, 0, {0, 0});
	cout << ans << '\n';
	for(auto &i : rec)
		cout << p[i].x << ' ' << p[i].y << '\n';
	return 0;
}