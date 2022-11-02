#include <bits/stdc++.h>

using namespace std;
#define int long long

int l(int a, int b) {
	return a * b / __gcd(a, b);
}

int mid_x(int a, int k) {
	return ((a + k - 1) / k) * k - a;
}

void read() {
	int a, b;
	cin >> a >> b;
	int diff = abs(a - b);
	int k = 0;
	int ans = l(a, b);
//	cout << ans << endl;
	for (int i = 1; i * i <= diff; i++) {
		if (diff % i == 0) {
			int m = mid_x(a, i);
			int a1 = a + m;
			int b1 = b + m;
			int fans = l(a1, b1);
	//		cout << "i = " << i <<  " m = " << m << " a1 = " << a1 << " b1 = " << b1 << " fans = " << fans << endl;
			if (fans < ans) {
				ans = fans;
				k = m;
			} 
			m = mid_x(a, diff / i);
			a1 = a + m;
			b1 = b + m;
			fans = l(a1, b1);
	//		cout << "diff / i = " << diff / i << " m = " << m << " a1 = " << a1 << " b1 = " << b1 << " fans = " << fans << endl;
			
			if (fans < ans) {
				ans = fans;
				k = m;
			}
		}
	}	
	cout << k << endl;
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