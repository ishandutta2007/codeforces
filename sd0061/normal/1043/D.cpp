#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n , m;
int a[N];
int nxt[N] , deg[N];

int main() {
    scanf("%d%d" , &n , &m);
    for (int i = 0 ; i < m ; ++ i) {
        for (int j = 0 ; j < n ; ++ j) {
            scanf("%d" , &a[j]);
        }
        a[n] = n + 1;
        for (int j = 0 ; j < n ; ++ j) {
            if (!nxt[a[j]]) {
                nxt[a[j]] = a[j + 1];
            } else if (nxt[a[j]] != a[j + 1]) {
                nxt[a[j]] = -1;
            }
        }
    }
    for (int i = 1 ; i <= n ; ++ i) {
        //cout << i << nxt[i] << endl;
        if (~nxt[i]) {
            ++ deg[nxt[i]];
        }
        if (nxt[i] > n) nxt[i] = -1;
    }
    long long sum = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        if (!deg[i]) {
            int x = i , y = 0;
            while (~x) {
                ++ y;
                x = nxt[x];
            }
            sum += 1LL * y * (y + 1) / 2;
        }
    }
    cout << sum << endl;
}