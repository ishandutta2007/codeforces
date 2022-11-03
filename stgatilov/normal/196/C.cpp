#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

struct iPoint {
	int x, y;
	inline iPoint(int _x = 0, int _y = 0) : x(_x), y(_y) {}

	inline iPoint operator+ (const iPoint &b) const { return iPoint(x+b.x, y+b.y); }
	inline iPoint operator- (const iPoint &b) const { return iPoint(x-b.x, y-b.y); }

	inline iPoint operator* (int b) const { return iPoint(x*b, y*b); }

	inline int64 operator^ (const iPoint &b) const { return int64(x)*b.x + int64(y)*b.y; }
	inline int64 operator% (const iPoint &b) const { return int64(x)*b.y - int64(y)*b.x; }

	inline int64 operator! () const { return int64(x)*x + int64(y)*y; }
	inline iPoint operator~ () const { return iPoint(-y, x); }
	inline bool operator< (const iPoint &b) const { return (x!=b.x ? x<b.x : y<b.y); }
};

const int SIZE = 1550;

int n;
vector<int> nbr[SIZE];
iPoint pts[SIZE];

iPoint ctr;
struct ComparePolar {
	inline bool operator() (int ai, int bi) const {
		iPoint a = pts[ai] - ctr;
		iPoint b = pts[bi] - ctr;
		return (a % b) < 0;
	}
};


bool vis[SIZE];
int vert[SIZE];
int tsz[SIZE];

void DFS(int u) {
	vis[u] = true;
	tsz[u] = 1;
	for (int i = 0; i<nbr[u].size(); i++) {
		int v = nbr[u][i];
		if (vis[v]) continue;
		DFS(v);
		tsz[u] += tsz[v];
	}
}

void Solve(int u, int p, vector<int> pinds) {
	vert[p] = u;
	vis[u] = true;

	for (int i = 0; i<pinds.size(); i++)
		if (pinds[i] == p) {
			std::swap(pinds[0], pinds[i]);
			break;
		}

	ctr = pts[p];
	sort(pinds.begin() + 1, pinds.end(), ComparePolar());

	int cc = 1;
	for (int i = 0; i<nbr[u].size(); i++) {
		int v = nbr[u][i];
		if (vis[v]) continue;

		int ncc = cc + tsz[v];
		vector<int> soninds(pinds.begin() + cc, pinds.begin() + ncc);
		cc = ncc;

		Solve(v, soninds[0], soninds);
	}
	assert(cc == tsz[u]);

}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 0; i<n-1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;  b--;
		nbr[a].push_back(b);
		nbr[b].push_back(a);
	}
	for (int i = 0; i<n; i++) scanf("%d%d", &pts[i].x, &pts[i].y);

	DFS(0);

	int best = -1;
	int minx = 2000000000;
	for (int i = 0; i<n; i++)
		if (minx > pts[i].x) {
			minx = pts[i].x;
			best = i;
		}
//	Eo(best);

	memset(vis, 0, sizeof(vis));
	memset(vert, -1, sizeof(vert));
	vector<int> pinds;
	for (int i = 0; i<n; i++) pinds.push_back(i);
	Solve(0, best, pinds);

	for (int i = 0; i<n; i++) printf("%d ", vert[i] + 1);
	printf("\n");

	return 0;
}