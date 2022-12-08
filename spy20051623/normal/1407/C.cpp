#include <bits/stdc++.h>

using namespace std;

int ask(int x, int y) {
	cout << "? " << x << ' ' << y << endl;
	int z;
	cin >> z;
	return z;
}

int a[10005];

int main() {
//#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
//#endif
	int n;
	cin >> n;
	set<int> s;
	for (int i = 1; i <= n; ++i) s.insert(i);
	int p = 1;
	for (int i = 2; i <= n; ++i) {
		int x = ask(p, i);
		int y = ask(i, p);
		if (x > y) {
			a[p] = x;
			p = i;
			s.erase(x);
		} else {
			a[i] = y;
			s.erase(y);
		}
	}
	a[p] = *s.begin();
	cout << "! ";
	for (int i = 1; i <= n; ++i) {
		cout << a[i] << ' ';
	}
	cout << endl;
	return 0;
}