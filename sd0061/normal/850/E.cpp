#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 20;
const int Q = 1e9 + 7;

int n , f[1 << N] , cnt[1 << N];
char str[(1 << N) + 5];

int power[7][N + 1];

int inverse(int x) {
    return x == 1 ? x : (LL)(Q - Q / x) * inverse(Q % x) % Q;
}
void FWT(int a[] , int len , int oper) {
    for (int k = 0 ; 1 << k < len ; ++ k) {
        for (int i = 0 ; i < len ; ++ i) {
            if (~i >> k & 1) {
                int j = i ^ (1 << k);
                int x = (a[i] + Q - a[j]) % Q;
                int y = (a[i] + a[j]) % Q;
                if (oper == -1) {
                    x = (Q - x) % Q;
                    swap(x , y);
                }
                a[i] = x;
                a[j] = y;
            }
        }
    }
}


int main() {
    scanf("%d%s" , &n , str);
    for (int i = 0 ; i <= 6 ; ++ i) {
        power[i][0] = 1;
        for (int j = 1 ; j <= n ; ++ j) {
            power[i][j] = (LL)power[i][j - 1] * i % Q;
        }
    }
    for (int i = 0 ; i < 1 << n ; ++ i) {
        f[i] = str[i] - '0';
    }
    for (int i = 1 ; i < 1 << n ; ++ i) {
        cnt[i] = cnt[i & (i - 1)] + 1;
    }
    FWT(f , 1 << n , 1);
    for (int i = 0 ; i < 1 << n ; ++ i) {
        f[i] = (LL)f[i] * f[i] % Q;
    }
    FWT(f , 1 << n , -1);
    int inv = inverse(1 << n);
    for (int i = 0 ; i < 1 << n ; ++ i) {
        f[i] = (LL)f[i] * inv % Q;
    }
    //for (int x = 0 ; x <= 6 ; ++ x) {
    //  for (int y = 0 ; y <= 6 ; ++ y) {
    int res = 0;
    for (int i = 0 ; i < 1 << n ; ++ i) {
        // printf("%d %d\n" , i , f[i]);
        res += (LL)f[i] * power[1][cnt[i]] % Q * power[2][n - cnt[i]] % Q;
        res %= Q;
    }
    //cout << x << ' ' << y << ' ';
    res = res * 3LL % Q;
    cout << res << endl;
    //     }}
}