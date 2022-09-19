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
	int a, b, c, d, n;
	cin >> a >> b >> c >> d >> n;
	int k = 0;
	forn (i, n) {
		if ((i + 1) % a == 0 || (i + 1) % b == 0 || (i + 1) % c == 0 || (i + 1) % d == 0) {
			k++;
		}
	}
	cout << k;
	return 0;
}