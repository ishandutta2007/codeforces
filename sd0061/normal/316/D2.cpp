#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000005;
const int Q = 1e9 + 7;
int n , cnt[2];
LL I[N];
void work() {
    int i , x;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d",&x);
        ++ cnt[x - 1];
    }
    LL res = 1;
    for (i = cnt[0] + 1 ; i <= n ; ++ i)
        res *= i , res %= Q;
    I[0] = I[1] = 1;
    for (i = 2 ; i <= cnt[0] ; ++ i) {
        I[i] = I[i - 1];
        I[i] += (i - 1) * I[i - 2];
        I[i] %= Q;
    }
    res *= I[cnt[0]] , res %= Q;
    cout << res << endl;
}

int main() {
    work();
    return 0;
}