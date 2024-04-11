#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int n , m , K;
int a[N];
bool f[N];
int cnt[N];
int u[N] , t[N];
int main() {
    scanf("%d%d" , &n , &K);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i]);
        -- a[i];
    }
    int mx = 0 , m1 = 0 , m2 = 0;
    for (int i = 0 ; i < n ; ++ i) {
        if (!f[i]) {
            int x = i , y = 0;
            while (!f[x]) {
                f[x] = 1;
                x = a[x];
                ++ y;
            }
            ++ cnt[y];
            m1 += y % 2;
            m2 += y / 2;
        }
    }
    int tmpK = K;
    while (tmpK && m2) {
        tmpK --;
        m2 --;
        mx += 2;
    }
    while (tmpK && m1) {
        tmpK --;
        m1 --;
        mx ++;
    }
    memset(t , -1 , sizeof(t));
    t[0] = 0;
    int G = min(K , n - K);
    for (int i = 1 ; i <= n ; ++ i) {
        if (!cnt[i]) continue;
        for (int j = 0 ; j + i <= G ; ++ j) {
            if (t[j] < 0) continue;
            if (t[j] == i) {
                if (u[j]) {
                    if (t[j + i] < 0) {
                        t[j + i] = i;
                        u[j + i] = u[j] - 1;
                    }
                }
            } else {
                if (t[j + i] < 0) {
                    t[j + i] = i;
                    u[j + i] = cnt[i] - 1;
                }
            }
        }
        if (~t[G]) {
            break;
        }
    }
    int mn = ~t[G] ? K : K + 1;
    printf("%d %d\n" , mn , mx);
}