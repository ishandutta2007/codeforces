#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>
#include <memory.h>
#include <set>
#include <cmath>
#include <queue>

using namespace std;

#define forab(i, a, b) for (int i = a; i < (int)(b); i++)
#define fordab(i, a, b) for (int i = b - 1; i >= (int)(a); i--)
#define forn(i, n) forab (i, 0, n)
#define ford(i, n) fordab (i, 0, n)
#define forv(i, n) forn (i, n.size())
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long int64;
typedef long double ld;

vector<pair<int, int> > a;
vector<int> ans;

int main() {
	int n;
	cin >> n;
	a.resize(n);
	ans.resize(n);
	forn (i, n) {
		cin >> a[i].fs;
		a[i].sc = i;
	}
	sort(a.begin(), a.end());
	int ind = 1, pos = a[0].sc;
	ans[a[0].sc] = -1;
	for (; ind < n && a[ind].fs == a[ind - 1].fs; ind++) {
		ans[a[ind].sc] = -1;
		pos = max(pos, a[ind].sc);
	}
	while (ind < n) {
		int newPos = -1;
		if (a[ind].sc > pos) {
			ans[a[ind].sc] = -1;
		} else {
			ans[a[ind].sc] = pos - a[ind].sc - 1;
		}
		newPos = max(newPos, a[ind].sc);
		ind++;
		for (; ind < n && a[ind].fs == a[ind - 1].fs; ind++) {
			if (a[ind].sc > pos) {
				ans[a[ind].sc] = -1;
			} else {
				ans[a[ind].sc] = pos - a[ind].sc - 1;
			}
			newPos = max(newPos, a[ind].sc);
		}
		pos = max(newPos, pos);
	}
	forn (i, n) {
		cout << ans[i] << " ";
	}
}