#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <stack>
#include <cstring>
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

int n;
int a[1005];

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

struct Query {
    int l, r, id;
};

unordered_map<int, bool, custom_hash> exists;
unordered_map<int, int, custom_hash> numcnt;
unordered_map<int, int, custom_hash> numidx;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    int ans = 0;
    vector<int> vals;
    for (int i = 1; i <= n; i++) {
        numcnt[a[i]]++;
        numidx[a[i]] = 0;
        exists[a[i]] = true;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (a[i] == 0 && a[j] == 0) {
                ans = max(ans, numcnt[0]);
                continue;
            }
            int seqlen = 2;
            numidx[a[i]]++; numidx[a[j]]++;
            int x = a[i]; int y = a[j];
            while (true) {
                int newv = x + y;
                if (numidx[newv] >= numcnt[newv]) {
                    break;
                } else {
                    numidx[newv]++;
                    x = y; y = newv;
                    seqlen++;
                }
            }
            ans = max(ans, seqlen);
            x = a[i]; y = a[j];
            numidx[x] = numidx[y] = 0;
            for (int k = 3; k <= seqlen; k++) {
                int newv = x + y;
                x = y; y = newv;
                numidx[newv] = 0;
            }
            //printf("\n");
        }
    }
    printf("%d", ans);
    return 0;
}