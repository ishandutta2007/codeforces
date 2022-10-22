#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
typedef long long LL;

int n , a[N] , f[N] , b[N];
vector<int> e[N];
LL res;
int sum[20][N][2];

void dfs(int x , int fa) {
    for (auto &y : e[x]) {
        if (y != fa) {
            a[y] ^= a[x];
            dfs(y , x);
            for (int i = 0 ; i < 20 ; ++ i) {
                sum[i][x][0] += sum[i][y][0];
                sum[i][x][1] += sum[i][y][1];
                for (int j = 0 ; j < 2 ; ++ j) {
                    for (int k = 0 ; k < 2 ; ++ k) {
                        if (j ^ k ^ (b[x] >> i & 1)) {
                            res -= ((LL)sum[i][y][j] * sum[i][y][k]) << i;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0 ; i < 20 ; ++ i) {
        ++ sum[i][x][a[x] >> i & 1];
        for (int j = 0 ; j < 2 ; ++ j) {
            for (int k = 0 ; k < 2 ; ++ k) {
                if (j ^ k ^ (b[x] >> i & 1)) {
                    res += ((LL)sum[i][x][j] * sum[i][x][k]) << i;
                }
            }
        }
    }
}

int main() {
    scanf("%d" , &n);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &a[i]);
        b[i] = a[i];
        res += a[i];
    }
    for (int i = 1 ; i < n ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1 , 0);
    cout << res / 2 << endl;
}