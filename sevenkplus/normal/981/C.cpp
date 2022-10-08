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
int d[N];
vector<int> A[N];
int c[N];
int n;

bool chk(int x) {
	bool F = true;
	c[d[x]] --;
	for (auto i : A[x]) {
		c[d[i]] --;
		d[i] --;
		c[d[i]] ++;
		if (d[i] >= 2) F = false;
	}
	if (c[0] + c[1] + c[2] != n-1) F = false;
	c[d[x]] ++;
	for (auto i : A[x]) {
		c[d[i]] --;
		d[i] ++;
		c[d[i]] ++;
	}
	return F;
}

int main() {
	cin >> n;
	for (int i = 0; i < n-1; i ++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		d[x] ++; d[y] ++;
		A[x].pb(y); A[y].pb(x);
	}
	for (int i = 0; i < n; i ++) c[d[i]] ++;
	int S = -1;
	for (int i = 0; i < n; i ++)
		if (chk(i)) {
			S = i;
			break;
		}
	if (S == -1) {
		puts ("No");
	} else {
		puts ("Yes");
		int s = c[1];
		if (d[S] == 1) s--;
		printf ("%d\n", s);
		for (int i = 0; i < n; i ++)
			if (d[i] == 1 && i != S)
				printf ("%d %d\n", S+1, i+1);
	}
	return 0;
}