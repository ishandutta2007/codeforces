#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int maxn = 300010;

int n, w, a[maxn], b[maxn];
set<pii> s0to1, s1to2, s2to1, s1to0, s0to2;

int main() {
	scanf("%d %d", &n, &w);
	forn(i, n) {
		scanf("%d %d", &a[i], &b[i]);
		s0to1.insert(pii(a[i], i));
		s0to2.insert(pii(b[i], i));
	}

	// s1to2
	// s2to1
	ll ans = 0;
	while (w--) {
		int best = int(1e9 + 7);
		int bd = -1;
		if (!s0to1.empty() && s0to1.begin()->first < best) {
			best = s0to1.begin()->first;
			bd = 0;
		}

		if (!s1to2.empty() && s1to2.begin()->first < best) {
			best = s1to2.begin()->first;
			bd = 1;
		}

		if (!s0to2.empty()) {
			int cur = s0to2.begin()->first;
			int cwin = 0;
			int td = -1;
			if (!s2to1.empty() && s2to1.rbegin()->first > cwin) {
				td = 1;
				cwin = s2to1.rbegin()->first;
			}
			if (!s1to0.empty() && s1to0.rbegin()->first > cwin) {
				td = 0;
				cwin = s1to0.rbegin()->first;
			}

			if (cur - cwin < best) {
				best = cur - cwin;
				bd = 2 + td;
			}
		}

		if (bd == 0) {
			int i = s0to1.begin()->second;
			ans += a[i];
			s0to1.erase(s0to1.begin());
			s0to2.erase(pii(b[i], i));
			s1to2.insert(pii(b[i] - a[i], i));
			s1to0.insert(pii(a[i], i));

			int cd = -1;
			int cb = 0;
			if (!s2to1.empty() && s2to1.rbegin()->first > cb) {
				cb = s2to1.rbegin()->first;
				cd = 0;
			}
			if (!s1to0.empty() && s1to0.rbegin()->first > cb && s1to0.rbegin()->second != s1to2.begin()->second) {
				cb = s1to0.rbegin()->first;
				cd = 1;
			}
			if (s1to0.size() > 1) {
				set<pii>::iterator it = s1to0.end();
				it--;
				it--;
				if (it->first > cb && it->second != s1to2.begin()->second) {
					cb = it->first;
					cd = 2;
				}
			}

			// printf("action: %d(%d) %d\n", bd, i, cd);

			if (cb > s1to2.begin()->first) {
				if (cd == 0) {
					ans += s1to2.begin()->first - s2to1.rbegin()->first;
					int i12 = s1to2.begin()->second;
					int i21 = s2to1.rbegin()->second;
					// printf("back 2to1: %d\n", i21);
					s1to2.erase(s1to2.begin());
					s1to0.erase(pii(a[i12], i12));
					s2to1.erase(--s2to1.end());
					s1to2.insert(pii(b[i21] - a[i21], i21));
					s1to0.insert(pii(a[i21], i21));
					s2to1.insert(pii(b[i12] - a[i12], i12));
				} else if (cd == 1) {
					ans += s1to2.begin()->first - s1to0.rbegin()->first;
					int i12 = s1to2.begin()->second;
					int i10 = s1to0.rbegin()->second;
					s1to2.erase(pii(a[i12], i12));
					s1to0.erase(pii(a[i10], i10));
					s2to1.insert(pii(b[i12] - a[i12], i12));
					s0to1.insert(pii(a[i10], i10));
					s0to2.insert(pii(b[i10], i10));
				} else if (cd == 2) {
					set<pii>::iterator it = s1to0.end();
					it--; it--;
					ans += s1to2.begin()->first - it->first;
					int i12 = s1to2.begin()->second;
					int i10 = it->second;
					s1to2.erase(pii(a[i12], i12));
					s1to0.erase(pii(a[i10], i10));
					s2to1.insert(pii(b[i12] - a[i12], i12));
					s0to1.insert(pii(a[i10], i10));
					s0to2.insert(pii(b[i10], i10));
				}
			}
		} else if (bd == 1) {
			int i = s1to2.begin()->second;
			// printf("action: %d(%d)\n", bd, i);
			ans += b[i] - a[i];
			s1to2.erase(s1to2.begin());
			s1to0.erase(pii(a[i], i));
			s2to1.insert(pii(b[i] - a[i], i));
		} else if (bd == 2) {
			int i02 = s0to2.begin()->second;
			int i10 = s1to0.rbegin()->second;

			// printf("action: %d(%d)\n", bd, i02);

			ans += s0to2.begin()->first - s1to0.rbegin()->first;

			s0to2.erase(pii(b[i02], i02));
			s0to1.erase(pii(a[i02], i02));

			s1to0.erase(pii(a[i10], i10));
			s1to2.erase(pii(b[i10] - a[i10], i10));

			s2to1.insert(pii(b[i02] - a[i02], i02));

			s0to1.insert(pii(a[i10], i10));
			s0to2.insert(pii(b[i10], i10));
		} else if (bd == 3) {
			int i02 = s0to2.begin()->second;
			int i21 = s2to1.rbegin()->second;

			// printf("action: %d(%d)\n", bd, i02);

			ans += s0to2.begin()->first - s2to1.rbegin()->first;

			s0to2.erase(pii(b[i02], i02));
			s0to1.erase(pii(a[i02], i02));

			s2to1.erase(pii(b[i21] - a[i21], i21));

			s2to1.insert(pii(b[i02] - a[i02], i02));

			s1to2.insert(pii(b[i21] - a[i21], i21));
			s1to0.insert(pii(a[i21], i21));
		}

		// assert(s1to0.size() == s1to2.size());
		// assert(s0to1.size() == s0to2.size());
		// assert(s0to1.size() + s1to2.size() + s2to1.size() == n);
		// cout << "> " << ans << endl;
	}

	cout << ans << endl;
	forn(i, n) {
		if (s1to0.find(pii(a[i], i)) != s1to0.end() || s1to2.find(pii(b[i] - a[i], i)) != s1to2.end())
			printf("1");
		else
			if (s2to1.find(pii(b[i] - a[i], i)) != s2to1.end())
				printf("2");
			else
				printf("0");
	}
	printf("\n");

	return 0;
}