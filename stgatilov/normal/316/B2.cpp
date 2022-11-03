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

const int SIZE = 1024;

int n, x;
int mprev[SIZE];
int mnext[SIZE];

bool used[SIZE];

int k, xx;
int arr[SIZE];

bool res[2][SIZE];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d", &n, &x);
	x--;
	memset(mprev, -1, sizeof(mprev));
	memset(mnext, -1, sizeof(mnext));
	for (int i = 0; i<n; i++) {
		scanf("%d", &mprev[i]);
		mprev[i]--;
		if (mprev[i] >= 0) mnext[mprev[i]] = i;
	}

	for (int i = 0; i<n; i++) if (!used[i] && mprev[i] < 0) {
		int xpos = -1;

		int id = 0;
		int curr = i;
		while (curr >= 0) {
			int t = mnext[curr];

			used[curr] = true;
			if (curr == x) xpos = id;

			curr = t;
			id++;
		}
		
		if (xpos < 0)
			arr[k++] = id;
		else
			xx = xpos;
	}

	res[0][0] = true;
	for (int i = 0; i<k; i++) {
		memset(res[(i+1)&1], 0, sizeof(res[0]));
		for (int j = 0; j<=n; j++) if (res[i&1][j]) {
			res[(i+1)&1][j] = true;
			res[(i+1)&1][j+arr[i]] = true;
		}
	}

	for (int i = 0; i<=n; i++)
		if (res[k&1][i])
			printf("%d\n", i + xx + 1);

	return 0;
}