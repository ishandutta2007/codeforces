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

const int SIZE = 100<<10;

int n, m;
int edges[SIZE][2];
vector<int> nbr[SIZE];
int deg[SIZE];

bool IsLoop() {
	for (int i = 0; i<n; i++)
		if (deg[i] != 2)
			return false;
	return true;
}

bool IsPath() {
	int cnt[3] = {0};
	for (int i = 0; i<n; i++) {
		if (deg[i] > 2)
			return false;
		cnt[deg[i]]++;	
	}
	return cnt[1] == 2;
}

bool IsStar() {
	vector<int> ctrDeg;
	for (int i = 0; i<n; i++)
		if (deg[i] != 1)
			ctrDeg.push_back(deg[i]);
	return ctrDeg.size() == 1;
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
	for (int i = 0; i<n; i++) deg[i] = nbr[i].size();

	if (IsPath()) printf("bus topology\n");
	else if (IsLoop()) printf("ring topology\n");
	else if (IsStar()) printf("star topology\n");
	else printf("unknown topology\n");

	return 0;
}