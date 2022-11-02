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

int n, b;
ll x, y;

void cal(ll &p){
    int t;
    scanf("%d %d", &n, &b);
    while (n --) {
        scanf("%d", &t);
        p = p * b + t;
    }
}

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    cal(x), cal(y);
    if (x < y) puts("<");
    else if (x > y) puts(">");
    else puts("=");

    return 0;
}