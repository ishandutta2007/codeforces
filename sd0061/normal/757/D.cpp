#include <bits/stdc++.h>
using namespace std;
const int N = 80;
const int Q = 1e9 + 7;

inline void add(int &x , int y) {
    x += y;
    if (x >= Q) {
        x -= Q;
    }
}
int n;
char str[N];
int num[N][N];
int f[N][1 << 20] , res;
int main() {
    scanf("%d%s" , &n , str);
    for (int i = 0 ; i < n ; ++ i) {
        num[i][i] = str[i] - '0';
        for (int j = i + 1 ; j < n ; ++ j) {
            num[i][j] = num[i][j - 1] * 2 + str[j] - '0';
            num[i][j] = min(100 , num[i][j]);
        }
    }
    for (int i = 0 ; i <= n ; ++ i) {
        add(f[i][0] , 1);

        for (int j = 0 ; j < 1 << 20 ; ++ j) {
            if (!f[i][j]) continue;

            for (int k = i ; k < n ; ++ k) {
                if (num[i][k] <= 20 && num[i][k]) {
                    add(f[k + 1][j | (1 << num[i][k] - 1)] , f[i][j]);
                }
                if (num[i][k] > 20) break;
            }
        }
    }
    for (int i = 1 ; i <= n ; ++ i) {
        int w = 0;
        for (int j = 0 ; j < 20 ; ++ j) {
            w = w << 1 | 1;
            add(res , f[i][w]);
        }
    }
    cout << res << endl;
}