#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000005;
const LL Q = 1e9 + 7;
const LL MAGIC = 29;
int n , m , p;
LL power[N] , Hash[N];
char str[N];
int a[N] , b[N];

void work() {
    int i , j;
    scanf("%d%d",&n,&m);
    scanf("%s" , str);
    p = strlen(str);
    memset(b , -1 , sizeof(b));
    for (i = 0 ; i < m ; ++ i) {
        scanf("%d" , &a[i]);
        b[a[i]] = 0;
    }
    for (i = 1 ; i <= n ; ++ i) {
        if (!~b[i] && ~b[i - 1] && b[i - 1] + 1 < p)
            b[i] = b[i - 1] + 1;
    }
    power[0] = 1;
    int cnt = 0;
    for (i = 1 ; i <= n ; ++ i) {
        power[i] = power[i - 1] * MAGIC % Q;
        Hash[i] = (Hash[i - 1] * MAGIC + (!~b[i] ? 27 : str[b[i]] - 'a' + 1)) % Q;
        cnt += !~b[i];
        //cout << str[b[i]] << endl;
    }
    LL W = 0;
    for (i = 0 ; i < p ; ++ i)
        W = (W * MAGIC + (str[i] - 'a' + 1)) % Q;
    //cout << W << endl;
    for (i = 0 ; i < m ; ++ i) {
        int x = a[i];
        LL H = (Hash[x + p - 1] - power[p] * Hash[x - 1] % Q + Q) % Q;
        if (H != W) {
            puts("0");
            return;
        }
    }
    LL res = 1;
    while (cnt --)
        res *= 26 , res %= Q;
    cout << res << endl;
}

int main() {
    work();
    return 0;
}