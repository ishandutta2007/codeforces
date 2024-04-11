#include<bits/stdc++.h>
using namespace std;

int n; 

int gcd(int x, int y) { return y? gcd(y, x % y) : x; }
int Rand() { return (rand() << 15) + rand(); }

int main() {
	srand(time(NULL));
	cin >> n;
	int l = 0, r = 1e9, mx = 0;
	int res = 60;
	while(l <= r) {
		int mid = l + r >> 1, opt;
		cout << "> " << mid << endl, cin >> opt, cout.flush(), res--;
		if(!opt) mx = mid, r = mid - 1;
		else l = mid + 1;
	}
	int diff, pos = Rand() % n + 1;
	cout << "? " << pos << endl, cin >> diff, cout.flush(), res--;
	if(diff == mx) pos = pos % n + 1, cout << "? " << pos << endl, cin >> diff, cout.flush(), res--;
	diff = mx - diff;
	for(int i = 1, x; i <= res; i++) {
		pos = Rand() % n + 1;
		cout << "? " << pos << endl, cin >> x, cout.flush();
		if(x != diff) diff = gcd(diff, mx - x);
	}
	int fir = mx - (n - 1) * diff;
	printf("! %d %d\n", fir, diff);
	return 0;
}