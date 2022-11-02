#include <bits/stdc++.h>
using namespace std;
#define N 100100
#define inf 1e9
#define eps 1e-7
#define gc getchar
#define pc putchar

typedef pair<int, int> pii;
typedef long long ll;

template <class T>
inline void chkmax(T &x, T y) {if (x < y) x = y;}

template <class T>
inline void chkmin(T &x, T y) {if (x > y) x = y;}

int a, b, c, t;
bool vis[N];

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%d %d %d", &a, &b, &c);
    while (!vis[a]) {
        vis[a] = 1, a *= 10, t ++;
        if (a / b == c) {printf("%d\n", t); return 0;}
        a %= b;
    }
    puts("-1");

    return 0;
}