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
const int MOD = 1000000000;

int n, m;
int arr[SIZE];
int ph[SIZE];

void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}
int mult(int a, int b) {
	return (int64(a)*b) % MOD;
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	

	scanf("%d%d", &n, &m);
	for (int i = 0; i<n; i++) scanf("%d", &arr[i]);

	ph[0] = 1;
	ph[1] = 1;
	for (int i = 2; i<=n; i++) {
		ph[i] = ph[i-1];
		add(ph[i], ph[i-2]);
	}

	for (int i = 0; i<m; i++) {
		int t, a, b;
		scanf("%d%d%d", &t, &a, &b);
		if (t == 1)
			arr[a-1] = b;
		else if (t == 2) {
			int ans = 0;
			a--;
			for (int i = a; i<b; i++)
				add(ans, mult(ph[i-a], arr[i]));
			printf("%d\n", ans);
		}
	}

	return 0;
}