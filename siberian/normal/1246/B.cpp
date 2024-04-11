#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n, k;
vector<int> a;
void read() {
	cin >> n >> k;
	a.resize(n);
	for (auto &i : a)
		cin >> i;
}

vector<pair <int, int> > get(int x) {
	vector<pair<int, int> > ans;
	for (int i = 2; i * i <= x; i++) {
		int cnt = 0;
		while (x % i == 0) {
			x /= i;
			cnt++;
		}
		cnt %= k;
		if (cnt > 0) {
			ans.push_back({i, cnt});
		}
	}
	if (x != 1) {
		ans.push_back({x, 1});
	}
	sort(ans.begin(), ans.end());
	return ans;
}

vector<pair<int, int> > get_rev(vector<pair<int, int> > x) {
	for (auto &i : x)
		i.second = k - i.second;
	return x;
}

int ans1, ans2;

void run() {
	map<vector<pair<int, int> > , int> have;
	ans1 = ans2 = 0;
	for (auto i : a)
		have[get(i)]++;
	/*cout << "have = " << endl;
	for (auto i : have) {
		cout << "x = " << endl;
		for (auto j : i.first) {
			cout << j.first << " " << j.second << endl;
		}
		cout << i.second << endl;
		cout << endl;
	}*/
	for (auto i : have) {
		auto x = get_rev(i.first);
		if (x == i.first) {
			ans2 += i.second * (i.second - 1) / 2;
		}
		else {
			ans1 += i.second * have[x];
		}
	}
}

void write() {
	cout << ans1 / 2 + ans2 << endl;
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