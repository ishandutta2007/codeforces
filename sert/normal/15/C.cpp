#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
long long x, k, ans;

long long cnt(long long st, long long len) {
    if (len == 1) return st;
    if (len == 2) return st ^ (st + 1);
    if (len == 3) return st ^ (st + 1) ^ (st + 2);
    if (st % 2 == 0 && len % 2 == 0) {
        return (len / 2) % 2;
    }
    if (st % 2 == 1) return st ^ cnt(st + 1, len - 1);
    if (len % 2 == 1) return (st + len - 1) ^ cnt(st, len - 1);
    exit(1);
}

int main() {
    //freopen("a.in", "r", stdin);
    scanf("%d", &n);
    while (n--) {
        scanf("%I64d%I64d", &x, &k);
        ans ^= cnt(x, k);
    }
    if (ans) printf("tolik\n");
    else printf("bolik\n");
}