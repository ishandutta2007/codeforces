#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

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

const int maxn = 300010;

vector<int> c;
int n, m, p, a[maxn], b[maxn], cur[maxn], cb[maxn], jj[maxn], kj;

int main() {
	scanf("%d %d %d", &n, &m, &p);
	forn(i, n) scanf("%d", &a[i]), c.pb(a[i]);
	forn(i, m) scanf("%d", &b[i]), c.pb(b[i]);

	vector<int> rc = compress(c);
	forn(i, n) a[i] = c[i];
	forn(i, m) b[i] = c[i+n];

	forn(i, m) cb[ b[i] ]++;
	int cnz = 0;
	forn(i, rc.size())
		if (cb[i]) cnz++;

	ll p1 = (ll)p * m;
	ll p2 = (ll)p * (m - 1);
	vector<int> ans;
	for (int i = 0; i < min(n, p); i++) {
		int curnz = 0;
		kj = 0;
		for (int j = i; j < n; j += p) {
			if (cur[ a[j] ] == cb[ a[j] ]) curnz--;
			++cur[a[j]];
			if (cur[ a[j] ] == cb[ a[j] ]) curnz++;

			jj[kj++] = j;

			if (j >= p1) {
				if (cur[ a[j - p1] ] == cb[ a[j - p1] ]) curnz--;
				--cur[a[j - p1]];
				if (cur[ a[j - p1] ] == cb[ a[j - p1] ]) curnz++;
			}
			if (j >= p2)
				if (curnz == cnz) {
					ans.pb(j - p2);
				}
		}
		for (int q = kj - 1; q >= 0 && jj[q] + p1 >= n; q--)
			cur[a[jj[q]]]--;
	}

	sort(ans.begin(), ans.end());
	printf("%d\n", int(ans.size()));
	forn(i, ans.size()) {
		if (i) printf(" ");
		printf("%d", ans[i] + 1);
	}
	printf("\n");

	return 0;
}