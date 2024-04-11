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

int n;
int64 rect[5][4];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d", &n);
	for (int i = 0; i<n; i++)
		for (int j = 0; j<4; j++)
			scanf("%I64d", &rect[i][j]);

	int64 sqall = 0;
	for (int i = 0; i<n; i++)
		sqall += (rect[i][2] - rect[i][0]) * (rect[i][3] - rect[i][1]);


	for (int a = 0; a<n; a++)
		for (int b = 0; b<n; b++) {
			int64 reg[4] = {rect[a][0], rect[a][1], rect[b][2], rect[b][3]};

			if (reg[2] - reg[0] != reg[3] - reg[1]) continue;

			int64 tsq = (reg[2] - reg[0]) * (reg[3] - reg[1]);
			if (tsq != sqall) continue;

			bool ok = true;
			for (int i = 0; i<n; i++)
				ok &= (rect[i][0] >= reg[0] && rect[i][1] >= reg[1] && rect[i][2] <= reg[2] && rect[i][3] <= reg[3]);

			if (ok) {
				printf("YES\n");
				return 0;
			}
		}
	
	printf("NO\n");
	return 0;
}