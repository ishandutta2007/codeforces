#include <cstdio>
#include <cstring>
#include <algorithm>
#define P 998244353

using namespace std;

typedef long long ll;

ll n, a, b, F[2222], G[2222], C[2222][2222], Rev1[2222][2222], Rev2[2222][2222], cyc[2222], mulA[2222], mulB[2222];
ll asdfg[12345678];
ll powmod(ll x, ll y = P - 2, ll p = P) {
    ll ans = 1;
    while(y) {
        if(y & 1) ans = ans * x % p;
        x = x * x % p;
        y >>= 1;
    }
    return ans;
}

int main() {
    for(int i = 0; i <= 2000; i++)
        for(int j = 0; j <= i; j++)
            C[i][j] = !j ? 1 : (C[i - 1][j - 1] + C[i - 1][j]) % P;
    scanf("%lld%lld%lld", &n, &a, &b);
    b -= a;
    for(int i = 0; i < 2222; i++) {
        mulA[i] = !i ? 1 : mulA[i - 1] * a % P * powmod(a + b) % P;
        mulB[i] = !i ? 1 : mulB[i - 1] * b % P * powmod(a + b) % P;
    }
    /*Rev[0] = 1;
    for(int i = 1; i <= 2000; i++)
        Rev[i] = Rev[i - 1] * (mulA[i + 1] - mulB[i - 1]) % P * powmod(a - b) % P;*/
    Rev1[0][0] = 1;
    for(int i = 0; i <= 2000; i++)
        for(int j = 0; j <= i; j++) {
            Rev1[i + 1][j + 1] = (Rev1[i + 1][j + 1] + Rev1[i][j] * mulB[i - j]) % P;
            Rev1[i + 1][j] = (Rev1[i + 1][j] + Rev1[i][j] * mulA[j]) % P;
        }
    /*Rev2[1][1] = 1;
    for(int i = 1; i <= 2000; i++)
        for(int j = 1; j <= i; j++) {
            Rev2[i + 1][j + 1] = (Rev2[i + 1][j + 1] + Rev2[i][j] * mulB[i - j]) % P;
            Rev2[i + 1][j] = (Rev2[i + 1][j] + Rev2[i][j] * mulA[i]) % P;
        }
    cyc[1] = 1;
    for(int i = 2; i <= 2000; i++) {
        cyc[i] = 1;
        for(int j = 1; j < i; j++)
            cyc[i] = (cyc[i] - cyc[j] * Rev2[i][j]) % P;
    }
    F[1] = 0;
    for(int i = 2; i <= 2000; i++) {
        for(int j = 1; j <= i; j++)
            F[i] = (F[i] + F[j] * Rev1[i][j]) % P;
        F[i] = (F[i] + powmod(1 - cyc[i])) % P;
    }*/
    cyc[1] = 1;
    for(int i = 2; i <= 2000; i++) {
        cyc[i] = 1;
        for(int j = 1; j < i; j++)
            cyc[i] = (cyc[i] - cyc[j] * Rev1[i][j]) % P;
    }
    F[1] = 0;
    G[1] = 0;
    for(int i = 2; i <= 2000; i++) {
        F[i] = (powmod(1 - cyc[i])) * (i * (i - 1) / 2) % P;
        for(int j = 1; j < i; j++)
            G[i] = (G[i] + (F[j] + (G[i - j] + F[i - j] * cyc[i - j] % P)) * cyc[j] % P * Rev1[i][j]) % P;
        F[i] = (F[i] + G[i] * powmod(1 - cyc[i])) % P;
    }
    printf("%lld\n", ((F[n]) % P + P) % P);
    return 0;
}