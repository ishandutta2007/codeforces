#include <bits/stdc++.h>
using namespace std;
#define N 100100
#define inf 1e9
#define eps 1e-7

typedef pair<int, int> pii;
typedef long long ll;

template <class T>
inline void chkmax(T &x, T y) {if (x < y) x = y;}

template <class T>
inline void chkmin(T &x, T y) {if (x > y) x = y;}

int n, x, y, flp, fln;

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%d", &n);
    while (n --) {
        scanf("%d %d", &x, &y);
        if (x > 0) flp ++;
        if (x < 0) fln ++;
    }
    if (flp > 1 && fln > 1) puts("No");
    else puts("Yes");

    return 0;
}