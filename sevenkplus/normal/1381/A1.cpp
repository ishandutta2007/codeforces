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

string a, b;
int n;
vector<int> S;

int main() {
	int _;
	cin >> _;
	while (_--) {
		cin >> n >> a >> b;
		S.clear();
		int l = 0, r = n-1;
		for (int i = 0; i < n; i ++) {
			char c;
			if (i&1) {
				c = a[r]^1;
				r--;
			} else {
				c = a[l];
				l++;
			}
			if (c == b[n-i-1]) {
				S.pb(1);
				S.pb(n-i);
			} else {
				S.pb(n-i);
			}
		}
		printf("%d", (int) S.size());
		for (auto i : S) printf(" %d", i);
		puts("");
	}
	return 0;
}