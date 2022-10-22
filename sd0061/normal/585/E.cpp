#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 500005;
const int M = 1e7 + 5;
const int Q = 1e9 + 7;
int n , m , a[N] , power[N];
int fac[M] , mu[M] , prime[M] , tot , cnt[M];
bool f[M];
int F[256] , t;
void dfs(int k , int x , vector<int>& P) {
    if (k == P.size()) {
        F[t ++] = x;
    } else {
        dfs(k + 1 , x , P);
        dfs(k + 1 , x * P[k] , P);
    }
}

int main() {
    scanf("%d" , &n);
    power[0] = 1;
    for (int i = 0 ; i < n ; ++ i) {
        power[i + 1] = power[i] * 2 % Q;
        scanf("%d" , &a[i]);
        m = max(m , a[i]);
    }
    mu[1] = 1;
    for (int i = 2 ; i <= m ; ++ i) {
        if (!f[i]) {
            prime[tot ++] = i;
            fac[i] = i;
            mu[i] = -1;
        }
        for (int j = 0 ; j < tot ; ++ j) {
            int x = i * prime[j];
            if (x > m) break;
            f[x] = 1;
            fac[x] = prime[j];
            if (i % prime[j] == 0) {
                mu[x] = 0;
                break;
            } else {
                mu[x] = -mu[i];
            }
        }
    }
    for (int i = 0 ; i < n ; ++ i) {
        vector<int> P;
        int x = a[i];
        while (x > 1) {
            P.push_back(fac[x]);
            x /= fac[x];
        }
        P.resize(unique(P.begin() , P.end()) - P.begin());
        t = 0;
        dfs(0 , 1 , P);
        
        for (int j = 0 ; j < t ; ++ j) {
            int it = F[j];
            ++ cnt[it];
        }
    }
    int sum = 0;
    for (int i = 1 ; i <= m ; ++ i) {
        sum += mu[i] * (power[cnt[i]] - 1);
        sum = (sum % Q + Q) % Q;
    }
    int res = 0;
    for (int i = 0 ; i < n ; ++ i) {
        vector<int> P;
        int x = a[i];
        while (x > 1) {
            P.push_back(fac[x]);
            x /= fac[x];
        }
        P.resize(unique(P.begin() , P.end()) - P.begin());
        t = 0;
        dfs(0 , 1 , P);  
        for (int j = 0 ; j < t ; ++ j) {
            int it = F[j];
            sum -= mu[it] * (power[cnt[it]] - 1);
            sum = (sum % Q + Q) % Q;
            -- cnt[it];
            sum += mu[it] * (power[cnt[it]] - 1);
            sum = (sum % Q + Q) % Q;
            res += mu[it] * (power[cnt[it]] - 1);
            res = (res % Q + Q) % Q;
        }
        res += Q - sum , res %= Q;
        for (int j = 0 ; j < t ; ++ j) {
            int it = F[j];
            sum -= mu[it] * (power[cnt[it]] - 1);
            sum = (sum % Q + Q) % Q;
            ++ cnt[it];
            sum += mu[it] * (power[cnt[it]] - 1);
            sum = (sum % Q + Q) % Q;
        }        
    }
    printf("%d\n" , res);
    return 0;
}