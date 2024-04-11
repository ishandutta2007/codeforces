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
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppp;
typedef long double ld;

vector<pii> a;
bool good[12];
int n, xw;
int bc[1 << 10];
vector<ppp> ans;
char buf[310];
int len[256];
int b[5];
int lb, L;

void check() {
	/*int lb = 0;
	forn(j, 4) {
		sprintf(buf + lb, "%d", b[j]);
		lb += len[b[j]];
	}
	for (int i = 0; i < lb - 1 - i; i++)
		if (buf[i] != buf[lb - 1 - i]) return; */
	ans.pb(mp(mp(b[0], b[1]), mp(b[2], b[3])));
}

void rec(int i, int mask) {
	// printf("rec %d %d %d\n", i, mask, lb);
	if (i == 4) check();
	else {
		forn(j, a.size()) {
			if (n - bc[mask | a[j].second] <= 3 * (3 - i)) {
				b[i] = a[j].first;
				sprintf(buf + lb, "%d", a[j].first);
				lb += len[a[j].first];
				if (lb + (3 - i) > L) {
					lb -= len[a[j].first];
					break;
				}
				if (lb + 3 * (3-i) >= L) {	
					bool ok = true;
					for (int q = lb - 1; q > (L - 1)/2; q--)
						if (buf[q] != buf[L - 1 - q]) {
							ok = false;
							break;
						}
					if (ok) {
						// printf("ok to use b[%d] = %d\n", i, a[j].first);
						rec(i + 1, mask | a[j].second);
					}
				}
				lb -= len[a[j].first];
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	forn(i, n) {
		scanf("%d", &xw);
		good[xw] = true;
	}
	if (n > 6) {
		printf("%d\n", 0);
		return 0;
	}
	bc[0] = 0;
	for (int i = 1; i < (1 << 10); i++)
		bc[i] = bc[i & (i-1)] + 1;
	forn(i, 256) {
		bool ok = true;
		int md = 0;
		for (int x = i; x > 0; x /= 10) {
			md |= 1 << (x%10);
			ok &= good[x % 10];
			len[i]++;
		}
		if (md == 0) {
			md = 1;
			len[i] = 1;
			ok &= good[0];	
		} 
		if (ok) a.pb(pii(i, md));
	}
	for (L = 4; L <= 12; L++)
		rec(0, 0);
	printf("%d\n", int(ans.size()));
	forn(i, ans.size())
		printf("%d.%d.%d.%d\n", ans[i].first.first, ans[i].first.second, ans[i].second.first, ans[i].second.second);
	return 0;
}