#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int n, a, b, m[110][110];

int main() {
    scanf("%d %d %d", &n, &a, &b);
    int c = 1;
    forn(i, a) {
        if (i & 1) {
            for (int j = b - 1; j >= 0; j--) {
                m[i][j] = c++;
                if (c > n) goto out;
            }
        } else {
            forn(j, b) {
                m[i][j] = c++;
                if (c > n) goto out;
            }
        }
    }
    out:;

    if (c > n) {
        forn(i, a) {
            forn(j, b) printf("%d ", m[i][j]);
            printf("\n");
        }
    } else {
        printf("-1\n");
    }

    return 0;
}