#include <bits/stdc++.h>
using namespace std;
vector<int> a, b;

bool ok(int x, int f) {
	if (f == 1) {
		if (a.size() == 0 || a[a.size() - 1] != x)
			return true;
		else
			return false;
	} else {
		if (b.size() == 0 || b[b.size() - 1] != x)
			return true;
		else
			return false;
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n, temp = 0, in, ok1, ok2;
	cin >> n;
	while (n--) {
		cin >> in;
		if (temp == 0) {
			ok1 = ok(in, 1);
			ok2 = ok(in, 2);
			if (ok1 && ok2)
				temp = in;
			if (ok1 && !ok2)
				a.push_back(in);
			if (!ok1 && ok2)
				b.push_back(in);
		} else if (in == temp) {
			a.push_back(in);
			b.push_back(in);
			temp = 0;
		} else {
			ok1 = ok(in, 1);
			ok2 = ok(in, 2);
			if (!ok1) {
				if (!ok2) {
					a.push_back(temp);
					a.push_back(in);
					temp = 0;
				} else {
					a.push_back(temp);
					temp = in;
				}
			} else {
				b.push_back(temp);
				temp = in;
			}
		}
	}
	if (temp)
		a.push_back(temp);
	cout << a.size() + b.size() << endl;
	return 0;
}