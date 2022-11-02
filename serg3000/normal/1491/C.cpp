#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <queue>
#include <deque>
#include <unordered_set>
#include <map>
#include<unordered_map>
#include <bitset>
#include <random>
#include <ctime>
#include <fstream>
using namespace std;
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("section-anchors")
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
#pragma GCC optimize("vpt")
#pragma GCC optimize("rename-registers")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("function-sections")
#pragma GCC optimize("data-sections")
#pragma GCC optimize("branch-target-load-optimize")
#pragma GCC optimize("branch-target-load-optimize2")
#pragma GCC optimize("btr-bb-exclusive")
#define ll long long
#define rall(v) v.rbegin(), v.rend()
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define firn(i, n) for (int i = 1; i < (int)n; i++)
#define all(v) v.begin(), v.end()
mt19937 rnd(time(nullptr));
#define int long long
using namespace std;
const int MAXN = 5e5;
vector<int>t(MAXN);
void upd(int v, int tl, int tr, int pos, int x) {
	if (tl + 1 == tr) {
		t[v] = x;
		return;
	}
	else {
		int tm = (tl + tr) / 2;
		if (tm > pos) {
			upd(2 * v, tl, tm, pos, x);
		}
		else {
			upd(2 * v + 1, tm, tr, pos, x);
		}
		t[v] = max(t[2 * v],  t[v + v + 1]);
	}
}
int getmax(int v, int tl, int tr, int l, int r) {
	if (l >= r) {
		return -1e9;
	}
	if (tl == l && tr == r) {
		return t[v];
	}
	else {
		int tm = (tl + tr) / 2;
		return max(getmax(2 * v, tl, tm, l, min(r, tm)), getmax(v + v + 1, tm, tr, max(l, tm), r));
	}
}
signed main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int t;
	cin >> t;
	forn(w, t) {
		int n;
		cin >> n;
		vector<int>a(n);
		forn(i, n) {
			cin >> a[i];
		}
		int cnt = 0;
		vector<int>r(n);
		forn(i, n) {
			int la = 1e8;
			for (int j = n - 1; j > -1; j--) {
				if (a[j] == 1 && (j + 1 == n || a[j + 1] != 1)) {
					la = j + 1;
					r[j] = la;
					
				}
				else {
					if (a[j] == 1) {
						
						r[j] = la;
					}
					else {
						r[j] = 0;
					}
				}
			}
			int x = a[i];
			if (a[i] > n - i + 1) {
				cnt += a[i] - (n - i + 1);
				x -= a[i] - (n - i + 1);
				a[i] = (n - i + 1);
			}
			firn(w, x) {
				cnt++;
				int i2 = i;
				while (i2 < n) {
					a[i2]--;
					int i3 = i2;
					i2 += a[i2] + 1;
					if (i2 < n && r[i2] != 0) {
						i2 = r[i2];
					}
					a[i3] = max(a[i3], 1ll);
					
				}
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}