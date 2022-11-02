#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;
#define int long long
#define pb push_back
template <typename T1, typename T2> void chkmin(T1 & x, const T2 & y) {if (y > x) x = y;}
template <typename T1, typename T2> void chkmax(T1 & x, const T2 & y) {if (y < x) x = y;}
int n, m;
void read() {
	cin >> n >> m;
}	

vector<pair <int, int> > ans;

void run() {
	deque <pair <int, int> > help;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			help.push_back({i, j});
		}
	}
	int cnt = 0;
	while (!help.empty()) {
		if (cnt % 2 == 0) {
			ans.push_back(help[0]);
			help.pop_front();
		}
		else {
			ans.push_back(help.back());
			help.pop_back();
		}
		cnt++;	
	}
}

void write() {
	for (auto i : ans)
		cout << i.first << " " << i.second << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	read();
	run();
	write();
	return 0;
}