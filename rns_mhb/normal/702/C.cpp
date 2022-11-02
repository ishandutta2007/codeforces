#include <bits/stdc++.h>
using namespace std;

#define N 100005
#define INF 2000000007

template<class T> void chkmax(T &a, T b) { if (a < b) a = b; }
template<class T> void chkmin(T &a, T b) { if (a > b) a = b; }
int n, m;
int a[N], b[N];
int ans;

set<int> s;
set<int> :: iterator it;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i ++) {
        scanf("%d", &b[i]);
        s.insert(b[i]);
    }
    for (int i = 1; i <= n; i ++) {
        it = s.lower_bound(a[i]);
        int mn = INF;
        if (it != s.end()) chkmin(mn, *it - a[i]);
        if (it != s.begin()) {
            it --;
            chkmin(mn, a[i] - *it);
        }
        chkmax(ans, mn);
    }
    printf("%d\n", ans);
    return 0;
}