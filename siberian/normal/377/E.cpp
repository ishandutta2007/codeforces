#include <bits/stdc++.h>

using namespace std;
#define int long long
#define double long double

vector<pair <int, int> > a;
int n, s;

bool cmp(pair <int, int> a, pair <int, int> b) {
	return a.first < b.first || (a.first == b.first && a.second > b.second);
}

void read() {
	cin >> n >> s;
	a.resize(n);
	for (auto &i : a)
		cin >> i.second >> i.first;
	sort(a.begin(), a.end(), cmp);
	vector<pair <int, int> > help;
	help.push_back(a[0]);
	for (int i = 1; i < n; i++) {
		if ((help.back()).second < a[i].second && a[i].first < s)
			help.push_back(a[i]);
	}
	a = help;
}

const int INF = -1e18;

struct line{
	int k, b;
	line(){
		k = 0, b = INF;
	}
	line(int x, int y){
		k = x, b = y;
	}
};

int eval(line l, int x) {
	return l.k * x + l.b;
}

double cross(line a, line b) {
	return (double) (b.b - a.b) / (a.k - b.k);
}

struct cht {
	vector<double> p;
	vector<line> l;
	cht() {
		p = {};
		l = {};
	}
	void upd(line x) {
		while (!p.empty() && p.back() >= cross(x, l.back()))
			p.pop_back(), l.pop_back();
		l.push_back(x);
		if (l.size() >= 2)
			p.push_back(cross(l[l.size() - 1], l[l.size() - 2]));
	}

	int get(int x) {
		int pos = lower_bound(p.begin(), p.end(), x) - p.begin();
		return eval(l[pos], x);
	}
};

cht help;

int fin(int x) {
	int l = -1, r = 1e9;
	while (l < r - 1) {
		int mid = (l + r) / 2;
		int have = help.get(mid);
		if (have >= x)
			r = mid;
		else
			l = mid;
	}
	return r;
}

int ans = 1e18;

void relax(int k, int b) {
	ans = min(ans, (s - b + k - 1) / k);
}

void run() {
	int n = a.size();
	help.upd(line(a[0].second, 0));
	relax(a[0].second, 0);
	for (int i = 1; i < n; i++) {
		int k = a[i].second;
		int f = fin(a[i].first);
		int b = -a[i].second * f + help.get(f) - a[i].first;
		help.upd(line(k, b));
		relax(k, b);
	}
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