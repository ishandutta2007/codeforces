#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
#define foreach(it , h) for (typeof((h).begin()) it = (h).begin() ; it != (h).end() ; ++ it)
const int N = 100005;
int n , K , Q = 1e9 + 7;
int f[N << 1];
int getf(int x) {return x == f[x] ? x : f[x] = getf(f[x]);}

void work() {
    int i , x , y;
    char str[5];
    scanf("%d%d",&n,&K);
    for (i = 0 ; i < n + n + 2 ; ++ i)
        f[i] = i;
    int X = n + n + 1 , O = n + n;
    for (i = 0 ; i < K ; ++ i) {
        scanf("%d%d%s" , &x , &y , str);
        -- x , -- y;
        int l = abs(x - y) , r = min(x + y , 2 * (n - 1) - x - y);
        if (l < 2) {
            if (*str == 'o') {
                if (getf(r) == getf(X) || getf(r + n) == getf(O))
                    break;
                f[getf(r)] = getf(O);
                f[getf(r + n)] = getf(X);
            } else {
                if (getf(r) == getf(O) || getf(r + n) == getf(X))
                    break;
                f[getf(r)] = getf(X);
                f[getf(r + n)] = getf(O);
            }
        } else {
            l -= 2;
            if (*str == 'x') {
                if (getf(r) == getf(l + n) || getf(l) == getf(r + n))
                    break;
                f[getf(r)] = getf(l);
                f[getf(r + n)] = getf(l + n);
            } else {
                if (getf(r) == getf(l) || getf(l + n) == getf(r + n))
                    break;
                f[getf(r)] = getf(l + n);
                f[getf(r + n)] = getf(l);
            }
        }

    }
    if (i < K || getf(O) == getf(X)) {
        puts("0");
        return;
    }
    int ans = 1;
    for (i = 0 ; i < n ; ++ i) {
        x = getf(i);
        if (x == i && x != getf(O) && x != getf(X))
            ans += ans , ans %= Q;
    }
    printf("%d\n" , ans);
}

int main() {
    work();
    return 0;
}