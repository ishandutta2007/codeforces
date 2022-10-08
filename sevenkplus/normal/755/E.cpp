#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int main() {
	int n, k;
	cin >> n >> k;
	if (n == 2) {
		puts ("-1");
		return 0;
	}
	if (n == 3) {
		puts ("-1");
		return 0;
	}
	if (k == 1) {
		puts ("-1");
		return 0;
	}
	if (n == 4) {
		if (k != 3) {
			puts ("-1");
			return 0;
		}
		k = 2;
	}
	if (k == 2) {
		printf ("%d\n", n-1);
		for (int i = 1; i < n; i ++)
			printf ("%d %d\n", i, i+1);
		return 0;
	}
	if (k == 3) {
		vector<PII> A;
		A.pb(mp(1, 2));
		A.pb(mp(2, 3));
		A.pb(mp(3, 4));
		for (int i = 5; i <= n; i ++) {
			A.pb(mp(1, i));
			A.pb(mp(2, i));
		}
		printf ("%d\n", (int) A.size());
		for (int i = 0; i < (int) A.size(); i ++)
			printf ("%d %d\n", A[i].fi, A[i].se);
		return 0;
	}
	puts ("-1");
	return 0;
}