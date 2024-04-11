#include <bits/stdc++.h>

using namespace std;
#define int long long

int f(int x) {
	x++;
	while (x % 10 == 0 && x > 0) {
		x /= 10;
	}
	return x;
}

void read() {
	int n;
	cin >> n;
	set <int> help;
	help.insert(n);
	for (int i = 0; i < 1e5 + 10; i++)
	{
		n = f(n);
		help.insert(n);
	}
	cout << help.size() << endl;
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