#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <list>
#include <stack>
#include <queue>
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
#define sqr(x) ((x) * (x))

typedef long long int64;       
typedef long double ld;

int f[15];
vector<int64> lu;
bool used[20];

void gen(int64 cur, int len) {
	if (cur) {
		lu.pb(cur);
	}
	if (len == 12) {
		return;
	}
	gen(cur * 10 + 4, len + 1);
	gen(cur * 10 + 7, len + 1);
}

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	gen(0, 0);
	sort(lu.begin(), lu.end());
	f[0]  = 1;
	forn (i, 14) {
		f[i + 1] = f[i] * (i + 1);
	}
	int n, k;
	cin >> n >> k;
	if (n < 15 && k > f[n]) {
		cout << -1;
		exit(0);
	}
	k--;
	int cur = max(0, n - 14);
	int beg = cur, ans = 0;
	forn (i, lu.size()) {
		if (lu[i] <= cur) {
			ans++;
		} else {
			break;
		}
	}
	forn (i, 20) {
		used[i] = false;
	}
	while (cur < n) {
		int x = k / f[n - cur - 1];
		forn (i, 20) {
			if (used[i]) {
				continue;
			}
			if (x == 0) {
				used[i] = true;
				x = i;
				break;
			} else {
				x--;
			}
		}
		x += beg + 1;
//		cout << x << " ";
		bool isa = false, isb = false;
		forn (i, lu.size()) {
			if (lu[i] == x) {
				isa = true;
			}
			if (lu[i] == cur + 1) {
				isb = true;
			}
		}
		if (isa && isb) {
			ans++;
		}
		k = k % f[n - cur - 1];
		cur++;
	}
//	cout << endl;
	cout << ans;
}