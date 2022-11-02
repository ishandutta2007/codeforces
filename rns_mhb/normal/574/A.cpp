#include <bits/stdc++.h>
using namespace std;
#define N 1001
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

int n, me, ans, a;
priority_queue <int> q;

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%d %d", &n, &me);
    for (int i = 1; i < n; i ++) scanf("%d", &a), q.push(a);
    while (!q.empty()) {
        int u = q.top(); q.pop();
        if (u < me) continue;
        ans ++, me ++, u --;
        if (me <= u) q.push(u);
    }
    printf("%d\n", ans);

    return 0;
}