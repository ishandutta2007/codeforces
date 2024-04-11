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

#define N 1010
int n, a[N], b[N];
int A, B;

int main() {
	cin >> n >> A >> B;
	set<PII> AA, BB;
	for (int i = 0; i < n; i ++) {
		cin >> a[i] >> b[i];
		a[i] = a[i]*A/100;
		AA.insert(mp(-a[i], i));
	}
	int c = A, t = 0, w = 0;
	const int ma = A+n;
	vector<PII> S;
	while (t < ma) {
		c -= w;
		c += B;
		c = min(c, A);
		if (c <= 0) {
			break;
		}
		
		while (!AA.empty() && -AA.begin()->fi >= c) {
			int x = AA.begin()->se;
			AA.erase(AA.begin());
			BB.insert(mp(-b[x], x));
		}

		if (!BB.empty()) {
			int x = BB.begin()->se;
			BB.erase(BB.begin());
			S.pb(mp(t, x));
			w += b[x];
		}

		t++;
	}
	if (t >= ma) {
		puts ("NO");
	} else {
		puts ("YES");
		printf ("%d %d\n", t, (int) S.size());
		for (auto p : S) {
			printf("%d %d\n", p.fi, p.se + 1);
		}
	}
	return 0;
}