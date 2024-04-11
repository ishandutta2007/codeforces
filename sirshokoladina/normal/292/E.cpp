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

int a[100010], b[100010];
int lb[300010], rb[300010], t[300010], u[300010];

int d[100010];

int N = 1 << 17;

void push (int i) {
	t[i] = u[i];
	if (i < N - 1 && u[i] > -1) {
		u[2 * i + 1] = u[i];
		u[2 * i + 2] = u[i];
		u[i] = -1;
	}
}

int get (int l, int r, int i = 0) {
	push(i);
	if (lb[i] >= r || rb[i] <= l) {
		return -1;
	}
	if (lb[i] >= l && rb[i] <= r) {
		return t[i];
	}
	return max(get(l, r, 2 * i + 1), get(l, r, 2 * i + 2));
}

void upd (int l, int r, int v, int i = 0) {
	push(i);
	if (lb[i] >= r || rb[i] <= l) {
		return;
	}
	if (lb[i] >= l && rb[i] <= r) {
		u[i] = v;
		return;
	}
	upd(l, r, v, 2 * i + 1);
	upd(l, r, v, 2 * i + 2);
}

int main () {
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	int n, m;
	cin >> n >> m;
	forn (i, n) {
		scanf("%d", &a[i]);
	}
	forn (i, n) {
		scanf("%d", &b[i]);
	}
	
	ford (j, 2 * N - 1) {
		t[j] = -1;
		u[j] = -1;
		if (j >= N - 1) {
			lb[j] = j - (N - 1);
			rb[j] = j - (N - 1) + 1;
		} else {
			lb[j] = lb[2 * j + 1];
			rb[j] = rb[2 * j + 2];
		}
	}
	
	forn (i, m) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int x, y, k;
			scanf("%d%d%d", &x, &y, &k);
			x--;
			y--;
			d[i] = x - y;
			upd(y, y + k, i);
		} else {
			int x;
			scanf("%d", &x);
			x--;
			int k = get(x, x + 1);
			if (k == -1) {
				printf("%d\n", b[x]);
			} else {
				printf("%d\n", a[x + d[k]]);
			}
		}
	}
	return 0;
}