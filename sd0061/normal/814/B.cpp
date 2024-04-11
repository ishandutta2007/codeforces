#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n , a[N] , b[N] , res[N];
bool f[N];

void dfs(int k , int x , int y) {
    if (k == n + 1) {
        if (x == n - 1 && y == n - 1) {
            for (int i = 1 ; i <= n ; ++ i) {
                printf("%d%c" , res[i] , " \n"[i == n]);
            }
            exit(0);
        }
    } else {
        if (res[k]) {
            dfs(k + 1 , x + 1 , y + 1);
        } else {
            for (int i = 1 ; i <= n ; ++ i) {
                if (!f[i]) {
                    res[k] = i;
                    f[i] = 1;
                    dfs(k + 1 , x + (i == a[k]) , y + (i == b[k]));
                    f[i] = 0;
                    res[k] = 0;
                }
            }
        }

    }
}

int main() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> b[i];
        if (a[i] == b[i]) {
            f[a[i]] = 1;
            res[i] = a[i];
        }
    }
    dfs(1 , 0 , 0);
}