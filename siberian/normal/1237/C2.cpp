#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

struct event{
	int x, y, z, ind;
};

int n;
vector<event> a;

void read() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, z, ind;
		cin >> x >> y >> z;
		ind = i;
		a.push_back({x, y, z, ind});
	}
} 

bool operator<(const event & a, const event & b) {
	return tie(a.x, a.y, a.z, a.ind) < tie(b.x, b.y, b.z, b.ind);
}

vector<pair<int, int> > ans;

vector<event> solve_z(vector<event> & a) {
	int n = a.size();
	for (int i = 0; i + 1 < n; i += 2) {
		ans.push_back({a[i].ind, a[i + 1].ind});
	}
	if (n % 2)
		return {a[n - 1]};
	else 
		return {};
}

vector<event> solve_y(vector<event> & a) {
	int n = a.size();
	vector<event> b;
	for (int i = 0; i < n; i++) {
		int j = i;
		vector<event> help;
		while (j < n && a[i].y == a[j].y){
			help.push_back(a[j]);
			j++;
		}
		help = solve_z(help);
		for (auto &x : help)
			b.push_back(x);
		i = j - 1;
	}
	n = b.size();
	for (int i = 0; i + 1 < n; i += 2) {
		ans.push_back({b[i].ind, b[i + 1].ind});
	}
	if (n % 2)
		return {b[n - 1]};
	else
		return {};
}

void solve_x(vector<event> & a) {
	int n = a.size();
	vector<event> b;
	for (int i = 0; i < n; i++) {
		int j = i;
		vector<event> help;
		while (j < n && a[i].x == a[j].x){
			help.push_back(a[j]);
			j++;
		}
		help = solve_y(help);
		for (auto &x : help)
			b.push_back(x);
		i = j - 1;
	}
	n = b.size();
	for (int i = 0; i < n; i += 2) {
		ans.push_back({b[i].ind, b[i + 1].ind});
	}
}

void run() {
	sort(a.begin(), a.end());
	solve_x(a);
}

void write() {
	for (auto i : ans)
		cout << i.first + 1 << " " << i.second + 1 << endl;
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