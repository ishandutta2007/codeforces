#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 1e3 + 10;
bool used[MAXN];
int n;
int Q = 10000;
void query(vector<int> have) {
	Q--;
	assert(Q >= 0);
	cout << have.size();
	for (auto i : have) {
		used[i] = true;
		cout << " " << i + 1;
	}
	cout << endl;
	int x;
	cin >> x;
	x--;
	for (int i = 0; i < (int)have.size(); i++) {
		used[(x + i) % n] = false;
	}
}

int calc(int n, int x) {
	return n - n / x - (int)(n % x != 0) - (x - 1);
}
	
int findBest(int n) {
	int ans = 2;
	for (int x = 2; x < n; x++) {
		if (calc(n, x) > calc(n, ans)) {
			ans = x;
		}
	}
	return ans;
}

void outAns() {
	int have = 0;
	for (int i = 0; i < n; i++) {
		have += used[i];
	}
	assert(have >= calc(n, findBest(n)));
	cout << 0 << endl;
	exit(0);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	if (n <= 3) outAns();
	int x = findBest(n);
	vector<int> need;
	for (int i = 0; i < n - 1; i++) {
		if ((i + 1) % x == 0) continue;
		need.push_back(i);
	}
	/*cerr << "x = " << x << endl;
	cerr << "need = ";
	for (auto i : need) cerr << i << " ";
	cerr << endl;*/
	while (true) {
		vector<int> have;
		for (auto i : need) {
			if (!used[i]) {
				have.push_back(i);
				if ((int)have.size() == x) {
					break;
				}
			}
		}
		if (have.size() < x) outAns();
		query(have);
	}
	return 0;
}