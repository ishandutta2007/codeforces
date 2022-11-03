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

const int SIZE = 128;

int n, m;
int arr[SIZE];
char mode[SIZE];
int pl[SIZE];

int res[24][1<<20];
const int BAD = 0x3f3f3f3f;

int Sign(int p) {
    return p == 1 ? 1 : -1;
}

int Solve(int k, int rem) {
    if (res[k][rem] != BAD)
        return res[k][rem];

    int ans;
    if (k == m)
        ans = 0;
    else {
        int sgn = Sign(pl[k]);
        ans = -sgn * BAD;
        if (mode[k] == 'p') {
            for (int i = 0; i<n; i++) if (rem & (1<<i)) {
                int tres = sgn * arr[i] + Solve(k+1, rem ^ (1<<i));
                if (sgn * tres > sgn * ans)
                    ans = tres;
            }
        }
        else {
            for (int i = 0; i<n; i++) if (rem & (1<<i)) {
                int tres = Solve(k+1, rem ^ (1<<i));
                if (sgn * tres > sgn * ans)
                    ans = tres;
            }
/*            int tres = Solve(k+1, rem);
            if (sgn * tres > sgn * ans)
                ans = tres;*/
        }
    }

    assert(ans != BAD && ans != -BAD);
    return res[k][rem] = ans;
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
    scanf("%d", &n);
    for (int i = 0; i<n; i++) scanf("%d", &arr[i]);
    scanf("%d", &m);
    for (int i = 0; i<m; i++) scanf(" %c%d", &mode[i], &pl[i]);

    sort(arr, arr+n);
    for (int i = 0; i<m; i++) arr[i] = arr[n-m+i];
    n = m;

    memset(res, 0x3F, sizeof(res));
    int ans = Solve(0, (1<<n)-1);

    printf("%d\n", ans);

    return 0;
}