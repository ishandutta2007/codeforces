#include <cstdio>
#include <chrono>
#include <unordered_map>
using namespace std;
const int N = 1e3 + 1, M = 20;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int n, m, c[N][M], cnt[N];
long long val[N];
unordered_map<long long, int, custom_hash> mp;

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++){
        long long tmp = 0;
        for (int j = 0; j < m; j++){
            scanf("%d", &c[i][j]);
            tmp |= (long long)c[i][j] << (j << 1);
        }
        mp[tmp] = i;
    }
    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i; j++){
            long long tmp = 0;
            for (int k = 0; k < m; k++){
                tmp |= (long long)(c[i][k] == c[j][k] ? c[i][k] : ((c[i][k] + 1) ^ (c[j][k] + 1)) - 1) << (k << 1);
            }
            cnt[mp[tmp]]++;
        }
    long long ans = 0;
    for (int i = 1; i <= n; i++){
        ans += 1ll * cnt[i] * (cnt[i] - 1) / 2;
    }
    printf("%lld", ans);
    return 0;
}