#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
typedef long long LL;

int n , K , a[N];

LL checkl(int x) {
    LL sum = 0;
    for (int i = 0 ; i < n ; ++ i) {
        sum += max(0 , x - a[i]);
    }
    return sum;
}
LL checkr(int x) {
    LL sum = 0;
    for (int i = 0 ; i < n ; ++ i) {
        sum += max(0 , a[i] - x);
    }
    return sum;
}


int main() {
    scanf("%d%d" , &n , &K);
    LL sum = 0;
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i]);
        sum += a[i];
    }
    sort(a , a + n);
    int l = 0 , r = 1e9;
    while (l < r) {
        int m = l + r + 1 >> 1;
        if (checkl(m) <= K) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    int L = l;
    l = 0 , r = 1e9;
    while (l < r) {
        int m = l + r >> 1;
        if (checkr(m) <= K) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    int R = r;
    printf("%d\n" , max(R - L , sum % n == 0 ? 0 : 1));
}