#include <bits/stdc++.h>
using namespace std;
#define f1(i, a, b) for (int i = a; i <= b; i ++)
#define f3(i, a, b) for (int i = a; i >= b; i --)
template <class T> void chkmax(T &a, T b) {if (a < b) a = b;}

const int inf = 0x3f3f3f3f;

#define N 200005

int n, a[N];
int bs, b[N], L[N], R[N];

int main() {
    scanf("%d", &n);
    f1(i, 1, n) scanf("%d", &a[i]);
    bs = 0;
    f1(i, 1, n) {
        int k = upper_bound(b, b + bs, a[i] - i) - b;
        b[k] = a[i] - i;
        if (k == bs) bs ++;
        L[i] = k + 1;
    }
    f1(i, 1, n) a[i] = a[i] - i + 1, a[i] = inf - a[i];
	bs = 0;
	R[n-1] = 1;
    a[0] = inf * 2;
    f3(i, n, 1) {
        int k = upper_bound(b, b + bs, a[i]) - b;
        b[k] = a[i];
        if (k == bs) bs ++;
        if (i > 1) {
            k = upper_bound(b, b + bs, a[i-2]+1) - b;
            R[i-2] = k + 1;
        }
    }
    int ans = 0;
    f1(i, 0, n-1) chkmax(ans, L[i] + R[i] - 1);
    printf("%d\n", n - 1 - ans);
	return 0;
}