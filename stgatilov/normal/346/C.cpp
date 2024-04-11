#define _SECURE_SCL 0
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

const int SIZE = 1<<20;
const int MAXN = 100<<10;

int n, a, b;
int arr[MAXN];

int res[SIZE];

int divdown(int a, int b) { return a/b; }
int divup(int a, int b) { return (a+b-1)/b; }

const int QQ = 12100000;
int evs[QQ];
int tprev[QQ];
int tends[SIZE];


int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d", &n);
	for (int i = 0; i<n; i++) scanf("%d", &arr[i]);
	scanf("%d%d", &a, &b);

	sort(arr, arr+n);
	n = unique(arr, arr+n) - arr;
	fprintf(stderr, "!");

	int qq = 0;
	fprintf(stderr, "!");
	memset(tends, -1, sizeof(tends));
	for (int i = 0; i<n; i++) {
		int t = arr[i];
		int l = divup(b, t);
		int r = divdown(a, t);
		int curr = l*t - b;
		for (int j = l; j<=r; ) {
			evs[qq] = t;
			tprev[qq] = tends[curr];
			tends[curr] = qq;
			qq++;

			curr += t;
			break;
		}
	}
	fprintf(stderr, "!(%d)", qq);

	int tres = 0;
	int l = 0;
	int r = 1;
	while (1) {
		int nr = r+1;
		for (int i = l; i<r; i++) {
			res[i] = tres;
			for (int j = tends[i]; j>=0; ) {
				int q = evs[j];
				int pp = tprev[j];
				nr = max(nr, i+q);
				if (i+q <= a-b) {
					tprev[j] = tends[i+q];
					tends[i+q] = j;
				}
				j = pp;
			}
		}
		if (r > a-b) break;
		nr = min(nr, a-b+1);

		tres++;
		l = r;
		r = nr;
	}
	fprintf(stderr, "!");
    
    printf("%d\n", res[a-b]);

	return 0;
}