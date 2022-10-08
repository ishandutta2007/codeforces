#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 200010
int n, a[N], b[N], q[N], c[N];

bool cmp(int x, int y) {
    int cx = a[x]-x;
    int cy = a[y]-y;
    return cx > cy;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> a[i];
    reverse(a, a+n);
    for (int i = 0; i < n; i ++) b[i] = a[i]-i;
    sort(b, b+n);
    for (int i = 0; i < n-1; i ++)
        if (b[i] == b[i+1]) {
            puts(":(");
            return 0;
        }
    for (int i = 0; i < n; i ++) q[i] = i;
    sort(q, q+n, cmp);
    /*
    for (int i = 0; i < n; i ++) 
        printf ("%d%c", q[i], i == n-1?'\n':' ');
    */
    for (int i = 0; i < n; i ++) c[i] = a[q[i]]+i-q[i];
    reverse(c, c+n);
    for (int i = 0; i < n; i ++) 
        printf ("%d%c", c[i], i == n-1?'\n':' ');
    return 0;
}