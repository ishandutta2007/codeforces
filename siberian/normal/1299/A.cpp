#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n;
vector<int> a;
void read() {
	cin >> n;
	a.resize(n);
	for (auto &i : a)
		cin >> i;
}

vector<int> solve(vector<int> a) {
	map<int, vector<int> > cnt;
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < 31; j++) {
			if ((a[i] >> j) & 1) {
				cnt[j].push_back(i);
			}
		}
	}
	int best = 0, ans = 0;
	for (int i = 0; i < a.size(); i++) {
		int fans = 0;
		for (int j = 0; j < 31; j++) {
			if ((a[i] >> j) & 1) {
				if (cnt[j].size() == 1)
					fans += (1 << j);
			}
		}
		if (fans > ans) {
			best = i;
			ans = fans;
		}
	}
	vector<int> A;
	A.push_back(a[best]);
	for (int i = 0; i < a.size(); i++) {
		if (i == best) continue;
		A.push_back(a[i]);
	}
	return A;
}


void run() {
	a = solve(a);
}

void write() {
	for (auto i : a)
		cout << i << " ";
	cout << endl;
}

int calc(int a, int b) {
	return (a | b) - b;
}

int calc(vector<int> a) {
	int ans = calc(a[0], a[1]);
	for (int i = 2; i < a.size(); i++) {
		ans = calc(ans, a[i]);
	}
	return ans;
}


void stupid() {
	int n = rand() % 5 + 5;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 1000;
	}
	sort(all(a));
	vector<int> ans = a;
	do {
		if (calc(a) > calc(ans))
			ans = a;
	} while (next_permutation(all(a)));
	sort(all(a));
	a = solve(a);
	//reverse(all(a));
	if (calc(ans) > calc(a)) {
		cout << "WA" << endl;
		for (auto i : a)
			cout << i << " ";
		cout << endl;
		cout << calc(a) << endl;
		for (auto i : ans)
			cout << i << " ";
		cout << endl;
		cout << calc(ans) << endl;
		exit(0);
	}
	cout << "OK" << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//while (true) {
	//	stupid();
	//}

	read();
	run();
	write();
	return 0;
}