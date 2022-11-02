#include <bits/stdc++.h>

using namespace std;
#define int long long
int n;
vector <int> a;
void read() {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += a[i] == a[0];
	if (cnt <= n / 2) {
		cout << "Alice" << endl;
	}
	else {
		cout << "Bob" << endl;
	}
}

void run() {

}

void write() {

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