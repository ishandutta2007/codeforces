#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
const int Q = 998244353;

int a[N] , n;
int f[2][N][11];

void update(int &A , int B) {
    A += B;
    if (A >= Q) {
        A -= Q;
    }
}
void work() {
    scanf("%d" , &n);

    vector<int> odd , even;
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i]);
        static char str[20];
        sprintf(str , "%d" , a[i]);
        int len = strlen(str);
        a[i] %= 11;
        if (len % 2 == 0) {
            even.emplace_back(a[i]);
        } else {
            odd.emplace_back(a[i]);
        }
    }

    int cur = 0 , nxt = 1;
    memset(f , 0 , sizeof(f));
    f[cur][0][0] = 1;
    for (auto x : odd) {
        memset(f[nxt] , 0 , sizeof(f[nxt]));
        for (int i = 0 ; i <= n ; ++ i) {
            for (int j = 0 ; j < 11 ; ++ j) {
                if (!f[cur][i][j]) continue;
                update(f[nxt][i + 1][(j + x) % 11] , f[cur][i][j]);
                update(f[nxt][i][(j + 11 - x) % 11] , f[cur][i][j]);
            }
        }
        swap(cur , nxt);
    }
    int delta = 1;
    for (int i = 1 ; i <= int(odd.size()) / 2 ; ++ i) {
        delta = (long long) delta * i % Q;
    }
    for (int i = 1 ; i <= int(odd.size() + 1) / 2 ; ++ i) {
        delta = (long long) delta * i % Q;
    }
    for (int i = 0 ; i <= n ; ++ i) {
        for (int j = 0 ; j < 11 ; ++ j) {
            if (i != (odd.size() + 1) / 2) {
                f[cur][i][j] = 0;
            } else {
                f[cur][i][j] = (long long)f[cur][i][j] * delta % Q;
            }
        }
    }
    int cnt = odd.size();
    for (auto &x : even) {
        memset(f[nxt] , 0 , sizeof(f[nxt]));
        for (int i = 0 ; i <= n ; ++ i) {
            for (int j = 0 ; j < 11 ; ++ j) {
                if (!f[cur][i][j]) continue;
                update(f[nxt][i + 1][(j + 11 - x) % 11] , (long long)f[cur][i][j] * i % Q);
                update(f[nxt][i][(j + x) % 11] , (long long)f[cur][i][j] * (cnt - i + 1) % Q);
            }
        }
        ++ cnt;
        swap(cur , nxt);
    }
    int res = 0;
    for (int i = 0 ; i <= n ; ++ i) {
        update(res , f[cur][i][0]);
    }
    cout << res << endl;
}

int main() {
    int T;
    scanf("%d" , &T);
    while (T --) {
        work();
    }
}