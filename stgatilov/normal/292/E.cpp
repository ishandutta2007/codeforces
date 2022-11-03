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
int src[SIZE];
int dest[SIZE];

typedef map<int, int> ColorMap;
typedef ColorMap::iterator mIter;
const int NOVAL = 1<<30;
ColorMap colors;

void PrintState() {
	for (mIter it = colors.begin(); it != colors.end(); it++) {
		printf("(%d ", it->first);
		if (it->second == NOVAL) printf("X");
		else printf("%d", it->second);
		printf("), ");
	}
	printf("\n");
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d", &n, &m);
	for (int i = 0; i<n; i++) scanf("%d", &src[i]);
	for (int i = 0; i<n; i++) scanf("%d", &dest[i]);

	colors[0] = NOVAL;
	colors[n] = NOVAL;

	for (int i = 0; i<m; i++) {
		int t;
		scanf("%d", &t);

		if (t == 2) {
			int pos;
			scanf("%d", &pos);
			pos--;

			mIter it = colors.lower_bound(pos+1);
			it--;
			int ans = (it->second == NOVAL ? dest[pos] : src[pos + it->second]);

			printf("%d\n", ans);
		}
		else {
			int ps, pd, len;
			scanf("%d%d%d", &ps, &pd, &len);
			ps--;  pd--;
			int offs = ps - pd;
			int left = pd;
			int right = left + len;

			mIter lit = colors.lower_bound(left);
			mIter rit = colors.lower_bound(right);
			bool setr = (rit->first != right);
			int afterc = NOVAL;
			if (setr) {
				mIter q = rit; q--;
				afterc = q->second;
			}
			colors.erase(lit, rit);
			colors[left] = offs;
			if (setr) colors[right] = afterc;
		}

//		PrintState();
	}

	return 0;
}