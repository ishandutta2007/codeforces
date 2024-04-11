#pragma comment(linker, "/STACK:32000000")
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

int a[200000];
pii b[200000];
vector<int> d[3];

int main() {
	//freopen("input.txt", "rt", stdin)
	//freopen("output.txt", "wt", stdout)
	int n;
	cin >> n;
	forn (i, n) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int m = 0;
	forn (i, n) {
		if (i == 0 || a[i] != a[i - 1]) {
			b[m].fs = 0;
			b[m].sc = a[i];
			m++;
		}
		b[m - 1].fs++;
	}
	sort(b, b + m);
	forn (i, m / 2) {
		swap(b[i], b[m - 1 - i]);
	}
	if (m < 3) {
		cout << 0;
		return 0;
	}
	while (b[2].fs > 0) {
		b[0].fs--;
		b[1].fs--;
		b[2].fs--;
		forn (i, 3) {
			d[i].push_back(b[i].sc);
		}
		ford (i, 3) {
			int l = i;
			int r = m - 1;
			while (l != r) {
				int mid = (l + r + 1) / 2;
				if (b[mid].fs > b[i].fs) {
					l = mid;
				} else {
					r = mid - 1;
				}
			}
			swap(b[i].fs, b[l].fs);
			swap(b[i].sc, b[l].sc);
		}
	}
	cout << d[0].size() << endl;
	forn (i, d[0].size()) {
		vi q(3);
		forn (j, 3) {
			q[j] = d[j][i];
		}
		sort(q.begin(), q.end());
		printf("%d %d %d\n", q[2], q[1], q[0]);
	}
	return 0;
}