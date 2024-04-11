#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

struct point{
	int x, y;
	point() {}
	point(int a, int b) {
		x = a, y = b;
	}
};

int n;
vector<point> a;
void read() {
	cin >> n;
	a.resize(n);
	for (auto &i : a) {
		cin >> i.x >> i.y;
		i.x += 1e8, i.y += 1e8;
	}
}

void write(vector<int> l) {
	cout << l.size() << "\n";
	for (auto i : l)
		cout << i + 1 << " ";
	cout << "\n";
	exit(0);
}

void run() {
	while (true) {
		vector<int> ans;
		for (int i = 0; i < n; i++) {
			if ((a[i].x + a[i].y) % 2 == 0) 
				ans.push_back(i);
		}
		if (!ans.empty() && ans.size() < n)
			write(ans);
		if (ans.size() == n) {
			if (a[0].x % 2) {
				for (auto &i : a)
					i.x--, i.y--;
			}
		}
		int x = 1LL << 62;
		for (auto i : a)
			x = __gcd(i.x, x), x = __gcd(i.y, x);
		for (auto &i : a) {
			i.x /= x;
			i.y /= x;
		}
		ans.clear();
		for (int i = 0; i < n; i++) {
			if ((a[i].x + a[i].y) % 2 == 0) 
				ans.push_back(i);
		}
		if (!ans.empty() && ans.size() < n)
			write(ans);
		
		vector<int> l, r;
		for (int i = 0; i < n; i++) {
			if (a[i].x % 2) l.push_back(i);
			else r.push_back(i);
		}
		if (!l.empty() && !r.empty())
			write(l);
		if (!l.empty())
			for (auto &i : a)
				i.y--;
		else
			for (auto &i : a)
				i.x--;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	return 0;
}