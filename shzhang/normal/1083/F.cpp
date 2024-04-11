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

static inline int updiv(int x, int y)
{
    return x % y == 0 ? x / y : x / y + 1;
}

const int BLKSIZE = 450;

int ans = 0;
int badcnt = 0;

struct Chain {
    int size;
    int blocks;
    int* a;
    int* blkxor;
    int** freq;
    int poscnt;
};

Chain build(vector<int>& vec)
{
    Chain chain;
    chain.size = (int)vec.size();
    chain.blocks = updiv(chain.size, BLKSIZE);
    chain.a = new int[chain.size];
    for (int i = 0; i < chain.size; i++) chain.a[i] = vec[i];
    if (chain.blocks >= 2) {
        chain.blkxor = new int[chain.blocks];
        for (int i = 0; i < chain.blocks; i++) chain.blkxor[i] = 0;
        chain.freq = new int*[chain.blocks];
        for (int i = 0; i < chain.blocks; i++) {
            chain.freq[i] = new int[1 << 14];
            for (int j = 0; j < (1 << 14); j++) chain.freq[i][j] = 0;
        }
        for (int i = 0; i < chain.size; i++) {
            chain.freq[i / BLKSIZE][chain.a[i]]++;
        }
    }
    chain.poscnt = 0;
    for (int i = 0; i < chain.size; i++) {
        if (chain.a[i]) chain.poscnt++;
    }
    ans += chain.poscnt;
    if (chain.a[chain.size - 1]) badcnt++;
    return chain;
}

void modify(Chain& chain, int pos, int val)
{
    ans -= chain.poscnt;
    if (chain.blocks == 1) {
        if (chain.a[chain.size - 1]) badcnt--;
        for (int i = pos; i < chain.size; i++) {
            if (chain.a[i]) chain.poscnt--;
            chain.a[i] ^= val;
            if (chain.a[i]) chain.poscnt++;
        }
        if (chain.a[chain.size - 1]) badcnt++;
    } else {
        if (chain.a[chain.size - 1] ^ chain.blkxor[chain.blocks - 1]) badcnt--;
        int startblk = pos / BLKSIZE;
        while (pos < chain.size && pos / BLKSIZE == startblk) {
            if (chain.a[pos] ^ chain.blkxor[startblk]) chain.poscnt--;
            chain.freq[startblk][chain.a[pos]]--;
            chain.a[pos] ^= val;
            chain.freq[startblk][chain.a[pos]]++;
            if (chain.a[pos] ^ chain.blkxor[startblk]) chain.poscnt++;
            pos++;
        }
        if (pos < chain.size) {
            for (int blk = pos / BLKSIZE; blk < chain.blocks; blk++) {
                chain.poscnt += chain.freq[blk][chain.blkxor[blk]];
                chain.blkxor[blk] ^= val;
                chain.poscnt -= chain.freq[blk][chain.blkxor[blk]];
            }
        }
        if (chain.a[chain.size - 1] ^ chain.blkxor[chain.blocks - 1]) badcnt++;
    }
    ans += chain.poscnt;
}

int n, k, q;

int arr[200005];
int a[200005], b[200005];
Chain chains[200005];

void output_ans()
{
    if (badcnt) {
        printf("-1\n");
    } else {
        printf("%d\n", ans);
    }
}

int main()
{
    scanf("%d%d%d", &n, &k, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        arr[i] = a[i];
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", b + i);
        arr[i] ^= b[i];
    }
    for (int i = 0; i < k; i++) {
        vector<int> vec;
        for (int j = i; j <= n; j += k) {
            vec.push_back(arr[j] ^ (j ? arr[j-1] : 0));
        }
        for (int j = 1; j < vec.size(); j++) vec[j] ^= vec[j-1];
        chains[i] = build(vec);
    }
    output_ans();
    for (int qr = 1; qr <= q; qr++) {
        char arrid[5];
        int pos; int newv; int xorv;
        scanf("%s%d%d", arrid, &pos, &newv);
        pos--;
        if (arrid[0] == 'a') {
            xorv = newv ^ a[pos];
            a[pos] = newv;
        } else {
            xorv = newv ^ b[pos];
            b[pos] = newv;
        }
        modify(chains[pos % k], pos / k, xorv);
        modify(chains[(pos + 1) % k], (pos + 1) / k, xorv);
        output_ans();
    }
    return 0;
}