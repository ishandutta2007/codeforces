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
int n, m;
int a[N];

int lo = N;

bool po = true;
int q[N], L;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i ++) cin >> a[i];
	while (m--) {
		string s; int x;
		cin >> s >> x;
		if (s[0] == '<') x--;
		if (!x) x = -1;

		int xx;
		if (x < 0) xx = abs(x)-1; else xx = abs(x);
		lo = min(lo, xx);
		while (L && q[L-1] >= xx) L--;

		if (po && (1 <= x) || !po && (-1 <= x)) po = !po;
		if (!po ^ (L%2 == 1)) q[L++] = xx;

		if (s[0] == '>') {
			po = !po;
		}
	}

	for (int i = 0; i < n; i ++) {
		auto p = lower_bound(q, q+L, abs(a[i]));
		int S = abs(a[i]);
		if (!po ^ ((p-q)%2 == 1)) S = -S;
		if (a[i] < 0 && abs(a[i]) <= lo) S = -S;
		printf("%d%c", S, i == n-1?'\n':' ');
	}
	return 0;
}