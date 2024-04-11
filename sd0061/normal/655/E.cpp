#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
const int N = 1000005;
const int Q = 1e9 + 7;

int n , m , K;
char str[N];
int f[N + N];
int vis[N];



int main() {

    scanf("%d%d" , &n , &K);
    scanf("%s" , str + 1);
    int m = strlen(str + 1);
    f[0] = 1;
    for (int i = 1 ; i <= m ; ++ i) {
        f[i] = f[i - 1] * 2 % Q;
        if (vis[str[i] - 'a']) {
            f[i] += (Q - f[vis[str[i] - 'a'] - 1]);
            f[i] %= Q;
        }
        vis[str[i] - 'a'] = i;
    }

    for (int i = m + 1 ; i <= m + n ; ++ i) {
        int c = 0;
        for (int k = 1 ; k < K ; ++ k) {
            if (vis[k] < vis[c])
                c = k;
        }
        f[i] = f[i - 1] * 2 % Q;
        if (vis[c]) {
            f[i] += (Q - f[vis[c] - 1]);
            f[i] %= Q;
        }
        vis[c] = i;
    }

    printf("%d\n" , f[m + n]);

    return 0;
}