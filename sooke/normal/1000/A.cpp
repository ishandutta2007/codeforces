#include <cstdio>
#include <iostream>
#include <algorithm>
#define Maxn 101

using namespace std;

string a[Maxn], b[Maxn];
int n, ans = 0;
bool used[Maxn], suc[Maxn];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!used[j] && b[i] == a[j]) {
				used[j] = true;
				suc[i] = true;
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		ans += suc[i];
	}
	cout << n - ans << endl;
	return 0;
}

// By Sooke.
// CF1000A Codehorses T-shirts.