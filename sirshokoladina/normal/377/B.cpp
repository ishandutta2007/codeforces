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

int n, m;
ll s;

pair<int, int> a[100100], b[100100];
ll c[100100];

int ans[100100];

bool check (int t) {
	ll s1 = 0;
	set<pair<ll, int> > st;
	int i = 0;
	for (int j = 0; j < m; j += t) {
		while (i < n && b[i].fs >= a[j].fs) {
			st.insert(mp(c[b[i].sc], b[i].sc));
			i++;
		}
		if (!st.size()) {
			return 0;
		}
		s1 += st.begin()->fs;
		forn (l, t) {
			if (j + l < m) {
				ans[a[j + l].sc] = st.begin()->sc;
			}
		}
		st.erase(st.begin());
	}
	return s1 <= s;
}

int main () {
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	cin >> n >> m >> s;
	forn (i, m) {
		scanf("%d", &a[i].fs);
		a[i].sc = i;
	}
	sort(a, a + m);
	reverse(a, a + m);

	forn (i, n) {
		scanf("%d", &b[i].fs);
		b[i].sc = i;
	}
	sort(b, b + n);
	reverse(b, b + n);

	forn (i, n) {
		int x;
		scanf("%d", &x);
		c[i] = x;
	}

	int l = 1, r = m + 1;
	while (l < r) {
		int m = (l + r) / 2;
		if (check(m)) {
			r = m;
		} else {
			l = m + 1;
		}
	}

	if (l > m) {
		puts("NO");
		return 0;
	}

	check(l);

	puts("YES");
	forn (i, m) {
		printf("%d ", ans[i] + 1);
	}
	puts("");
	return 0;
}