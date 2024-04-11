#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n , a[N];

int main() {
    scanf("%d" , &n);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &a[i]);
    }
    for (int i = 1 ; i <= n ; ++ i) {
        a[i] += a[i - 1];
    }
    // 1: [1 , a[1]]
    // 2: [a[1]+1, a[2]]
    // .
    // .
    // n: [a[n - 1] + 1 , a[n]]
    int m;
    scanf("%d" , &m);
    while (m --) {
        int x;
        scanf("%d" , &x);
        int l = 1 , r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            if (x <= a[mid]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        printf("%d\n" , r);
    }

}