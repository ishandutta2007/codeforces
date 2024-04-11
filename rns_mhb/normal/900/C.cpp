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

int n, p, ans, fimax, semax, id, tmp, cur, mini = N;

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%d", &n); ans = cur = -N;
    for (int i = 0; i < n; i ++) {
        scanf("%d", &p);
        if (p > fimax) {
            semax = fimax, fimax = p;
            if (cur > ans) ans = cur, id = tmp;
            cur = -1, tmp = p;
        }
        else {
            mini = min(mini, p);
            if (p > semax) cur ++, semax = p;
        }
    }
    if (cur > ans) ans = cur, id = tmp;
    if (ans <= 0 && mini < N) id = mini;
    printf("%d", id);

    return 0;
}