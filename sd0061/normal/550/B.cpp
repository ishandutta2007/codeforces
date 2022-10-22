#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
typedef long long LL;

int n , L , R , X;
int a[N];

void work() {
    int i , j , cnt = 0;
    cin >> n >> L >> R >> X;
    for (i = 0 ; i < n ; ++ i)
        cin >> a[i];
    for (i = 0 ; i < 1 << n ; ++ i) {
        if (__builtin_popcount(i) < 2)
            continue;
        int s = 0 , mx = -1 << 30 , mn = 1 << 30;
        for (j = 0 ; j < n ; ++ j) {
            if (i >> j & 1) {
                s += a[j];
                mx = max(mx , a[j]);
                mn = min(mn , a[j]);
            }
        }
        if (s > R || s < L || mx - mn < X)
            continue;
        ++ cnt;
    }
    cout << cnt << endl;
}

int main() {
    work();
    return 0;
}