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

typedef long double ld;
typedef long long ll;
typedef unsigned char uc;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ld PI = 3.141592653589793238462643l;

pair<int, int> a[200000], b[200000];

vector<pair<int, int> > ans;

int main() {
	//freopen("input.txt", "rt", stdin)
	//freopen("output.txt", "wt", stdout)
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	forn (i, n) {
		scanf("%d", &a[i].fs);
		a[i].sc = i;
	}
	forn (i, m) {
		scanf("%d", &b[i].fs);
		b[i].sc = i;
	}
	sort(a, a + n);
	sort(b, b + m);
	int i = 0, j = 0;
	ans.clear();
	while (i < n && j < m) {
		if (b[j].fs < a[i].fs - x) {
			j++;
		} else if (b[j].fs > a[i].fs + y) {
			i++;
		} else {
			ans.pb(mp(a[i].sc, b[j].sc));
			i++;
			j++;
		}
	}
	cout << ans.size() << endl;
	forn (i, ans.size()) {
		printf("%d %d\n", ans[i].fs + 1, ans[i].sc + 1);
	}
	return 0;
}