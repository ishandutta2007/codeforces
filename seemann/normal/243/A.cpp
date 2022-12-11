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
const int MAXN = 100100;
const int MAXD = 21;
const int MAXC = 1e6 + 10;

int a[MAXN];
int d[MAXD][MAXN];
int cd[MAXN];
int cp[MAXN];

struct event{
	short int d;
	int dist;
};

bool operator < (const event& a, const event& b) {
	if (a.dist != b.dist)
		return a.dist < b.dist;
	return a.d < b.d;
}
event c[MAXD];
int nm[MAXD];

int main()
{
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	int n;
	cin >> n;
	clr(cd);
	FOR(i, n) {
		scanf("%d", &a[i]);
		for (int j = 1, st = 0; j < MAXC; j <<= 1, st++) {
			if ((a[i] & j) != 0) {
				d[st][cd[st]++] = i;
			}
			nm[st] = j;
		}
	}
	set<int> ans;
	clr(cp);
	FOR(i, n) {
		FOR(j, MAXD) {
			while (cp[j] < cd[j] && d[j][cp[j]] <= i)
				cp[j]++;
		}
		FOR(j, MAXD) {
			if (cp[j] >= cd[j])
				c[j].dist = INF;
			else
				c[j].dist = d[j][cp[j]] - i;
			c[j].d = j;
		}
		sort(c, c + MAXD);
		/*
		FOR(j, MAXD)
			cerr << c[j].dist << ' ' << c[j].d << '\n';
			*/
		int w = a[i];
		//cerr << w<< '\n';
		ans.insert(w);
		FOR(j, MAXD) {
			if (c[j].dist == INF)
				break;
			w |= nm[c[j].d];
			if (c[j + 1].dist > c[j].dist) {
		//		cerr << w << '\n';
				ans.insert(w);
			}
		}
	}
	cout << ans.size() << '\n';

	return 0;
}