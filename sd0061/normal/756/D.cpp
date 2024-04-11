#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int Q = 1e9 + 7;
int n;
char str[N];

inline void add(int &A , int B) {
    A += B;
    if (A >= Q) {
        A -= Q;
    }
}

int f[2][N][27] , C[N][N];
int g[26][N][27];
int h[2][N] , w[26][N];
int cnt[N];

int main() {
    scanf("%d%s" , &n , str + 1);
    /*n = 5000;
    for (int i = 1 ; i <= n ; ++ i) {
        str[i] = 'a' + rand() % 26;
        }*/
    for (int i = 0 ; i <= n ; ++ i) {
        C[i][0] = 1;
        for (int j = 1 ; j <= i ; ++ j) {
            C[i][j] = C[i - 1][j - 1];
            add(C[i][j] , C[i - 1][j]);
        }
    }
    int cur = 0 , nxt = 1;
    memset(f[cur] , 0 , sizeof(f[cur]));
    f[cur][0][26] = 1;
    h[cur][0] = 1;
    for (int i = 1 ; i <= n ; ++ i) {
        memcpy(f[nxt] , f[cur] , sizeof(f[nxt]));
        memcpy(h[nxt] , h[cur] , sizeof(h[nxt]));
        for (int j = 0 ; j < i ; ++ j) {
            int k = str[i] - 'a';

            add(f[nxt][j + 1][k] , h[cur][j]);
            add(f[nxt][j + 1][k] , Q - f[cur][j][k]);
            add(f[nxt][j + 1][k] , Q - w[k][j]);
            add(f[nxt][j + 1][k] , g[k][j][k]);

            add(h[nxt][j + 1] , h[cur][j]);
            add(h[nxt][j + 1] , Q - f[cur][j][k]);
            add(h[nxt][j + 1] , Q - w[k][j]);
            add(h[nxt][j + 1] , g[k][j][k]);


            /*for (int l = 0 ; l <= 26 ; ++ l) {
                if (l != k) {
                    add(f[nxt][j + 1][k] , f[cur][j][l]);
                    add(f[nxt][j + 1][k] , Q - g[k][j][l]);

                    add(h[nxt][j + 1] , f[cur][j][l]);
                    add(h[nxt][j + 1] , Q - g[k][j][l]);
                }
                }*/
        }
        memcpy(g[str[i] - 'a'] , f[cur] , sizeof(f[cur]));
        memcpy(w[str[i] - 'a'] , h[cur] , sizeof(h[cur]));
        swap(cur , nxt);
    }
    int res = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        for (int j = 0 ; j < 26 ; ++ j) {
            add(cnt[i] , f[cur][i][j]);
        }
    }
    for (int i = 1 ; i <= n ; ++ i) {
        //cout << i << ' ' << cnt[i] << endl;
        add(res , (long long)cnt[i] * C[n - 1][i - 1] % Q);
    }
    cout << res << endl;
}