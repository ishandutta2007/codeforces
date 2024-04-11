#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

int n, x;
vector<int> a;
void read() {
	cin >> n >> x;
	a.resize(n);
	for (auto &i : a)
		cin >> i;
}

vector<int> ans;
vector<int> p;
vector<int> m;

void make() {
	p.resize(n);
	iota(all(p), 0);
	m.resize(n);
	iota(all(m), 0);
}

int get_p(int v) {
	if (p[v] == v) return v;
	return p[v] = get_p(p[v]);
}

void uni(int a, int b) {
	a = get_p(a);
	b = get_p(b);
	if (a == b) return;
	p[a] = b;
	chkmax(m[b], m[a]);
}

void run() {
	make();
	vector<int> have(n, 0);
	vector<int> cnt(x, 0);
	for (int i = 0; i < n; i++) {
		/*cout << "have = " << endl;
		for (auto j : have)
			cout << j << " ";
		cout << endl;
		cout << "cnt = " << endl;
		for (auto j : cnt)
			cout << j << " ";
		cout << endl;*/
		cnt[a[i] % x]++;
		
		if (a[i] % x + (cnt[a[i] % x] - 1) * x >= n) {
			if (!have[0]) {
				ans.push_back(0);
				continue;
			}

			ans.push_back(m[get_p(0)] + 1);
			continue;
		}
		int y = a[i] % x + (cnt[a[i] % x] - 1) * x; 
		have[y] = 1;
		//cout << "y = " << y << endl;
		if (y > 0 && have[y - 1]) uni(y, y - 1);
		if (y + 1 < n && have[y + 1]) uni(y, y + 1);

		if (!have[0]) {
			ans.push_back(0); continue;
		}
		ans.push_back(m[get_p(0)] + 1);
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