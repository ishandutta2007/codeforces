#include <iostream>
#define FOR(i, l, r) for(int i=l; i<=r; i++)
#define f(i) f[i + 200002]
using namespace std;
int n, k, a[200005], f[400005];

bool check(int val) {
    FOR(i, -n, n) f(i) = 0;
    int v = 0; f(v) = 1;
    FOR(i, 1, n) {
        if (a[i] >= val) v++; else v--;
        if (f(v-1) && i-f(v-1)+1 >= k) return true;
        if (!f(v)) {
            if (f(v-1)) f(v) = f(v-1);
            else f(v) = i+1;
        }
    }
    return false;
}

int main()
{
    scanf("%d%d", &n, &k);
    int l = 1e9, r = 0;
    FOR(i, 1, n) scanf("%d", &a[i]), l = min(l, a[i]), r = max(r, a[i]);
    while (l < r) {
        int mid = (l+r+1) / 2;
        if (check(mid)) l = mid; else r = mid-1;
    }
    cout << l;
}