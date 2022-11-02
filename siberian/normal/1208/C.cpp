#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 1e3 + 10;
bool used[MAXN * MAXN];

int n;

void read() {
	cin >> n;
}

vector<vector<int> > ans;

bool check() {
	set<int> xors;
	for (int i = 0; i < n; i++) {
		int x = 0;
		for (int j = 0; j < n; j++)
			x ^= ans[i][j];
		xors.insert(x);
	}

	for (int j = 0; j < n; j++) {
		int x = 0;
		for (int i = 0; i < n; i++)
			x ^= ans[i][j];
		xors.insert(x);
	}
	return xors.size() == 1;
}

void run() {
	ans.assign(n, vector<int> (n, 0));
	vector<int> num;
	for (int i = 0; i < n * n; i++)
		num.push_back(i);
	reverse(num.begin(), num.end());
	for (int s = 0; s < n; s += 4) {
		for (int i = 0; i < n; i++) {
			for (int j = s; j < s + 4; j++) {
				ans[i][j] = num.back();
				num.pop_back();
			}
		}
	}
	assert(check());
}

void write() {
	for (auto i : ans) {
		for (auto j : i)
			cout << j << " ";
		cout << "\n";
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	
	//for (n = 4; n <= 1000; n += 4)
	//	run();
	
	return 0;
}