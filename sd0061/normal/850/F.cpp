#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;
const int Q = 1e9 + 7;

int inverse(int x) {
    return x == 1 ? x : (LL)(Q - Q / x) * inverse(Q % x) % Q;
}

int n , c , a[N];
int f[N];
int main() {
    scanf("%d" , &c);
    for (int i = 0 ; i < c ; ++ i) {
        scanf("%d" , &a[i]);
        n += a[i];
    }
    f[0] = 0;
    f[1] = (LL)(n - 1) * (n - 1) % Q * inverse(n) % Q;
    for (int i = 2 ; i < N && i <= n ; ++ i) {
        //cout << n - i + 1 << endl;
        LL delta = 2 * f[i - 1] - f[i - 2] - (LL)(n - 1) * inverse(n - i + 1) % Q;
        delta = (Q + delta % Q) % Q;
        f[i] = delta;
    }
    int res = 0;
    for (int i = 0 ; i < c ; ++ i) {
        res += f[a[i]];
        res %= Q;
    }
    cout << res << endl;
}