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
const int MAXN = 2*1e5 + 10;
const int MAXST = 4 * 1e6;

int c2[MAXN];
ll p[MAXN];
int a[MAXN];
int b[MAXN];
int c[2 * MAXN];

int main()
{
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	int n;
	cin >> n;
	FOR(i, n) {
		scanf("%d", &a[i]);
	}
	FOR(i, n) {
		scanf("%d", &b[i]);
	}
	ll m;
	cin >> m;
	c2[1] = 0;
	p[1] = 1 % m;
	for (int i = 2; i <= 2 * n; ++i) {
		c2[i] = c2[i - 1];
		int w = i;
		while (w % 2 == 0) {
			w /= 2;
			c2[i]++;
		}
		p[i] = (p[i - 1] * w) % m;
	}
	int eq = 0;
	FOR(i, n)
		if (a[i] == b[i])
			eq++;
	FOR(i, n) {
		c[i] = a[i];
		c[n + i] = b[i];
	}
	sort(c, c + 2 * n);
	int nm = 0;
	ll ans = 1;
	int cnt = 0;
	FOR(i, 2 * n) {
		if (i == 0 || c[i - 1] == c[i])
			nm++;
		else {
			ans = (ans * p[nm]) % m;
			cnt += c2[nm];
			nm = 1;
		}
	}
	ans = (ans * p[nm]) % m;
	cnt += c2[nm];
	cnt -= eq;
	ll st = 1;
	FOR(i, cnt){
		st = (st * 2) % m;
	}
	ans = (ans * st) % m;
	cout << ans;


	return 0;
}