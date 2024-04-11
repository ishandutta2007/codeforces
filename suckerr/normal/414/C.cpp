#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1111111;

long long v[2][22]; 
int a[N], b[N];
int n, nn; 

void divide(int dep, int l, int r) {
    if (l == r) {
        return;
    }
    int mid = (l + r) / 2;
    divide(dep + 1, l, mid);
    divide(dep + 1, mid + 1, r);
    for(int i = mid + 1, p = l; i <= r; i++) {
        while(p <= mid && a[i] > a[p])
            p++;
        v[1][dep] += (p - l);
    }
    for(int i = l, p = mid + 1; i <= mid; i++) {
        while(p <= r && a[i] > a[p])
            p++;
        v[0][dep] += (p - mid - 1);
    }
    for(int i = l; i <= r; i++)
        b[i] = a[i];
    int p1 = l, p2 = mid + 1, tot = l;
    while(p1 <= mid || p2 <= r) {
        if (p2 > r) {
            a[tot++] = b[p1++];
        } else if (p1 > mid) {
            a[tot++] = b[p2++];
        } else if (b[p1] < b[p2]) {
            a[tot++] = b[p1++];
        } else {
            a[tot++] = b[p2++];
        }
    }
}

int main() {
    scanf("%d", &n);
    nn = n;
    n = (1 << nn);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    divide(0, 1, n);
    int q;
    long long ans = 0;
    for(int i = 0; i < nn; i++) {
        ans += v[0][i];
    }
    scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
        int s;
        scanf("%d", &s);
        s = nn - s;
        for(int j = s; j < nn; j++) {
            ans -= v[0][j];
            swap(v[0][j], v[1][j]);
            ans += v[0][j];
        }
        printf("%I64d\n", ans);
    }
    return 0;
}