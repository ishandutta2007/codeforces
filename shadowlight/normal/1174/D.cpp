#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("D.in", "r", stdin);
	//freopen("D.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n, x;
	cin >> n >> x;
	set <int> q;
	for (int i = 1; i < (1 << n); i++) {
		q.insert(i);
	}
	q.erase(x);
	vector <int> a;
	int t = 0;
	while (!q.empty()) {
		int v = *q.begin();
		a.push_back(v ^ t);
		q.erase(v);
		q.erase(v ^ x);
		t = v;
	}
	cout << a.size() << "\n";
	for (int x : a) {
		cout << x << " ";
	}
}