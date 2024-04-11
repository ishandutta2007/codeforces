#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int maxn = 100010;

int n;
ll k;
int s[100010], inv[100010];

void modify(int x, int d) {
	for (x++; x <= n + 2; x += -x&x) {
		s[x] += d;
	}
}

int get(int x) {
	int res = 0;
	// printf("get %d = ", x);
	for (x++; x > 0; x &= x-1) {
		res += s[x];
	}
	// printf("%d\n", res);
	return res;
}

int getsum(int L, int R) {
	if (L > R) return 0;
	int res = get(R) - get(L-1);
	// printf("getsum %d %d -> %d\n", L, R, res);
	return res;
}

vector<int> compress(vector<int>& a) {
	vector< pair<int, int> > ev(a.size());
	for (int i = 0; i < (int)a.size(); i++)
		ev[i] = make_pair(a[i], i);
	sort(ev.begin(), ev.end());

	vector<int> real;
	for (int i = 0; i < (int)ev.size(); i++) {
		if (i == 0 || ev[i].first != ev[i-1].first)
			real.push_back(ev[i].first);

		a[ev[i].second] = real.size() - 1;
	}

	return real;
}

int main() {
	cin >> n >> k;
	vector<int> a(n);
	forn(i, n) scanf("%d", &a[i]);
	compress(a);

	forn(i, n) {
		inv[i] += getsum(a[i]+1, n);
		modify(a[i], +1);
	}

	memset(s, 0, sizeof(s));

	for (int i = n-1; i>=0; i--) {
		inv[i] += getsum(0, a[i]-1);
		modify(a[i], +1);
	}

	ll total = 0;
	forn(i, n) total += inv[i];
	total >>= 1;

	// forn(i, n) printf(" %d", inv[i]); printf("\n");

	ll ans = 0;
	int R = 0;
	memset(s, 0, sizeof(s));

	forn(L, n) {
		if (R < L) R = L;
		while (R < n && (total > k)) {
			total -= inv[R];
			total += getsum(a[R]+1, n);
			modify(a[R], +1);
			R++;
		}
		if (L) ans += n - R;
		if (R > L) {
			total += inv[L];
			total -= getsum(0, a[L]-1);
		}
		modify(a[L], -1);
	}

	cout << ans << endl;

    return 0;
}