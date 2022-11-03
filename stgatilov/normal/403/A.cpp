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

int n, p;
bool matr[32][32];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
int tests;
scanf("%d", &tests);
for (int tt = 0; tt < tests; tt++) {

    scanf("%d%d", &n, &p);
    memset(matr, false, sizeof(matr));

    for (int i = 0; i<n; i++) {
        int ni = (i+1) % n;
        matr[i][ni] = matr[ni][i] = true;
        ni = (i+2) % n;
        matr[i][ni] = matr[ni][i] = true;
    }

/*    for (int i = 0; i<1<<n; i++) {
        int k = 0;
        int c = 0;
        for (int u = 0; u<n; u++) if (i & (1<<u)) {
            for (int v = 0; v<n; v++) if (i & (1<<v))
                k += matr[u][v];
            c++;
        }
        k /= 2;
        if (k > 2*c) {
            assert(0);
            E(!);
        }
    }*/

    for (int i = 0; i<p; i++) {
        bool ok = false;
        for (int u = 0; !ok && u<n; u++)
            for (int v = u+1; !ok && v<n; v++)
                if (!matr[u][v]) {
                    ok = true;
                    matr[u][v] = matr[v][u] = true;
                }
        assert(ok);
    }

    for (int u = 0; u<n; u++)
        for (int v = u+1; v<n; v++)
            if (matr[u][v])
                printf("%d %d\n", u+1, v+1);

}

	return 0;
}