#include <cstdio>
#include <algorithm>

using namespace std;

#define MOD 998244353

#define BLKSIZE 350
#define BLKMAX (BLKSIZE+5)

/* indices of block members, in order, from low to high, of cur[x] */
int blkbase[BLKMAX][BLKMAX];
/* sum of the f[x] values for the x's in the block with the lowest cur values */
int blkpsum[BLKMAX][BLKMAX];
int f[100005];

int n, k;
int a[100005];
int previ[100005];
int previval[100005];
int blk[100005];
int blkbegin[100005];
int blkend[1000005];
//
int cur[100005];
int cur_offset[BLKMAX];
int cur_cnt[BLKMAX];

int cur_total = 0;

int blkcnt;

bool cmp(int A, int B)
{
    return cur[A] < cur[B];
}

void rebuild(int block)
{
    for (int i = blkbegin[block], j = 1; j <= BLKSIZE; i++, j++) {
        blkbase[block][j] = i;
    }
    sort(blkbase[block] + 1, blkbase[block] + BLKSIZE + 1, cmp);
    int r = 0;
    for (int i = 1; i <= BLKSIZE; i++) {
        blkpsum[block][i] = blkpsum[block][i-1] + f[blkbase[block][i]-1];
        if (blkpsum[block][i] >= MOD) blkpsum[block][i] -= MOD;
        if (cur[blkbase[block][i]] <= k) r = i;
    }
    //printf("Rebuild %d: curtotal %d ", block, cur_total);
    cur_total -= cur_cnt[block];
    cur_total += blkpsum[block][r];
    cur_cnt[block] = blkpsum[block][r];
    cur_total %= MOD; cur_total += MOD; cur_total %= MOD;
    //printf("-> %d\n", cur_total);
}

void update(int l, int r, int change)
{
    //printf("update [%d, %d], %d\n", l, r, change);
    for (int i = blk[l] + 1; i < blk[r]; i++) {
        cur_offset[i] += change;
        int L = 0, R = BLKSIZE;
        /* find last one meeting requirements */
        while (L < R) {
            int mid = (L + R) / 2 + 1;
            if (cur[blkbase[i][mid]] + cur_offset[i] <= k) {
                L = mid;
            } else {
                R = mid - 1;
            }
        }
        cur_total -= cur_cnt[i];
        cur_total += blkpsum[i][R];
        cur_cnt[i] = blkpsum[i][R];
        cur_total %= MOD; cur_total += MOD; cur_total %= MOD;
    }
    for (int i = blkbegin[blk[l]]; i <= blkend[blk[l]]; i++) {
        cur[i] += cur_offset[blk[l]];
    }
    cur_offset[blk[l]] = 0;
    for (int i = l; i <= blkend[blk[l]] && i <= r; i++) {
        cur[i] += change;
    }
    //printf("before rebuild: ");
    for (int j = 1; j <= n; j++) {
        //printf("%d ", cur[j]);
    }
    rebuild(blk[l]);
    if (blk[l] != blk[r]) {
        for (int i = blkbegin[blk[r]]; i <= blkend[blk[r]]; i++) {
            cur[i] += cur_offset[blk[r]];
        }
        cur_offset[blk[r]] = 0;
        for (int i = blkbegin[blk[r]]; i <= r; i++) {
            cur[i] += change;
        }
        rebuild(blk[r]);
    }
}

int main()
{
    cur[0] = -10000000;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        previ[i] = previval[a[i]];
        previval[a[i]] = i;
    }

    for (int i = 1; i <= 100000; i++) blk[i] = (i-1) / BLKSIZE + 1;
    for (int i = 1; i <= 350; i++) {
        blkbegin[i] = (i - 1) * BLKSIZE + 1;
        blkend[i] = blkbegin[i] + BLKSIZE - 1;
        for (int j = (i - 1) * BLKSIZE + 1, x = 1; x <= BLKSIZE; j++, x++) {
            blkbase[i][x] = j;
        }
    }
    //printf(" %d [%d %d] %d\n", blkbegin[1], blkend[1], blk[1]);
    f[0] = 1;
    rebuild(1);
    for (int i = 1; i <= n; i++) {
        update(previ[i] + 1, i, 1);
        if (previ[i]) update(previ[previ[i]] + 1, previ[i], -1);
        f[i] = cur_total;
        //printf("f[%d] = %d\n", i, f[i]);
        for (int j = 0; j < BLKSIZE; j++) {
            cur[blkbegin[blk[i+1]] + j] += cur_offset[blk[i+1]];
        }
        cur_offset[blk[i+1]] = 0;
        for (int j = 1; j <= n; j++) {
            //printf("%d ", cur[j]);
        }
        //printf("\n");
        rebuild(blk[i+1]);
    }
    printf("%d", f[n]);
    return 0;
}