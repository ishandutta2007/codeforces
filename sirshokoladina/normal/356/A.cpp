#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <memory.h>
#include <ctime>
#include <cctype>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define all(a) a.begin(), a.end()
#define sqr(a) ((a) * (a))

typedef long double ld;
typedef long long ll;
typedef unsigned char uc;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ld pi = 3.141592653589793238462643l;

int p[300010];

int P (int x) {
	if (p[x] == x) {
		return x;
	}
	return p[x] = P(p[x]);
}

int ans[300010];

int main () {
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	forn (i, 300010) {
		p[i] = i;
	}
	memset(ans, -1, sizeof ans);
	int n, m;
	cin >> n >> m;
	forn (i, m) {
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x);
		--l, --r, --x;
		int t = P(l);
		while (t <= r) {
			if (t != x) {
				p[t] = t + 1;
				ans[t] = x;
			}
			t = P(t + 1);
		}
	}
	forn (i, n) {
		printf("%d ", ans[i] + 1);
	}
	puts("");
	return 0;
}