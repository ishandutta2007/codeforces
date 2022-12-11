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

int a[100001];
int mx[100001];

int main()
{
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	int n;
	cin >> n;
	FOR(i, n)
		scanf("%d", &a[i]);
	mx[0] = a[0];
	for (int i = 1; i < n; ++i) {
		mx[i] = max(mx[i - 1], a[i]);
	}
	long long curmx = 0;
	int m;
	cin >> m;
	FOR(i, m) {
		int w, h;
		scanf("%d%d", &w, &h);
		w--;
		ll ans = max(curmx, ((ll)mx[w]));
		printf("%I64d\n", ans);
		curmx = max(curmx, ans + h);
	}


	return 0;
}