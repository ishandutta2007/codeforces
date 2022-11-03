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

struct Bug {
    int diff;
    int name;
    inline bool operator< (const Bug &x) const {
        if (diff != x.diff) return diff < x.diff;
        return name < x.name;
    }
};

struct Guy {
    int prof;
    int cost;
    int name;
    inline bool operator< (const Guy &x) const {
        if (prof != x.prof) return prof < x.prof;
        if (cost != x.cost) return cost < x.cost;
        return name < x.name;
    }
};
struct GuyCostCmp {
    inline bool operator() (const Guy &a, const Guy &b) const {
        if (a.cost != b.cost) return a.cost < b.cost;
        if (a.prof != b.prof) return a.prof < b.prof;
        return a.name < b.name;
    }
};

const int SIZE = 100<<10;

int n, m, s;
Bug bugs[SIZE];
Guy guys[SIZE];
int doneBy[SIZE];

bool Solve(int tl) {
    int bp = m-1;
    int gp = n-1;
    set<Guy, GuyCostCmp> cheapest;
    int currRem = -1;
    Guy currGuy;

    int64 sumCost = 0;

    while (bp >= 0 || gp >= 0) {
        bool isGuy;
        if (bp < 0) isGuy = true;
        else if (gp < 0) isGuy = false;
        else isGuy = (bugs[bp].diff <= guys[gp].prof);

        if (isGuy) {
            cheapest.insert(guys[gp]);
            gp--;
        }
        else {
            if (currRem <= 0) {
                if (cheapest.empty())
                    return false;
                currGuy = *cheapest.begin();
                currRem = tl;
                cheapest.erase(cheapest.begin());
                sumCost += currGuy.cost;
            }

            assert(currRem > 0);
            doneBy[bugs[bp].name] = currGuy.name;
            currRem--;

            bp--;
        }
    }

    if (sumCost > s)
        return false;
    return true;
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0; i<m; i++) scanf("%d", &bugs[i].diff);
    for (int i = 0; i<n; i++) scanf("%d", &guys[i].prof);
    for (int i = 0; i<n; i++) scanf("%d", &guys[i].cost);

    for (int i = 0; i<m; i++) bugs[i].name = i;
    for (int i = 0; i<n; i++) guys[i].name = i;

    sort(bugs, bugs+m);
    sort(guys, guys+n);

    int left = 0;
    int right = SIZE;
    while (right - left > 1) {
        int middle = (left + right) >> 1;
        if (Solve(middle))
            right = middle;
        else
            left = middle;
    }

    if (right > m)
        printf("NO\n");
    else {
        Solve(right);
        printf("YES\n");
        for (int i = 0; i<m; i++)
            printf("%d ", doneBy[i] + 1);
    }

	return 0;
}