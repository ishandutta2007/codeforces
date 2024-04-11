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

int eval(line l, int x) {
	return l.k * x + l.b;
}

double cross(line a, line b) {
	return (double) (b.b - a.b) / (a.k - b.k);
}

struct cht{
	vector<line> l;
	vector<double> p;
	cht(){
		l = {};
		p = {};
	}

	void add(line x) {
		while (!p.empty() && cross(l.back(), x) <= p.back())
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

int n;
vector<int> a;
void read() {
	cin >> n;
	a.resize(n);
	for (auto &i : a)
		cin >> i;
}


int ans = 0;
void run() {
	vector<int> pref(n + 1);
	vector<int> pre_ans(n + 1);
	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1] + a[i - 1]; 
		pre_ans[i] = pre_ans[i - 1] + a[i - 1] * i;
		ans = max(ans, pre_ans[i]);
	}

	cht help;

	for (int i = 2; i <= n; i++) {
		help.add(line(i - 1, pref[i - 1] * (i - 1) - pre_ans[i - 1]));
		ans = max(ans, help.get(-pref[i]) + pre_ans[i]);
	}
/*
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= i; j++) {
			ans = max(ans, (j - 1) * (-pref[i]) + pref[j - 1] * (j - 1) - pre_ans[j - 1] + pre_ans[i]);
		}
	}*/
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