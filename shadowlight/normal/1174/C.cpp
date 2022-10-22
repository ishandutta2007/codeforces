#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("C.in", "r", stdin);
	//freopen("C.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <int> a(n + 1, 0);
	int last = 0;
	for (int i = 2; i <= n; i++) {
		if (a[i] > 0) continue;
		last++;
		for (int j = i; j <= n; j += i) {
			if (!a[j]) {
				a[j] = last;
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		cout << a[i] << " ";
	}
}