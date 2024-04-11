//#pragma comment(linker, "/STACK:20000000")
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

const int VERTS = 512;
const int EDGES = 10<<10;
const int TRIES = 20<<10;

int n, m;
int edges[EDGES][2];
vector<int> nbr[VERTS];

int p[VERTS], has[VERTS];
int rk[VERTS];
int get(int i) {
	int j;
	for (j = i; p[j] != j; j = p[j]);
	while (i != j) {
		int t = p[i];
		p[i] = j;
		i = t;
	}
	return j;
}
void join(int i, int j) {
	i = get(i);
	j = get(j);

	if (rk[i] <= rk[j]) {
		p[i] = j;
		if (rk[i] == rk[j])
			rk[j]++;
	}
	else
		p[j] = i;
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d", &n, &m);
	for (int i = 0; i<m; i++) {
		for (int j = 0; j<2; j++) {
			scanf("%d", &edges[i][j]);
			edges[i][j]--;
		}
		nbr[edges[i][0]].push_back(edges[i][1]);
		nbr[edges[i][1]].push_back(edges[i][0]);
	}

	int k;
	scanf("%d", &k);
	for (int i = 0; i<k; i++) {
		int left, right;
		scanf("%d%d", &left, &right);
		left--;

		for (int j = 0; j<n; j++) { p[j] = j; rk[j] = 0; }
		for (int j = 0; j<m; j++) {
			if (j >= left && j < right) continue;
            join(edges[j][0], edges[j][1]);
		}
		memset(has, 0, sizeof(has));
		for (int j = 0; j<n; j++) has[get(j)] = true;
		int ans = 0;
		for (int j = 0; j<n; j++) ans += has[j];

		printf("%d\n", ans);
	}


	return 0;
}