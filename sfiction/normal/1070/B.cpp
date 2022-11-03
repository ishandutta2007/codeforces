#include <bits/stdc++.h>
using namespace std;

typedef pair<unsigned int, int> Sub;
typedef pair<unsigned int, unsigned int> Seg;

const int N = 2e5 + 10;

Seg white[N];
int wcnt;
Seg white2[N];
int wcnt2;
Sub black[N];
int bcnt;
set<Sub> ans;

void AddBlack(string s) {
	int a, b, c, d, e;

	if (s.find("/") != string::npos) {
		sscanf(s.c_str(), "-%d.%d.%d.%d/%d", &a, &b, &c, &d, &e);
	} else {
		sscanf(s.c_str(), "-%d.%d.%d.%d", &a, &b, &c, &d);
		e = 32;
	}
	black[bcnt].first = ((a << 8 | b) << 8 | c) << 8 | d;
	black[bcnt].second = e;
	// cout << black[bcnt].first << " " << black[bcnt].second << endl;
	++bcnt;
}

void AddWhite(string s) {
	unsigned int a, b, c, d, e;

	if (s.find("/") != string::npos) {
		sscanf(s.c_str(), "+%d.%d.%d.%d/%d", &a, &b, &c, &d, &e);
	} else {
		sscanf(s.c_str(), "+%d.%d.%d.%d", &a, &b, &c, &d);
		e = 32;
	}
	white[wcnt].first = ((a << 8 | b) << 8 | c) << 8 | d;
	white[wcnt].second = white[wcnt].first + (1 << 32 - e) - 1;
	// cout << white[wcnt].first << " " << white[wcnt].second << endl;
	++wcnt;
}

bool Check(Sub a) {
	if (a.second > 0)
		a.first &= (-1) << (32 - a.second);
	else
		a.first = 0;

	unsigned int l = a.first;
	unsigned int r = a.first + (1ll << 32 - a.second) -1;

	const Seg t1(l, 0);
	int i = lower_bound(white2, white2 + wcnt2, t1) - white2;

	// cout << "i " << i << " " << l << " " << r << " " << a.second << endl;

	if (i > 0) {
		if (white2[i - 1].second >= l) {
			return false;
		}
	}
	if (i < wcnt2) {
		if (r >= white2[i].first) {
			return false;
		}
	}
	// cout << wcnt2 << endl;

	return true;
}

bool Check() {
	sort(white, white + wcnt);
	wcnt2 = 0;
	if (wcnt) {
		white2[wcnt2++] = white[0];
	}
	for (int i = 1; i < wcnt; ++i) {
		if (white2[wcnt2 - 1].first <= white[i].first
			&& white[i].second <= white2[wcnt2 - 1].second) {
			continue;
		}
		if (white[i].first <= white2[wcnt2 - 1].first
			&& white2[wcnt2 - 1].second <= white[i].second) {
			white2[wcnt2 - 1] = white[i];
		} else {
			white2[wcnt2++] = white[i];
		}
	}
	for (int i = 0; i < bcnt; ++i) {
		Sub a = black[i];

		if (!Check(a)) {
			return false;
		}
		while (a.second > 0) {
			a.second--;
			if (!Check(a)) {
				a.second++;
				break;
			}
		}
		if (a.second > 0)
			a.first &= (-1) << (32 - a.second);
		else
			a.first = 0;
		ans.insert(a);
		// cout << a.first << "-" << a.second << endl;
	}

	return true;
}

int main() {
	ios::sync_with_stdio(0);

	int n;

	while (cin >> n) {
		wcnt = bcnt = 0;

		string ip;

		for (int i = 0; i < n; ++i) {
			cin >> ip;
			if (ip[0] == '-') {
				AddBlack(ip);
			} else {
				assert(ip[0] == '+');
				AddWhite(ip);
			}
		}
		ans.clear();

		if (Check()) {
			cout << ans.size() << endl;
			for (auto s : ans) {
				int a = s.first >> 24 & 255;
				int b = s.first >> 16 & 255;
				int c = s.first >> 8 & 255;
				int d = s.first & 255;

				cout << a << "." << b << "." << c << "." << d << "/" << s.second << endl;
			}
		} else {
			cout << -1 << endl;
		}
	}

	return 0;
}