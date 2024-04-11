#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<vector>
#include<set>
#include<algorithm>
#include<iostream>
#include<ctime>
#include<iomanip>
#include<cassert>
#include<memory>
#include<string>
#include<string.h>
#include<math.h>

using namespace std;

typedef double ld;
typedef long long li;

struct pt {
	li x, y;
	pt(li x, li y) : x(x), y(y) {}
	pt() : x(0), y(0) {}
	void read() {
		scanf("%I64d%I64d", &x, &y);
	}
	pt operator + (const pt & a) {
		return pt(a.x + x, a.y + y);
	}

	pt operator - (const pt & a) {
		return pt(x - a.x, y - a.y);
	}

	pt operator * (ld k) {
		return pt(x * k, y * k);
	}

};

struct line {
	li a, b, c;
	line(pt & p, pt & q) {
		a = p.y - q.y;
		b = q.x - p.x;
		c = -(a * p.x + b * p.y);
	}
};

ld ang(const pt & p) {
	return atan2(p.y, p.x);
}

int k, n, q;
const int N = 500 * 1000 + 5;
pt EV[N];
pt P[N];
pt V[N];
int T[N];
int CNT[N];

pt v[N];

bool cmp(const pt & a, const pt & b) {
	return ang(a) < ang(b);
}

void read() {
	scanf("%d%d%d", &k, &n, &q);
	for (int i = 0; i < k; ++i)
		V[i].read();
	for (int i = 0; i < n; ++i) {
		P[i].read();
		scanf("%d", &CNT[i]);
	}
	for (int i = 0; i < q; ++i) {
		EV[i].read();
		scanf("%d", &T[i]);
	}
}

li ans[N];

li f[N];

void inc(int pos, int d) {
	for (; pos < N; pos |= pos + 1)
		f[pos] += d;
}

li get(int pos) {
	li res = 0;
	for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
		res += f[pos];
	return res;
}

li get(int l, int r) {
	return get(r) - get(l - 1);
}

ld PI = 3.1415926535897932384626433832795;

void solve() {
	for (int i = 0; i < k; ++i)
	{
		V[i] = V[i] * 2;
		V[i + k] = V[i] * -1;
	}
	sort(V, V + 2 * k, cmp);

	v[0] = pt(0, 0);
	for (int i = 1; i < 2 * k; ++i)
		v[i] = v[i - 1] + V[i - 1];
	pt c(0, 0);
	for (int i = 0; i < 2 * k; ++i)
		c = c + v[i];
	c = c * (1 / (2.0 * k));

	for (int i = 0; i < 2 * k; ++i)
		v[i] = v[i] - c;

	int sig[33];

	li maxx = v[0].x;
	for (int i = 0; i < 2 * k; ++i)
		maxx = max(maxx, v[i].x);

	for (int _i = 0; _i < 2 * k; ++_i) {
		int _j = (_i + 1) % (2 * k);
		sig[_i] = 1;
		if (v[_i].x == v[_j].x)
			sig[_i] = 0;
		if (v[_i].x < v[_j].x)
			sig[_i] = -1;
	}

	for (int _i = 0; _i < 2 * k; ++_i) {
		vector<pair<li, int> > ev;
		vector <li> xs;
		memset(f, 0, sizeof f);

		int _j = (_i + 1) % (2 * k);
		line l(v[_i], v[_j]);
		ld c = -l.a;
		if (l.b < 0)
			l.b *= -1, c *= -1;

		if (v[_i].x == v[_j].x)
			continue;

		for (int i = 0; i < n; ++i) {
			li cy = P[i].y * l.b - P[i].x * c;
			if (sig[_i] == -1)
				cy++;
			ev.push_back(make_pair(cy, i));
			xs.push_back(P[i].x);
		}

		for (int i = 0; i < q; ++i) {
			pt p = EV[i] + v[_i] * T[i];
			li cy = p.y * l.b - c * p.x;
			ev.push_back(make_pair(cy, i + n));
			xs.push_back(p.x);
			xs.push_back(p.x - 1);
			xs.push_back((EV[i] + v[_j] * T[i]).x);
			xs.push_back((EV[i] + v[_j] * T[i]).x - 1);
		}
		sort(ev.begin(), ev.end(), [](const pair<li, int> & a, const pair<li, int> & b) {
			if (a.first != b.first)
				return a.first < b.first;
			return a.second < b.second;
		});
		sort(xs.begin(), xs.end());
		xs.resize(unique(xs.begin(), xs.end()) - xs.begin());

		for (int i = 0; i < ev.size(); ++i) {
			if (ev[i].second < n) {
				int j = ev[i].second;
				inc(lower_bound(xs.begin(), xs.end(), P[j].x) - xs.begin(), CNT[j]);
			}
			else {
				int j = ev[i].second - n;
				pt p1 = EV[j] + v[_i] * T[j];
				pt p2 = EV[j] + v[_j] * T[j];
				if (p1.x > p2.x)
					swap(p1.x, p2.x);
				li l = p1.x, r = p2.x;
				if (v[_i].x != maxx && v[_j].x != maxx)
					r--;
				ans[j] += sig[_i] * get(lower_bound(xs.begin(), xs.end(), l) - xs.begin(), lower_bound(xs.begin(), xs.end(), r) - xs.begin());
			}
		}
	}

	for (int i = 0; i < q; ++i)
		printf("%I64d\n", ans[i]);
}

int main() {

	srand(time(NULL));

	read();
	solve();

	return 0;
}