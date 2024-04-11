#include <bits/stdc++.h>

using namespace std;
#define int long long
int n, m;
vector<pair <int, int> > a;
void read() {
	cin >> n >> m;
	a.resize(n);
	for (auto &i : a)
		cin >> i.first >> i.second;

}

const int MAXN = 5 * 1e5 + 10, MAXLOG = 20;
int jump[MAXN][MAXLOG];

bool cmp(pair <int, int> a, pair <int, int> b) {
	return a.first < b.first || (a.first == b.first && a.second > b.second);
}

vector <int> ans;
void run() {
	sort(a.begin(), a.end(), cmp);
	vector<pair <int, int> > help;
	int mx_r = -1;
	for (int i = 0; i < n; i++) {
		if (a[i].second > mx_r) {
			help.push_back(a[i]);
			mx_r = a[i].second;
		}
	}
	a = help;
	n = a.size();
	unordered_map <int, vector<int>> r, l;

	for (auto i : a) {
		l[i.first].push_back(i.second);
		r[i.second].push_back(i.second);
	}

	multiset <int> have;
	for (int i = 0; i < MAXN; i++) {
		for (auto j : l[i])
			have.insert(j);
		if (have.size())
			jump[i][0] = *(--have.end());
		else
			jump[i][0] = i;
		for (auto j : r[i])
			have.erase(have.find(j));
	}

	for (int j = 1; j < MAXLOG; j++)
		for (int i = 0; i < MAXN; i++)
			jump[i][j] = jump[jump[i][j - 1]][j - 1];



	for (int test = 0; test < m; test++) {
		int x, y;
		cin >> x >> y;
		int fans = 0;
		for (int j = MAXLOG - 1; j >= 0; j--){
			if (jump[x][j] < y){
				x = jump[x][j];
				fans += 1 << j;
			}
		}
		if (jump[x][0] >= y) {
			fans++;
			ans.push_back(fans);
		}
		else {
			ans.push_back(-1);
		}
	}
}

void write() {
	for (auto i : ans)
		cout << i << "\n";
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