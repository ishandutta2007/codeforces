#include <cstdio>
#include <algorithm>
#include <set>
//
using namespace std;

/* make sure to modify array sizes if modifying BLK */
#define BLK 200
#define ll long long

int n, m;
int a[100005];
int pre[100005];
int lastpos[100005];
int idx[505][205];
int psum[505][205];
int blksiz[505];

set<int> position[100005];

bool cmp(int A, int b)
{
    return pre[A] > pre[b];
}

void build(int blkid)
{
    int first = max(blkid * BLK, 1);
    int last = min((blkid + 1) * BLK - 1, n);
    blksiz[blkid] = last - first + 1;
    for (int i = first; i <= last; i++) {
        idx[blkid][i - first + 1] = i;
    }
    sort(idx[blkid] + 1, idx[blkid] + last - first + 2, cmp);
    for (int i = 1; i <= last - first + 1; i++) {
        psum[blkid][i] = psum[blkid][i-1] + idx[blkid][i] - pre[idx[blkid][i]];
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        position[i].insert(0);
        scanf("%d", a + i);
        pre[i] = lastpos[a[i]];
        lastpos[a[i]] = i;
        position[a[i]].insert(i);
    }
    for (int i = 0; i <= n / BLK; i++) build(i);
    for (int op = 1; op <= m; op++) {
        int type, x, y;
        scanf("%d%d%d", &type, &x, &y);
        if (type == 1) {
            set<int>::iterator it = position[a[x]].upper_bound(x);
            if (it != position[a[x]].end()) {
                //fprintf(stderr, "exec a");
                int nxtpos = *it; pre[nxtpos] = pre[x]; build(nxtpos / BLK);
            }
            position[a[x]].erase(x);

            it = position[y].lower_bound(x);
            //fprintf(stderr, "exec b");
            if (it != position[y].end()) {
                //fprintf(stderr, "exec c");
                int nnxtpos = *it; pre[nnxtpos] = x; build(nnxtpos / BLK);
            }
            //fprintf(stderr, "exec d");

            it--; pre[x] = *it; build(x / BLK);

            position[y].insert(x);
            a[x] = y;
        } else {
            ll ans = 0;
            int curl = x, curr = y;
            if (x / BLK == y / BLK) {
                for (int i = x; i <= y; i++) {
                    if (pre[i] >= x) ans += i - pre[i];
                }
            } else {
                while (curr / BLK == y / BLK) {
                    if (pre[curr] >= x) ans += curr - pre[curr];
                    curr--;
                }
                while (curl / BLK == x / BLK) {
                    if (pre[curl] >= x) ans += curl - pre[curl];
                    curl++;
                }
                for (int cblk = curl / BLK; cblk <= curr / BLK; cblk++) {
                    int l = 0; int r = blksiz[cblk];
                    while (l < r) {
                        int mid = (l + r) / 2 + 1;
                        if (mid == 0 || pre[idx[cblk][mid]] >= x) {
                            l = mid;
                        } else {
                            r = mid - 1;
                        }
                    }
                    ans += (ll)psum[cblk][l];
                }
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}