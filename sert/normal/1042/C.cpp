#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false, E = false;

int a[N];

bool cmp(int x, int y) {
	return abs(a[x]) < abs(a[y]);
}

void print(vector<bool> u) {
	int nx = 0, st = 0;
	int n = u.size();
	while (nx < n && u[nx]) nx++;

	while (nx < n) {
		st = nx;
		nx++;
		while (nx < n && u[nx]) nx++;
		if (nx == n) return;

		printf("1 %d %d\n", st + 1, nx + 1);
	}
}

void solve() {	
	int n;
	scanf("%d", &n);
	vector<int> pos, neg, zer;
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		if (a[i] > 0) pos.push_back(i);
		else if (a[i] < 0) neg.push_back(i);
		else zer.push_back(i);
	}	
	sort(neg.begin(), neg.end(), cmp);
	sort(pos.begin(), pos.end(), cmp);

	vector<bool> u(n, false);
	for (int i = (int)zer.size() - 2; i >= 0; i--) {
		u[zer[i + 1]] = true;
		printf("1 %d %d\n", zer[i + 1] + 1, zer[i] + 1);
	}

	if ((int)neg.size() % 2 == 1 && !zer.empty() && (int)zer.size() + 1 < n) {
		u[neg[0]] = u[zer[0]] = true;
		printf("1 %d %d\n", neg[0] + 1, zer[0] + 1);
		printf("2 %d\n", zer[0] + 1);
		print(u);
		return;
	}

	if ((int)neg.size() % 2 == 1) {
		u[neg[0]] = true;
		printf("2 %d\n", neg[0] + 1);
		print(u);
		return;
	}

	if (!zer.empty() && (int)zer.size() < n) {
		u[zer[0]] = true;
		printf("2 %d\n", zer[0] + 1);
		print(u);
		return;
	}

	print(u);
}

int main() {
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 8;
	while (tst--) {
		solve();
		printf("\n");
	}
#else
	while (tst--) solve();
#endif
}