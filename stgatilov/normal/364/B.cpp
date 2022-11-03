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

const int NUM = 64;
const int SIZE = 10<<10;
const int MAXS = SIZE * NUM;

int n, d;
int arr[NUM];

bool res[NUM][MAXS+1];
bool poss[MAXS+1];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
    scanf("%d%d", &n, &d);
    for (int i = 0; i<n; i++) scanf("%d", &arr[i]);

    res[0][0] = 1;
    for (int i = 0; i<n; i++)
        for (int j = 0; j<=MAXS; j++) if (res[i][j]) {
            res[i+1][j] |= res[i][j];
            res[i+1][j+arr[i]] |= res[i][j];
        }

    for (int j = 0; j<=MAXS; j++) if (res[n][j]) poss[j] = true;

    int curr = 0;
    int turns = 0;
    while (1) {
        int last = -1;
        for (int i = curr + 1; i <= curr + d && i <= MAXS; i++)
            if (poss[i])
                last = i;
        if (last < 0) break;
        curr = last;
        turns++;
    }

    printf("%d %d\n", curr, turns);

	return 0;
}