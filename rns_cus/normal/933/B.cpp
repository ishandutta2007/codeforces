#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int k, pw;

void calc(int *a, ll p) {
    if (p == 0) return;
    ll q = p / pw;
    int x = p % pw;
    if (x < k) {
        a[0] = x, a[1] = 0;
        calc(a + 2, q);
    }
    else {
        q ++, x = pw - x;
        int t = (x - 1) / k + 1;
        int y = k * t - x;
        a[0] = y, a[1] = t;
        calc(a + 2, q);
    }
}

int a[100];
ll p;

int main() {
    scanf("%I64d %d", &p, &k);
    pw = k * k;
    calc(a, p);
    int d = 99;
    while (!a[d]) d --;
    printf("%d\n", d + 1);
    for (int i = 0; i <= d; i ++) {
        if (i) putchar(' ');
        printf("%d", a[i]);
    }
    puts("");
}