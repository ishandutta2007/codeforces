#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

const int N = 100005;
const int K = 105;
const int MOD = 1000000007;
vector<pair<int, int> > events[N];
int n, m;
int ans[N], mark[K][N];
long long fac[N * 2], rev[N * 2];

int C(int n, int m) {
    return 1LL * fac[n] * rev[m] % MOD * rev[n - m] % MOD;
}

int power(int a, int b) {
    if (b == 0)
        return 1;
    if (b == 1)
        return a % MOD;
    
    int tmp = power(a, b / 2);
    if (b % 2 == 0) {
        return 1LL * tmp * tmp % MOD;
    } else {
        return 1LL * tmp * tmp % MOD * a % MOD;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    fac[0] = rev[0] = 1;
    
    for(int i = 1; i <= n + 150; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        rev[i] = 1LL * power(i, MOD - 2) * rev[i - 1] % MOD;
    }
    for(int i = 1; i <= n; i++)
        scanf("%d", &ans[i]);
    for(int i = 1; i <= m; i++) {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        events[l].push_back(make_pair(k, -1));
        events[r + 1].push_back(make_pair(k, r - l + 1));
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 100; j >= 0; j--) {
            (mark[j][i] += mark[j][i - 1]) %= MOD;
            (mark[j][i] += mark[j + 1][i - 1]) %= MOD;
        }
        
        for(int j = 0; j < (int)events[i].size(); j++) {
            pair<int, int> t = events[i][j];
            if (t.second < 0) {
                for(int k = 0; k <= t.first; k++) {
                    (mark[k][i] += C(t.first, t.first - k)) %= MOD;
                }
            } else {
                for(int k = 0; k <= t.first; k++) {
                    (mark[k][i] -= C(t.first + t.second, t.first - k)) %= MOD;
                    (mark[k][i] += MOD) %= MOD;
                }
            }
        }
    }
    
    //printf("%d %d\n", C(1, 1), mark[0][1]);
    
    for(int i = 1; i <= n; i++) {
        printf("%d ", (mark[0][i] + ans[i]) % MOD);
    }
    printf("\n");
    
    return 0;
}