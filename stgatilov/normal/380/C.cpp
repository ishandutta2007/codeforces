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
	#define Eo(x) cerr<<#x<<" = "<<(x)<<tendl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

const int SIZE = 1<<20;
const int LOGS = 22;

int n;
char str[SIZE];
int sign[SIZE], psum[SIZE];
int smin[LOGS+1][SIZE];
int close[SIZE], clsum[SIZE];

int m;
int start, tend;

int GetMin(int left, int right) {
    int res = 1000000000;

    int lvl = 0;
    while ( (1<<(lvl+1)) <= right - left) lvl++;

    return min(smin[lvl][left], smin[lvl][right-(1<<lvl)]);
}

int score;
bool GoodMiddle(int pos) {
    int ref = -(GetMin(start, pos+1) - psum[start]);
    int rbal = (psum[pos] - psum[start]) + ref;
    int remcl = clsum[tend] - clsum[pos];
    if (rbal > remcl) {
        score = -1;
        return false;
    }
    score = (pos - start) - ref + remcl;
    return true;
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
    scanf("%s", str);
    n = strlen(str);

    for (int i = 0; i<n; i++) sign[i] = (str[i] == '(' ? 1 : -1);
    psum[0] = 0;
    for (int i = 0; i<n; i++) psum[i+1] = psum[i] + sign[i];

    for (int i = 0; i<n; i++) close[i] = (str[i] == ')');
    clsum[0] = 0;
    for (int i = 0; i<n; i++) clsum[i+1] = clsum[i] + close[i];

    for (int i = 0; i<=n; i++) smin[0][i] = psum[i];
    for (int s = 0; s<LOGS; s++)
        for (int i = 0; i<=n; i++) {
            int pos = i + (1<<s);
            smin[s+1][i] = min(smin[s][i], (pos <= n ? smin[s][pos] : 1000000000));
        }

    scanf("%d", &m);
    for (int i = 0; i<m; i++) {
        scanf("%d%d", &start, &tend);
        start--;

        int left = start;
        int right = tend + 1;
        while (right - left > 1) {
            int middle = (left + right) / 2;
            if (GoodMiddle(middle))
                left = middle;
            else
                right = middle;
        }
        GoodMiddle(left);

        printf("%d\n", score);
    }
	return 0;
}