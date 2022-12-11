#include <bits/stdc++.h>
using namespace std;

bool check(int a, int b, int c) {
	cout << "? " << a + 1 << " " << b + 1 << " " << c + 1 << endl; 
	string s;
	cin >> s;
	return (s == "Yes");
}

int main() {
	int n, k;
	cin >> n >> k;
	int a = 1, lst = 1;
	int h = 0;
	while (a < n) {
		lst *= k;
		a += lst;
		h++;
	}

	vector<int> v;
	int v1, v2;
	while (true) {
		v1 = rand() % n;
		v2 = rand() % (n - 1);
		if (v2 >= v1) v2++;

		v.clear();
		for (int i = 0; i < n; i++) {
			if (i != v1 && i != v2 && check(v1, i, v2)) v.push_back(i);
		}

		if ((int)v.size() == 2 * h - 1) break;
	}

	for (int w: v) {
		int num = 0;
		for (int q: v) {
			if (q != w && check(w, q, v2)) num++;
		}
		if (num == h - 1) {
			cout << "! " << w + 1 << endl;
			return 0;
		}
	}
}