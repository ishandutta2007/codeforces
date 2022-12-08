#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x;
	cin >> x;
	int h, m;
	cin >> h >> m;
	int ct = 0;
	while (1) {
		if (m % 10 == 7 || m/10 == 7 || h%10 == 7) {
			cout << ct << endl;
			break;
		}
		ct++;
		m -= x;
		if (m < 0) {
			m+= 60;
			h--;
			if (h < 0) h = 23;
		}
		
	}
	cin >> x;
}