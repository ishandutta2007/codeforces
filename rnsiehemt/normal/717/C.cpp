#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
int a[100005];

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%d", a+i);
    sort(a,a+n);
    long long r = 0;
    FO(i,0,n) {
        r += a[i] * 1ll * a[n-i-1];
        r %= 10007;
    }
    printf("%lld\n", r);
}