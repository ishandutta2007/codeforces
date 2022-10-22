#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 18;
int n;
int cnt[1 << N];
double p[N][N];
double f[N][1 << N];

int main() {
    cin >> n;
    for (int i = 0 ; i < n; ++ i) {
        for (int j = 0 ; j < n ; ++ j) {
            cin >> p[i][j];
        }
    }
    for (int i = 1 ; i < 1 << n ; ++ i) {
        cnt[i] = cnt[i & (i - 1)] + 1;
    }
    f[0][1] = 1;
    for (int i = 1 ; i < 1 << n ; ++ i) {
        if (cnt[i] < 2) continue;
        for (int j = 0 ; j < n ; ++ j) {

            for (int k = 0 ; k < n ; ++ k) {
                if (j != k && (i >> k & 1)) {
                    f[j][i] = max(f[j][i] , p[j][k] * f[j][i ^ (1 << k)] + p[k][j] * f[k][i ^ (1 << j)]);
                }
            }
        }
        //f[i] /= cnt;
    }
    double res = 0;
    for (int i = 0 ; i < n ; ++ i) {
        res = max(res , f[i][(1 << n) - 1]);
    }
    printf("%.12f\n" , res);
}