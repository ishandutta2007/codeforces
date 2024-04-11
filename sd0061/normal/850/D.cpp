#include <bits/stdc++.h>
using namespace std;
const int N = 100;
const int M = N * N;
int n;
int a[N], sd[N];

bool f[N][N][M];
short g[N][N][M];

vector<int> v;

pair<int , int> od[N];
int p[N][N] , q[N][N];

void gao(int x , int y , int z) {
    //cout << x << ' ' << y << ' ' << z << endl;
    if (y == 0) {
        return;
    }
    v.emplace_back(g[x][y][z] % 100);
    gao(x - g[x][y][z] / 100 , y - 1 , z - g[x][y][z] % 100);
}

int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i]);
    }
    sort(a , a + n);
    f[0][0][0] = 1;
    for (int i = 0 ; i < n ; ++ i) {
        for (int j = 0 ; j <= N - 5 ; ++ j) {
            int edge = j * (j - 1) / 2;
            int end = j * (j + 1) / 2;
            for (int k = edge ; k < M ; ++ k) {
                if (!f[i][j][k]) continue;
                if (k + a[i] < M && k + a[i] >= end) {
                    f[i][j + 1][k + a[i]] = 1;
                    g[i][j + 1][k + a[i]] = a[i];

                    f[i + 1][j + 1][k + a[i]] = 1;
                    g[i + 1][j + 1][k + a[i]] = a[i] + 100;
                }
            }
        }
    }
    int res = 1 << 30;
    for (int i = 0 ; i <= N - 5 ; ++ i) {
        if (f[n][i][i * (i - 1) / 2]) {
            res = min(res , i);
        }
    }
    if (res == 1 << 30) {
        cout << "=(" << endl;
        return 0;
    }
    gao(n , res , res * (res - 1) / 2);
    sort(v.begin() , v.end());
    n = res;
    cout << n << endl;
    for (int i = 0 ; i < n ; ++ i) {
        //cout << v[i] << " \n"[i + 1 == n];
        od[i] = {v[i] , i};
    }


    for (int i = n - 1 ; i >= 0 ; -- i) {
        sort(od , od + i + 1);
        int x = od[i].second;
        int id = i - od[i].first;
        //cout << id << endl;
        while (id) {
            sort(od , od + i);
            for (int j = 0 ; j < i ; ++ j) {
                sd[j] = j ? sd[j - 1] + od[j].first : od[j].first;
            }

            for (int j = i - 1 ; j >= 0 ; -- j) {
                -- sd[j];
                int y = od[j].second;
                if (!q[y][x] && od[j].first && sd[j] >= j * (j + 1) / 2) {
                    q[y][x] = 1;
                    p[y][x] = 1;
                    -- od[j].first;
                    -- id;
                    break;
                }
            }
        }
        for (int j = 0 ; j < i ; ++ j) {
            int y = od[j].second;
            if (!q[y][x]) {
                p[x][y] = 1;
            }
        }
    }


    for (int i = 0 ; i < n ; ++ i) {
        for (int j = 0 ; j < n ; ++ j) {
            printf("%d" , p[i][j]);
        }
        puts("");
    }
}