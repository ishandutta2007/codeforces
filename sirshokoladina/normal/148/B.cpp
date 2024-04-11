#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <cstring>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i ++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i --)
#define sqr(a) ((a) * (a))
#define mp make_pair
#define pb push_back
#define fs first
#define sc second

typedef long long ll;
typedef long double ld;

int main() {
	//freopen ("input.txt", "rt", stdin);
	//freopen ("output.txt", "wt", stdout);
	ld vp, vd, t, f, c;
	cin >> vp >> vd >> t >> f >> c;
	if (vd <= vp) {
		cout << 0;
		return 0;
	}
	int k = 0;
	ld d = vd * t * vp / (vd - vp);
	while (d < c - 1e-9l) {
		k++;
		d = vd * (d + (d / vd + f) * vp) / (vd - vp);
	}
	cout << k;
	return 0;
}