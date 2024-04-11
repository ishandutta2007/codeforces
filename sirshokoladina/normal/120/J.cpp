#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <deque>
#include <queue>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)
#define ford(i,n) for (int i = (int)(n) - 1; i >= 0; i--)

int x[100010], y[100010], t[100010];
int num[100010];

bool cmp(int i, int j) {
	return make_pair(x[i], y[i]) < make_pair(x[j], y[j]);
}

int sqr(int i) {
	return i * i;
}

int di(int i, int j) {
	return sqr(x[i] - x[j]) + sqr(y[i] - y[j]);
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int n;
	cin >> n;
	forn (i, n) {
		scanf("%d%d", &x[i], &y[i]);
		t[i] = 2 * (int)(y[i] < 0) + (int)(x[i] < 0) + 1;
		x[i] = abs(x[i]);
		y[i] = abs(y[i]);
		num[i] = i;
	}
	sort(num, num + n, cmp);
	int l = 0, r = 10000;
	while (l != r) {
		int m = (l + r) / 2;
		cerr << m << endl;
		vector<pair<int, int> > v;
		int k = 0;
		set<pair<int, int> > s;
		bool q = 0;
		forn (i, n) {
			while (k < (int)v.size() && v[k].first < x[num[i]] - m) {
				s.erase(make_pair(y[v[k].second], v[k].second));
				k++;
			}
			set<pair<int, int> > :: iterator up = s.upper_bound(make_pair(y[num[i]], 0)), down = up;
			if (up != s.end() && up->first - y[num[i]] <= m) {
				cerr << s.size() << ' ' << v.size() - k << ' ' << num[i] << ' ' << up->second << endl;
				q = 1;
				break;
			}
			if (down != s.begin() && y[num[i]] - (--down)->first <= m) {
				cerr << s.size() << ' ' << v.size() - k << ' ' << num[i] << ' ' << up->second << endl;
				q = 1;
				break;
			}
			v.push_back(make_pair(x[num[i]], num[i]));
			s.insert(make_pair(y[num[i]], num[i]));
		}
		if (q) {
			r = m;
		} else {
			l = m + 1;
		}
	}
	int m = floor(sqrtl(2) * l);
	int mn = 1000000000;
	int ans1 = 0, ans2 = 1;
	vector<pair<int, int> > v;
	int k = 0;
	set<pair<int, int> > s;
	forn (i, n) {
		while (k < (int)v.size() && v[k].first < x[num[i]] - m) {
			s.erase(make_pair(y[v[k].second], v[k].second));
			k++;
		}
		set<pair<int, int> > :: iterator up = s.upper_bound(make_pair(y[num[i]], 0)), down = up;
		while (up != s.end() && up->first - y[num[i]] <= m) {
			int d = di(up->second, num[i]);
			if (d < mn) {
				mn = d;
				ans1 = up->second;
				ans2 = num[i];
			}
			up++;
		}
		while (down != s.begin() && y[num[i]] - (--down)->first <= m) {
			int d = di(down->second, num[i]);
			if (d < mn) {
				mn = d;
				ans1 = down->second;
				ans2 = num[i];
			}
			if (down == s.begin()) {
				break;
			}
		}
		v.push_back(make_pair(x[num[i]], num[i]));
		s.insert(make_pair(y[num[i]], num[i]));
	}
	cout << ans1 + 1 << ' ' << t[ans1] << ' ' << ans2 + 1 << ' ' << 5 - t[ans2];
}