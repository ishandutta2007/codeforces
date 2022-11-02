#include <bits/stdc++.h>

using namespace std;
#define int long long
int n, m;
vector<vector<char> > s;
map<vector<char>, vector<vector<char> > > help1, help2;
void read() {
	cin >> n >> m;
	s.assign(n, vector<char> (m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> s[i][j];
		}
	}
}

void gen() {
	vector<char> lett = {'A', 'T', 'G', 'C'};
	sort(lett.begin(), lett.end());
	do {
		vector<char> h1;
		for (int i = 0; i < m; i++) {
			if (i % 2 == 0)
				h1.push_back(lett[0]);
			else
				h1.push_back(lett[1]);
		}
		
		vector<char> h2;
		for (int i = 0; i < m; i++) {
			if (i % 2 == 0)
				h2.push_back(lett[2]);
			else
				h2.push_back(lett[3]);
		}
		help1[h1].push_back(h2);

		h1.clear();
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0)
				h1.push_back(lett[0]);
			else
				h1.push_back(lett[1]);
		}
		
		h2.clear();
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0)
				h2.push_back(lett[2]);
			else
				h2.push_back(lett[3]);
		}
		help2[h1].push_back(h2);
	} while(next_permutation(lett.begin(), lett.end()));
}

int dist(vector<vector<char>> &a, vector<vector<char> > &b) {
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			ans += a[i][j] != b[i][j];
	return ans;
}

int dist(vector<char> &a, vector<char> &b) {
	int sz = a.size();
	int ans = 0;
	for (int i = 0; i < sz; i++) {
		ans += a[i] != b[i];
	}
	return ans;
}

int fans = 1e9;
vector<vector<char>> ans;


void run() {
	gen();
	for (auto i : help1) {
		vector<vector<char> > for_ans;
		auto start = i.first;
		for_ans.push_back(start);

		for (int j = 1; j < n; j++) {
			int now = 1e9;
			vector<char> fcheck;
			for (auto k: help1[start]) {
				if (dist(k, s[j]) < now) {
					now = dist(k, s[j]);
					fcheck = k;
				}
			}
			start = fcheck;
			for_ans.push_back(start);
		}
		if (fans > dist(s, for_ans)) {
			fans = dist(s, for_ans);
			ans = for_ans;
		}
	}

	for (auto i : help2) {
		vector<vector<char> > for_ans(n, vector<char> (m));
		auto start = i.first;
		for (int j = 0; j < n; j++)
			for_ans[j][0] = start[j];

		for (int j = 1; j < m; j++) {
			int now = 1e9;
			vector<char> fcheck;
			vector<char> from_s;
			for (int k = 0; k < n; k++)
				from_s.push_back(s[k][j]);
			for (auto k : help2[start]) {
				if (dist(k, from_s) < now) {
					now = dist(k, from_s);
					fcheck = k;
				}
			}
			start = fcheck;
			for (int k = 0; k < n; k++)
				for_ans[k][j] = start[k];
		}

		if (fans > dist(s, for_ans)) {
			fans = dist(s, for_ans);
			ans = for_ans;
		}
	}

}

void write() {
	for (auto i : ans) {
		for (auto j : i)
			cout << j;
		cout << '\n';
	}
	//cout << "dist = " << dist(ans, s) << endl;
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