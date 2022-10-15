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

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

#define BLKSIZE 200

int n, q;
int b[100005];
int blkid[100005];
int blkbegin[100005];
// for block i, minimum start value required for j increases
int mincnt[1000][1005];
int f[100005];

int fen[300005];

#define lowbit(x) ((x)&(-(x)))

int rquery(int* arr, int v)
{
    int ans = 0;
    while (v) {
        ans += arr[v]; v -= lowbit(v);
    }
    return ans;
}

void modify(int* arr, int loc, int val)
{
    //printf("%d %lld\n", loc, val);
    while (loc <= n) {
        arr[loc] += val; loc += lowbit(loc);
    }
}

void updateblock(int id)
{
    int start = max(id * BLKSIZE, 1);
    for (int i = start; blkid[i] == id; i++) {
        int x = 0; int curv = 0;
        for (int j = 16; j >= 0; j--) {
            int nx = x + (1 << j);
            if (nx <= n && curv + fen[nx] + nx <= b[i]) {
                x = nx; curv += fen[nx];
            }
        }
        f[i] = x + 1; if (f[i] <= n) modify(fen, f[i], 1);
    }
    vector<int> vals;
    for (int i = start; blkid[i] == id; i++) {
        vals.push_back(f[i]);
        if (f[i] <= n) modify(fen, f[i], -1);
    }
    sort(vals.begin(), vals.end());
    for (int i = 0; i < vals.size(); i++) {
        mincnt[id][i+1] = vals[i];
    }
    for (int i = vals.size() + 1; i <= BLKSIZE; i++) {
        mincnt[id][i] = 10000000;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", b + i);
    blkid[0] = blkid[n + 1] = -1;
    for (int i = 1; i <= n; i++) {
        blkid[i] = i / BLKSIZE;
        blkbegin[i] = (blkid[i-1] == blkid[i] ? blkbegin[i-1] : i);
    }
    for (int i = 0; i <= n / BLKSIZE; i++) {
        updateblock(i);
    }
    scanf("%d", &q);
    for (int qr = 1; qr <= q; qr++) {
        int typ; scanf("%d", &typ);
        if (typ == 1) {
            int x, y; scanf("%d%d", &x, &y);
            b[x] = y; updateblock(blkid[x]);
        } else {
            int x; scanf("%d", &x);
            int cur = b[x] + 1; int i;
            for (i = x + 1; blkid[i] == blkid[x]; i++) {
                if (cur > b[i]) cur++;
            }
            if (i <= n) {
                for (int j = blkid[i]; j <= n / BLKSIZE; j++) {
                    int l = 0; int r = BLKSIZE;
                    while (l < r) {
                        int mid = (l + r) / 2 + 1;
                        if (cur >= mincnt[j][mid]) {
                            l = mid;
                        } else {
                            r = mid - 1;
                        }
                    }
                    cur += l;
                }
            }
            printf("%d\n", n + 1 - cur);
        }
    }
    return 0;
}