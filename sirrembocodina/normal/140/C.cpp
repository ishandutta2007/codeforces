#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <list>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
        
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = n - 1 ; i >= 0 ; i--)
#define forv(i, a) for (int i = 0; i < (int)(a.size()); i++)
#define forab(i, a, b) for (int i = a; i < (int)(b); i++)
#define fordab(i, a, b) for (int i = b - 1; i >= (int)(a); i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define pi 3.1415926535897932
#define all(a) a.begin(), a.end()

typedef long long int64;       
typedef long double ld;

int a[100100];
vector<int> b, c;
multiset<pair<int, int> > s;
vector<int> a1, a2, a3;

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	int n;
	scanf("%d", &n);
	forn (i, n) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	b.pb(1);
	c.pb(a[0]);
	forab (i, 1, n) {
		if (a[i] != a[i - 1]) {
			b.pb(1);
			c.pb(a[i]);
		} else {
			b[b.size() - 1]++;
		}
	}
	if (b.size() < 3) {
		cout << 0;
		return 0;
	}
	forv (i, b) {
		s.insert(mp(-b[i], c[i]));
	}
	int ans = 0;
	while (true) {
		pair<int, int> A, B, C;
		A = *s.begin();
		s.erase(s.begin());
		B = *s.begin();
		s.erase(s.begin());
		C = *s.begin();
		s.erase(s.begin());
		if (C.fs == 0) {
			break;
		}
		s.insert(mp(A.fs + 1, A.sc));
		s.insert(mp(B.fs + 1, B.sc));
		s.insert(mp(C.fs + 1, C.sc));
		ans++;
		a3.pb(min(A.sc, min(B.sc, C.sc)));
		a2.pb(A.sc + B.sc + C.sc - max(A.sc, max(B.sc, C.sc)) - min(A.sc, min(B.sc, C.sc)));
		a1.pb(max(A.sc, max(B.sc, C.sc)));
	}
	printf("%d\n", ans);
	forv (i, a1) {
		printf("%d %d %d\n", a1[i], a2[i], a3[i]);
	}
}