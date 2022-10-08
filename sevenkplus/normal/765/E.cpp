#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define N 200010
int n;
set<int> A[N];

void out(int x) {
	while (x%2 == 0) x /= 2;
	printf ("%d\n", x);
	exit(0);
}

map<int, vector<int> > B[N];
set<PII> C;

void add(int x, int y, int t) {
	B[x][t].pb(y);
	if ((int) B[x][t].size() == 2) C.insert(mp(t, x));
}

int main() {
	cin >> n;
	for (int i = 0; i < n-1; i ++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		A[x].insert(y);
		A[y].insert(x);
	}
	int now = n-1;
	for (int i = 0; i < n; i ++)
		if ((int) A[i].size() == 1) {
			int x = *A[i].begin(), y = i;
			int t = 1;
			while ((int) A[x].size() == 2) {
				int x1 = *A[x].begin();
				if (x1 == y) x1 = *A[x].rbegin();
				y = x; x = x1;
				t++;
			}
			if ((int) A[x].size() == 1) out(now);
			add(x, y, t);
		}
	while (!C.empty()) {
		PII _x = *C.begin();
		C.erase(C.begin());
		int x = _x.se, t = _x.fi;
		int m = (int) B[x][t].size();
		for (int i = 1; i < m; i ++) {
			now -= t;
			A[x].erase(B[x][t][i]);
		}
		if ((int) A[x].size() == 1) out(now);
		if ((int) A[x].size() > 2) {
			B[x][t].resize(1);
			continue;
		}
		int y = B[x][t][0];
		B[x].erase(B[x].find(t));
		while ((int) A[x].size() == 2) {
			int x1 = *A[x].begin();
			if (x1 == y) x1 = *A[x].rbegin();
			y = x; x = x1;
			t++;
		}
		if ((int) A[x].size() == 1) out(now);
		add(x, y, t);
	}
	puts ("-1");
	return 0;
}