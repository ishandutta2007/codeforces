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

const int SIZE = 5<<10;
const int MAXS = SIZE * 10;

char str[SIZE];
int a, n;
int64 cnt[MAXS+1];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
    scanf("%d", &a);
    scanf("%s", str);
    n = strlen(str);

    for (int l = 0; l<n; l++) {
        int sum = 0;
        for (int r = l+1; r<=n; r++) {
            sum += str[r-1] - '0';
            cnt[sum]++;
        }
    }

    int64 ans = 0;
    if (a == 0) {
        for (int i = 1; i<=MAXS; i++) ans += cnt[i] * cnt[0];
        ans *= 2;
        ans += cnt[0] * cnt[0];
    }
    else {
        for (int i = 1; i<=MAXS; i++) if (cnt[i]) {
            int j = a / i;
            if (i * j != a) continue;
            if (j > MAXS) continue;
            ans += cnt[i] * cnt[j];
        }
    }

    printf("%I64d\n", ans);

	return 0;
}