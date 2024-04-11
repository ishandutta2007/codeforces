#include <bits/stdc++.h>

using namespace std;
#define int long long

struct rect{
	int l, r, u, d;
	rect() {
		l = 0, r = 0, u = 0, d = 0;
	}
	rect(int a, int b, int c, int d1) {
		l = a, r = b, u = c, d = d1;
	}
};

int n;
vector<pair<rect, int>> a;
void read() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		rect help;
		int a1, b1, c1, d1;
		cin >> a1 >> b1 >> c1 >> d1;
		help.l = a1;
		help.d = b1;
		help.r = c1;
		help.u = d1;
		a.push_back({help, i});	
	} 
}

bool cmp_l(pair <rect, int> a, pair <rect, int> b) {
	return a.first.l > b.first.l;
}

bool cmp_r(pair <rect, int> a, pair <rect, int> b) {
	return a.first.r < b.first.r;
}

bool cmp_d(pair <rect, int> a, pair <rect, int> b) {
	return a.first.d > b.first.d;
}

bool cmp_u(pair <rect, int> a, pair <rect, int> b) {
	return a.first.u < b.first.u;
}

vector<bool> used;

bool check_l(vector<pair <rect, int> > &st1, vector<pair <rect, int> > &st2, int & maxR) {
	while (!st1.empty() && used[st1.back().second])
		st1.pop_back();
	if (st1.empty()) return false;
	st2.push_back(st1.back());
	st1.pop_back();
	while (!st1.empty() && used[st1.back().second])
		st1.pop_back();
	if (st1.empty()) return false;
	maxR = max(maxR, st2.back().first.r);
	return maxR <= st1.back().first.l;
}

bool check_r(vector<pair <rect, int> > &st1, vector<pair <rect, int> > &st2, int & minL) {
	while (!st1.empty() && used[st1.back().second])
		st1.pop_back();
	if (st1.empty()) return false;
	st2.push_back(st1.back());
	st1.pop_back();
	while (!st1.empty() && used[st1.back().second])
		st1.pop_back();
	if (st1.empty()) return false;
	minL = min(minL, st2.back().first.l);
	return minL >= st1.back().first.r;
}

bool check_d(vector<pair <rect, int> > &st1, vector<pair <rect, int> > &st2, int & maxU) {
	while (!st1.empty() && used[st1.back().second])
		st1.pop_back();
	if (st1.empty()) return false;
	st2.push_back(st1.back());
	st1.pop_back();
	while (!st1.empty() && used[st1.back().second])
		st1.pop_back();
	if (st1.empty()) return false;
	maxU = max(maxU, st2.back().first.u);
	return maxU <= st1.back().first.d;
}

bool check_u(vector<pair <rect, int> > &st1, vector<pair <rect, int> > &st2, int & minD) {
	while (!st1.empty() && used[st1.back().second])
		st1.pop_back();
	if (st1.empty()) return false;
	st2.push_back(st1.back());
	st1.pop_back();
	while (!st1.empty() && used[st1.back().second])
		st1.pop_back();
	if (st1.empty()) return false;
	minD = min(minD, st2.back().first.d);
	return minD >= st1.back().first.u;
}

void make(vector<pair <rect, int> > & st) {
	for (auto i : st)
		used[i.second] = true;
} 

void make(vector<pair <rect, int> > & st2, int & cnt) {
	for (auto i : st2){
		if (!used[i.second]) 
			cnt--;
	}
}

void make(vector<pair <rect, int> > & st1, vector<pair <rect, int> > & st2) {
	while (!st2.empty()) {
		st1.push_back(st2.back());
		st2.pop_back();
	}
}

bool solve(vector<pair<rect, int> > a) {
	int cnt = 0;
	
	vector<pair <rect, int> > st1[4], st2[4];
	for (auto i : a) {
		if (!used[i.second]) {
			cnt++;
			st1[0].push_back(i);
			st1[1].push_back(i);
			st1[2].push_back(i);
			st1[3].push_back(i);
		}
	}

	sort(st1[0].begin(), st1[0].end(), cmp_l);
	sort(st1[1].begin(), st1[1].end(), cmp_r);
	sort(st1[2].begin(), st1[2].end(), cmp_d);
	sort(st1[3].begin(), st1[3].end(), cmp_u);
	int maxR, minL, maxU, minD;

	maxR = -1e18;
	minL = 1e18;
	maxU = -1e18;
	minD = 1e18;

	while (cnt > 3) {
		if (st1[0].empty() && st1[1].empty() && st1[2].empty() && st1[3].empty()) 
			return false;
		
		if (check_l(st1[0], st2[0], maxR)) {
			make(st2[0], cnt);
			if (!solve(st2[0])) 
				return false;
			make(st2[0]);	
			for (int i = 0; i < 4; i++)
				make(st1[i], st2[i]);
			maxR = -1e18;
			minL = 1e18;
			maxU = -1e18;
			minD = 1e18;
			continue;
		}
		if (check_r(st1[1], st2[1], minL)) {
			make(st2[1], cnt);
			if (!solve(st2[1])) 
				return false;
			make(st2[1]);
			for (int i = 0; i < 4; i++)
				make(st1[i], st2[i]);
			maxR = -1e18;
			minL = 1e18;
			maxU = -1e18;
			minD = 1e18;
			continue;
		}
		if (check_d(st1[2], st2[2], maxU)) {
			make(st2[2], cnt);
			if (!solve(st2[2])) 
				return false;
			make(st2[2]);
			for (int i = 0; i < 4; i++)
				make(st1[i], st2[i]);	
			maxR = -1e18;
			minL = 1e18;
			maxU = -1e18;
			minD = 1e18;
			continue;
		}
		if (check_u(st1[3], st2[3], minD)) {
			make(st2[3], cnt);
			if (!solve(st2[3])) 
				return false;
			make(st2[3]);
			for (int i = 0; i < 4; i++)
				make(st1[i], st2[i]);		
			maxR = -1e18;
			minL = 1e18;
			maxU = -1e18;
			minD = 1e18;
			continue;
		}
	}
	return true;
}

string ans;

void run() {
	used.assign(n, false);
	if (solve(a)) {
		ans = "YES";
	}
	else {
		ans = "NO";
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