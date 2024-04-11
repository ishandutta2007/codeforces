#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

typedef long long LL;

int n , m;
int a[N] , b[N];

bool check(LL V) {
    memcpy(b , a , sizeof(b));
    int i , j , K = n;
    for (i = 0 ; i < m && K ; ++ i) {
        while (K && !b[K - 1]) -- K;
        if (V < K)
            return 0;
        LL P = V - K;
        while (P && K) {
            if (!b[K - 1]) {
                -- K;
            } else {
                while (P && K) {
                    while (P && b[K - 1]) {
                        LL x = min(P , (LL)b[K - 1]);
                        P -= x , b[K - 1] -= x;
                    }
                    while (K && !b[K - 1]) -- K;
                }
            }
        }
    }
    return K == 0;
}

void work() {
    scanf("%d%d" , &n ,&m);
    for (int i = 0 ; i < n ; ++ i)
        scanf("%d" , &a[i]);
    LL l = 0 , r = 1e18 , mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << r << endl;
}

int main() {
    work();
    return 0;
}