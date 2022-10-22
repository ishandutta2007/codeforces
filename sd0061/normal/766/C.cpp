#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 3;
const int Q = 1e9 + 7;
typedef long long LL;

int n , a[N] , cnt[N];
char str[N];
bool f[N][N];
int g[N];

int main() {
    scanf("%d%s" , &n , str);;
    for (int i = 0 ; i < 26 ; ++ i) {
        scanf("%d" , &a[i]);
    }
    for (int i = 0 ; i < n ; ++ i) {
        memset(cnt , 0 , sizeof(cnt));
        for (int j = i ; j < n ; ++ j) {
            ++ cnt[str[j] - 'a'];
            f[i][j] = 1;
            for (int k = 0 ; k < 26 ; ++ k) {
                if (cnt[k] && j - i + 1 > a[k]) {
                    f[i][j] = 0;
                    break;
                }
            }
        }
    }
    memset(g , 0 , sizeof(g));
    g[0] = 1;
    for (int i = 0 ; i < n ; ++ i) {
        for (int j = i ; j < n ; ++ j) {
            if (f[i][j]) {
                g[j + 1] += g[i];
                if (g[j + 1] >= Q) g[j + 1] -= Q;
            }
        }
    }
    printf("%d\n" , g[n]);
    memset(g , 0xC0 , sizeof(g));
    g[0] = 0;
    for (int i = 0 ; i < n ; ++ i) {
        for (int j = i ; j < n ; ++ j) {
            if (f[i][j]) {
                g[j + 1] = max(g[j + 1] , max(j - i + 1 , g[i]));
            }
        }
    }
    printf("%d\n" , g[n]);
    memset(g , 0x3f , sizeof(g));
    g[0] = 0;
    for (int i = 0 ; i < n ; ++ i) {
        for (int j = i ; j < n ; ++ j) {
            if (f[i][j]) {
                g[j + 1] = min(g[j + 1] , 1 + g[i]);
            }
        }
    }
    printf("%d\n" , g[n]);

}