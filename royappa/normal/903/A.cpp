#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		bool can = false;
		for (int a = 0; a <= 100; a++) {
			for (int b = 0; b <= 100; b++) {
				if (a*3+b*7 == x) {
					can = true; break;
				}
			}
		}
		cout << (can ? "YES" : "NO") << endl;
	}
	exit(0);
}