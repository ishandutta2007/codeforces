#include <bits/stdc++.h>
using namespace std;
#define N 100100
#define inf 1000000000
#define eps 1e-7
#define pi acos(-1)
#define gc getchar
#define pc putchar
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;

template <class T>
inline void chkmax(T &x, T y) {if (x < y) x = y;}

template <class T>
inline void chkmin(T &x, T y) {if (x > y) x = y;}

int n, a[N];
bool fl;

void func(int i) {
    scanf("%d", &a[i]);
    while (!(a[i] % 2)) a[i] /= 2;
    while (!(a[i] % 3)) a[i] /= 3;
}

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) func(i);
    for (int i = 0; i < n; i ++)
        if (a[i] != a[0]) fl = 1;
    if (fl) puts("No");
    else puts("Yes");

    return 0;
}