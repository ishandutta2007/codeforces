#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1000005;
const int Q = 1e9 + 7;
typedef long long LL;

int n , K , f[N];

int power(int a , int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = (LL)res * a % Q;
        a = (LL)a * a % Q , b >>= 1;
    }
    return res;
}
int inverse(int x) {
    return x == 1 ? x : (LL)(Q - Q / x) * inverse(Q % x) % Q;
}

void work() {
    scanf("%d%d" , &n , &K);
    for (int i = 1 ; i <= K + 1 ; ++ i) {
        f[i] = (f[i - 1] + power(i , K)) % Q;
    }
    if (n <= K + 1) {
        printf("%d\n" , f[n]);
        return;
    }
    int A = 1 , B = 1;
    for (int i = 0 ; i <= K + 1; ++ i)
        A = (LL)A * (n - i) % Q;
    for (int i = 1 ; i <= K + 1; ++ i)
        B = (LL)B * (Q - i) % Q;
    int res = 0;
    for (int i = 0 ; i <= K + 1; ++ i) {
        int C = (LL)A * inverse((LL)(n - i) * B % Q) % Q;
        res += (LL)f[i] * C % Q , res %= Q;
        if (i == K + 1) break;
        B = (LL)B * (i + 1) % Q * inverse(Q - (K + 1 - i)) % Q;
    }
    printf("%d\n" , res);
}

int main() {
    work();
    return 0;
}