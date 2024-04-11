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

int q[100010];
int a[100010];
bool b[100010];

int main() {
	//freopen("input.txt", "rt", stdin)
	//freopen("output.txt", "wt", stdout)
	memset(a, 0, sizeof a);
	int n, m;
	cin >> n >> m;
	int k = 0;
	forn (i, n) {
		int x;
		scanf("%d", &x);
		q[i] = x;
		if (x < 0) {
			k++;
			x = -x;
			a[x - 1] --;
		} else {
			a[x - 1] ++;
		}
	}
	int c = 0;
	forn (i, n) {
		b[i] = (k + a[i] == m);
		c += b[i];
	}
	forn (i, n) {
		int x = q[i];
		if (x < 0) {
			x = -x;
		}
		x--;
		int ans = 0;
		if (!b[x]) {
			ans = -1;
		} else {
			if (c == 1) {
				ans = 1;
			}
		}
		if (q[i] < 0) {
			ans *= -1;
		}
		if (ans == 1) {
			puts("Truth");
		} else if (ans == 0) {
			puts("Not defined");
		} else {
			puts("Lie");
		}
	}
	return 0;
}