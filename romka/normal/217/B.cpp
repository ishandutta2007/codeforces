#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int inf = (int)1e9;

int n, r;

int main() {
	scanf("%d %d", &n, &r);
	if (n == 1 && r == 1) {
		printf("0\nT\n");
		return 0;
	}
	if (n == 2 && r == 2) {
		printf("0\nTB\n");
		return 0;
	}
	int best = inf, bk = -1;
	for (int k = 1; k <= r/2; k++) {
		int a = r - k;
		int b = k;
		int cnt = 1;
		int err = 0;
		while (true) {
			if (a < b) swap(a, b);
			if (b == 0) break;
			if (b == 1) {
				err += a - 2;
				cnt += a;
				break;
			}
			cnt += a / b;
			err += a / b - 1;
			a %= b;
		}
		if (b != 1) continue;
		if (cnt == n) {
			if (err < best) {
				best = err;
				bk = k;
			}
		}
	}
	if (best == inf) printf("IMPOSSIBLE\n");
	else {
		int a = r - bk;
		int b = bk;
		vector<char> ans;
		while (a != 1 || b != 1) {
			if (a > b) ans.pb('T'), a -= b;
			else ans.pb('B'), b -= a;
		}
		if (ans.back() == 'T') {
			forn(i, ans.size())
				ans[i] = ans[i] == 'T' ? 'B' : 'T';
		}
		ans.pb('T');
		reverse(ans.begin(), ans.end());
		if (ans.back() == 'T') ans.pb('B');
		else ans.pb('T');
		printf("%d\n", best);
		forn(i, ans.size()) printf("%c", ans[i]);
		printf("\n");
	}
    return 0;
}