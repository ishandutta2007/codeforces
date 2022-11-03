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

void Exit(bool ok) {
	printf("%s\n", ok ? "YES" : "NO");
	exit(0);
}

const int SIZE = 2<<10;

int n;
bool matr[SIZE][SIZE];

vector<int> ord;
bool used[SIZE];
void DFS(int u) {
	used[u] = true;
	for (int i = 0; i<n; i++) if (!used[i] && matr[u][i])
		DFS(i);
	ord.push_back(u);
}

void DFS2(int u) {
	used[u] = true;
	for (int i = 0; i<n; i++) if (!used[i] && matr[i][u])
		DFS2(i);
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d", &n);
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++) {
			int q;
			scanf("%d", &q);
			matr[i][j] = (q > 0);
		}

	DFS(0);
	if (ord.size() != n) Exit(false);

	memset(used, 0, sizeof(used));
	DFS2(ord[n-1]);
	for (int i = 0; i<n; i++) if (!used[i]) Exit(false);

	Exit(true);

	return 0;
}