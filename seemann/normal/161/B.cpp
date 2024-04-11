#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <vector>

#define ll long long int
#define clr(a) memset(a, 0, sizeof(a))
#define FOR(a, b) for(int a = 0; a < (b); a++)
#define iter(a) typeof(a.begin())
#define foreach(a, it) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)

using namespace std;

const long double EPS = 1e-8;
const int INF = 1000000001;
const int MAXN = 1001;

struct obj {
	int c;
	int n;
};

bool operator < (obj a, obj b) {
	return a.c > b.c;
}

obj a[MAXN];
obj b[MAXN];
int ca, cb;
vector<int> ans[MAXN];

int main()
{
//	freopen("a.in", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	int n, k;
	cin >> n >> k;
	FOR(i, n) {
		int c, t;
		cin >> c >> t;
		c *= 2;
		if (t == 1) {
			a[ca].c = c;
			a[ca++].n = i + 1;
		} else {
			b[cb].c = c;
			b[cb++].n = i + 1;
		}
	}
	sort(a, a + ca);
	sort(b, b + cb);
	ll sum = 0;
	FOR(i, cb)
		sum += b[i].c;
	if (ca < k) {
		FOR(i, ca) {
			sum += a[i].c / 2;
			ans[i].push_back(a[i].n);
		}
		int pb = 0;
		for (int i = ca; i < k - 1; ++i) {
			ans[i].push_back(b[pb].n);
			pb++;
		}
		for (int i = pb; i < cb; ++i)
			ans[k - 1].push_back(b[i].n);
	} else {
		FOR(i, k - 1) {
			sum += a[i].c / 2;
			ans[i].push_back(a[i].n);
		}
		for (int i = k - 1; i < ca; ++i) {
			sum += a[i].c;
			ans[k - 1].push_back(a[i].n);
		}
		FOR(i, cb) {
			ans[k - 1].push_back(b[i].n);
		}
		int mn = a[ca - 1].c;
		if (cb > 0 && b[cb - 1].c < mn)
			mn = b[cb - 1].c;
		mn /= 2;
		sum -= mn;
	}
	cout << sum / 2;
	if (sum % 2 == 1) {
		cout << ".5";
	}else {
		cout << ".0";
	}
	cout << '\n';
	FOR(i, k) {
		printf("%d ", ans[i].size());
		FOR(j, ans[i].size()) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}