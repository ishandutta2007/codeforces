#include <bits/stdc++.h>

using namespace std;
#define int long long
int a, b, c;
void read() {
	cin >> a >> b >> c;
	int x = min(a, b);
	c += x;
	a -= x;
	b -= x;
	a = min(a, 1LL);
	b = min(b, 1LL);
	cout << a + b + c * 2 << endl;
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