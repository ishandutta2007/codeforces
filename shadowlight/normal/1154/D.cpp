#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("D.in", "r", stdin);
	//freopen("D.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n, b, a;
	cin >> n >> a >> b;
	int na = a, nb = b;
	for (int i = 0; i < n; i++) {
		int s;
		cin >> s;
		if (s) {
			if (na && nb != b) {
				na--;
				nb++;
			} else {
				if (!nb) {
					cout << i << "\n";
					return 0;
				}
				nb--;
			}
		} else {
			if (nb) {
				nb--;
			} else {
				if (!na) {
					cout << i << "\n";
					return 0;
				}
				na--;
			}
		}
		//cout << i << " " << na << " " << nb << "\n";
	}
	cout << n << "\n";
}