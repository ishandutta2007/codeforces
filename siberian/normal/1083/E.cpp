#include <bits/stdc++.h>

using namespace std;
#define int long long
#define double long double
const int INF = -1e18;
struct line{
	int k, b;
	line() {
		k = 0, b = INF;
	}
	line(int x, int y) {
		k = x, b = y;
	}
};

int eval(line a, int x) {
	return a.k * x + a.b;
}

double cross(line a, line b) {
	return (double) (b.b - a.b) / (a.k - b.k);
}

struct cht{
	vector <line> l;
	vector <double> p;
	cht() {
		l = {};
		p = {};
	}
	void add(line a) {
		while (!p.empty() && cross(a, l.back()) <= p.back())
			p.pop_back(), l.pop_back();
		l.push_back(a);
		if (l.size() >= 2)
			p.push_back(cross(l[l.size() - 2], l[l.size() - 1]));
	}
	int get(int x) {
		int pos = lower_bound(p.begin(), p.end(), x) - p.begin();
		return eval(l[pos], x);
	}
};

int n;
vector <pair <pair <int, int>, int> > a;

void read() {
	cin >> n;
	a.resize(n);
	for (auto &i : a) {
		cin >> i.first.first >> i.first.second >> i.second;
	}
	sort(a.begin(), a.end());
}

int ans;
vector <int> dp;

void run() {
	ans = 0;
	dp.resize(n + 1, 0);
	cht help;
	help.add(line(0, 0));
	for (int i = 1; i <= n; i++) {
		dp[i] = a[i - 1].first.first * a[i - 1].first.second - a[i - 1].second;
		int plus = 0;
		/*for (int j = 1; j < i; j++) {
			plus = max(plus, dp[j] - a[j - 1].first.first * a[i - 1].first.second);
		}*/
		if (!help.l.empty())
			plus = help.get(-a[i - 1].first.second);
		dp[i] += plus;
		help.add(line(a[i - 1].first.first, dp[i]));
	}
	for (int i = 0; i <= n; i++)
		ans = max(ans, dp[i]);
}

void write() {
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}