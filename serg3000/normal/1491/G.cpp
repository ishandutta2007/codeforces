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
	int n;
	cin >> n;
	vector<int>c(n);
	forn(i, n) {
		cin >> c[i];
		c[i] --;
	}
	vector<int>a(n);
	vector<int>used(n);
	vector<int>comp(n, -1);
	int z = 0;
	map<int, int>mp;
	forn(i, n) {
		int i2 = i;
		if (comp[i] == -1) {
			mp[z] = i;
			while (comp[i2] == -1) {
				comp[i2] = z;
				i2 = c[i2];
			}
			z++;
		}
	}
	vector<pair<int, int>>ans;
	int k = 0;
	forn(i, z / 2) {
		int i1 = mp[i * 2];
		int i2 = mp[i * 2 + 1];
		ans.push_back({ i1, i2 });
		int i3 = i1;
		i1 = c[i1];
		while (i1 != i3) {
			ans.push_back({ i2, i1 });
			i1 = c[i1];
		}
		int i4 = i2;
		i2 = c[i2];
		while (i2 != i4) {
			ans.push_back({ i1, i2 });
			i2 = c[i2];
		}
		ans.push_back({ i3, i4 });
	}
	if (z % 2 != 0) {
		int i1 = mp[z - 1];
		if (c[c[i1]] != i1) {


			ans.push_back({ i1, c[i1] });
			int i3 = i1;
			i1 = c[c[i1]];
			while (c[i1] != i3) {
				ans.push_back({ i3, i1 });
				i1 = c[i1];
			}
			ans.push_back({ i1, c[i3] });
			ans.push_back({ i1, i3 });
			ans.push_back({ c[i3], i3 });
		}
		else {
			int ff = 0;
			if (c[i1] != i1) {

				int cc = 0;
				forn(i, 3) {
					if (i1 != i && c[i1] != i) {
						cc = i;
					}
				}
				ans.push_back({ i1, cc });
				ans.push_back({ c[i1], cc });
				ans.push_back({ cc, i1 });
			}
		}
	}
	cout << ans.size() << '\n';
	forn(i, ans.size()) {
		cout << ans[i].first + 1 << " " << ans[i].second + 1 << '\n';
	}
	return 0;
}