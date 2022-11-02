#include <bits/stdc++.h>
using namespace std;
#define N 100100
#define inf 1000000000
#define eps 1e-7
#define pi acos(-1)
#define gc (getchar() - 48)
#define pc(x) putchar(x + 48)
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;

template <class T>
inline void chkmax(T &x, T y) {if (x < y) x = y;}

template <class T>
inline void chkmin(T &x, T y) {if (x > y) x = y;}

int h, m, a;

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    h = gc * 10 + gc; gc;
    m = gc * 10 + gc;
    scanf("%d", &a);
    a += h * 60 + m;
    m = a % 60, h = (a / 60) % 24;
    pc(h / 10), pc(h % 10), putchar(':');
    pc(m / 10), pc(m % 10), puts("");

    return 0;
}