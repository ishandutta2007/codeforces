#include <bits/stdc++.h>
#define ll long long

using namespace std;

int query(int i, int j) {
	cout << "? " << i + 1 << " " << j + 1 << endl;
	int k;
	cin >> k;
	return k;
}

int main() {
	vector <int> a = {4, 8, 15, 16, 23, 42};
	vector <int> p(6);
	iota(p.begin(), p.end(), 0);
	vector <int> q;
	q.push_back(query(0, 1));
	q.push_back(query(2, 3));
	q.push_back(query(0, 4));
	q.push_back(query(2, 4));
	do {
		if (a[p[0]] * a[p[1]] != q[0]) continue;
		if (a[p[2]] * a[p[3]] != q[1]) continue;
		if (a[p[0]] * a[p[4]] != q[2]) continue;
		if (a[p[2]] * a[p[4]] != q[3]) continue;
		cout << "! ";
		for (int i = 0; i < 6; i++) {
			cout << a[p[i]] << " ";
		}
		cout << endl;
		return 0;
	} while (next_permutation(p.begin(), p.end()));
}