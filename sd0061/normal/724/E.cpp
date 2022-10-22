#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 10005;

int n , C;
int p[N] , s[N];
LL f[2][N] , w[N];

int main() {
    scanf("%d%d" , &n , &C);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &p[i]);
    }
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &s[i]);
    }
    for (int i = 1 ; i <= n ; ++ i) {
        w[i] = w[i - 1] + C;
    }
    int cur = 0 , nxt = 1;
    memset(f , 0x3f , sizeof(f));
    f[0][0] = 0;
    for (int i = 0 ; i < n ; ++ i) {
        memset(f[nxt] , 0x3f , sizeof(f[nxt]));
        for (int j = 0 ; j <= i ; ++ j) {
            f[nxt][j] = min(f[nxt][j] , f[cur][j] + w[j] + p[i]);
            f[nxt][j + 1] = min(f[nxt][j + 1] , f[cur][j] + s[i]);
        }
        swap(cur , nxt);
    }
    LL res = 1LL << 60;
    for (int i = 0 ; i <= n ; ++ i) {
        res = min(res , f[cur][i]);
    }
    cout << res << endl;
}