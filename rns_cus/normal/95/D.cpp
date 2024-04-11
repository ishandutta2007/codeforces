#include <bits/stdc++.h>

using namespace std;

#define N 1010
#define mod 1000000007

int n, k;
int p[N], f[N], p8[N], g[N];
char A[N], B[N];

void add(int &x, int y) {
    x += y; if(x >= mod) x -= mod;
}

int calc() {
    int bf = - N;
    int sum = 0;
    int len = strlen(B);
    for(int i = 0; i < len; i ++) {
        sum = (10LL * sum + B[i] - '0') % mod;
    }
    add(sum, 1);
    int rt = 0;
    bool ok = 1;
    for(int i = 0; i < len; i ++) {
        for(int j = 0; j < B[i] - '0'; j ++) {
            if(j == 4 || j == 7) {
                if(i - bf >= k) {
                    if(i + k < len) add(rt, 1LL * p8[k - 1] * f[len - i - k] % mod);
                    else add(rt, p8[len - i - 1]);
                }
            } else {
                if(bf + k <= i) add(rt, f[len - i - 1]);
                else {
                    if(bf + k >= len) {
                        add(rt, p8[len - i - 1]);
                    } else {
                        add(rt, 1LL * p8[bf + k - i - 1] * f[len - bf - k] % mod);
                    }
                }
            }
        }
        if(B[i] == '4' || B[i] == '7') {
            if(i - bf < k) {
                ok = 0;
                break;
            }
            bf = i;
        }
        //printf("%d\n", rt);
    }
    //printf("%d %d\n", sum, rt);
    if(ok) add(rt, 1);
    sum -= rt;
    if(sum < 0) sum += mod;
    return sum;
}

void run() {
    int x = calc();
    int y;
    if(strlen(A) == 1 && A[0] == '1') y = 0;
    else {
        int l = strlen(A);
        for(int i = l - 1; i >= 0; i --) {
            if(A[i] != '0') {
                A[i] --; break;
            } else A[i] = '9';
        }
        if(A[0] == '0') strcpy(B, A + 1); else strcpy(B, A);
        y = calc();
    }
    x -= y;
    if(x < 0) x += mod;
    printf("%d\n", x);
}

void init() {
    p[0] = 1; p8[0] = 1;
    for(int i = 1; i < N; i ++) {
        p[i] = 10LL * p[i - 1] % mod;
        p8[i] = 8LL * p8[i - 1] % mod;
    }
    f[0] = 1;
    f[1] = 10;
    for(int i = 2; i < N; i ++) {
        f[i] = 8LL * f[i - 1] % mod;
        if(i <= k) {
            add(f[i], 2LL * p8[i - 1] % mod);
        } else {
            add(f[i], 2LL * f[i - k] * p8[k - 1] % mod);
        }
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    k ++;
    init();
    for(int i = 1; i <= n; i ++) {
        scanf("%s%s", A, B);
        run();
    }
    return 0;
}