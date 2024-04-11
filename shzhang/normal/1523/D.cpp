#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>
#include <random>
#include <chrono>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

int n, m, p;
ll mask[200005];
char s[65];

int f[35000];

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

bool final[65];

int main()
{
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        for (ll j = 0; j < m; j++) {
            if (s[j] == '1') mask[i] |= (1LL << j);
        }
    }
    int ans = 0;
    vector<int> curans;
    for (int att = 1; att <= 30; att++) {
        int x = (rng() % n) + 1;
        vector<ll> bits, bits2;
        for (ll i = 0; i < m; i++) {
            if (mask[x] & (1LL << i)) {
                bits.push_back(1LL << i);
                bits2.push_back(i);
            }
        }
        int cnt = (int)bits.size();
        for (int i = 0; i < (1 << cnt); i++) f[i] = 0;
        for (int i = 1; i <= n; i++) {
            int badmask = (1 << cnt) - 1;
            for (int j = 0; j < cnt; j++) {
                if (mask[i] & bits[j]) {
                    badmask -= (1 << j);
                }
            }
            f[badmask]++;
        }
        for (int i = 0; i < cnt; i++) {
            for (int j = 0; j < (1 << cnt); j++) {
                if (j & (1 << i)) {
                    f[j] += f[j ^ (1 << i)];
                }
            }
        }
        for (int i = 0; i < (1 << cnt); i++) {
            int amt = 0;
            for (int j = 0; j < cnt; j++) {
                if (i & (1 << j)) amt++;
            }
            if (amt > ans && f[(1 << cnt) - 1 - i] * 2 >= n) {
                ans = amt;
                curans.clear();
                for (int j = 0; j < cnt; j++) {
                    if (i & (1 << j)) {
                        curans.push_back(bits2[j]);
                    }
                }
            }
        }
    }
    for (int i = 0; i < curans.size(); i++) {
        final[curans[i]] = true;
    }
    for (int i = 0; i < m; i++) {
        printf("%d", final[i] ? 1 : 0);
    }
    return 0;
}