#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 100010
int n, a[N];

int main() {
	int _;
	cin >> _;
	while (_--) {
		cin >> n;
		for (int i = 0; i < n; i ++) cin >> a[i];
		bool F = false;
		for (int t = 30; t >= 0; t--) {
			// S = num 1
			// T = num 0
			int S = 0, T = 0;
			for (int i = 0; i < n; i ++)
				if ((a[i]>>t)&1) S++; else T++;
			if (S%2 == 0) continue;
			F = true;

			if (T%2 == 0) {
				if (S%4 == 3) {
					puts ("LOSE");
				} else {
					puts ("WIN");
				}
			} else {
				if (S%4 == 3) {
					puts ("WIN");
				} else {
					puts ("WIN");
				}
			}

			break;
		}
		if (!F) puts ("DRAW");
	}
	return 0;
}