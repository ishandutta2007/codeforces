#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
#include <string>

using namespace std;

#ifdef _WIN32
#define I64 "%I64d"
#define LLD "%I64d"
#else
#define I64 "%lld"
#define LLD "%lld"
#endif

typedef long double ld;
typedef long long ll;

ll rdtsc() {
    ll tmp;
    asm("rdtsc" : "=A"(tmp));
    return tmp;
}

inline int myrand() {
    return abs((rand() << 15) ^ rand());
}

inline int rnd(int x) {
    return myrand() % x;
}

#define pb push_back
#define mp make_pair
#define EPS (1e-9)
#define INF ((int)1e9)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const string name[2] = {"Polycarp", "Vasiliy"};

bool main_impl() {
    int xp,yp,xv,yv;
    if (scanf("%d%d%d%d", &xp, &yp, &xv, &yv) < 4) return 0;
    int sp = xp + yp;
    int sv = xv + yv;

    bool pwins = false;
    for (int i = 0; i < sv - sp + 1; i++) {
        if (xp - yp > xv - yv) {
            xp--;
        } else {
            if (xp - yp < xv - yv) {
                yp--;
            }
        }
        xv -= 1, yv -= 1;
        if (xv == xp && yv == yp) {
            pwins = true;
        }
    }
    if (xv < 0 || yv < 0) {
        pwins = true;
    }
    printf("%s\n", name[!pwins].c_str());
    return 1;
}

int main() {
    srand(rdtsc());
    while(main_impl());
    eprintf("%.18lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}