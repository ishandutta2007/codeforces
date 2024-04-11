#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <cinttypes>

using namespace std;

#define MAXN 1000010
#define F first
#define S second

int64_t s64() { int64_t res; scanf("%" PRId64, &res); return res; }
void p64(int64_t res) { printf("%" PRId64, res); }

int inp[MAXN];
int seg[MAXN];

void build(int x, int l, int r)
{
    if (l+1 == r)
    {
        seg[x] = inp[l];
        return;
    }
    int m = (l+r)/2;

    build(x*2, l, m);
    build(x*2+1, m, r);
    seg[x] = max(seg[x*2], seg[x*2+1]);
}
int search(int x, int l, int r, int il, int ir)
{
    if (l == il && r == ir)
    {
        //printf("seg %d %d %d %d %d -> %d\n", x,l,r,il,ir,seg[x]);
        return seg[x];
    }
    if (il >= r || ir <= l || ir <= il)
    {
        return 0;
    }

    int ans = 0;
    int m = (l+r) / 2;
    ans = max(ans, search(x*2, l, m, il, min(ir,m)));
    ans = max(ans, search(x*2+1, m, r, max(il,m), ir));
    return ans;
}
int main()
{
    int casN=1;
    //scanf("%d", &casN);
    for (int cas = 0; cas < casN; cas++)
    {
        int n, m;

        scanf("%d%d", &n,&m);
        for (int i = 0; i <= 4*m; i++) seg[i] = 0;
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &inp[i]);
        }

        build(1, 0, m);

        int q;
        scanf("%d", &q);

        for (int qn = 0; qn < q; qn++)
        {
            int p[2][2], k;
            scanf("%d%d%d%d%d",&p[0][1],&p[0][0], &p[1][1],&p[1][0], &k);

            bool ans = true;
            if ((p[0][0] - p[1][0]) % k != 0 || (p[0][1] - p[1][1]) % k != 0)
            {
                ans = false;
            }
            else if (p[0][0] != p[1][0])
            {
                int l = p[0][0], r = p[1][0];
                if (l > r) swap(l,r);
                int mx = search(1, 0, m, l-1, r-1);
                int target = p[0][1] + ((n - p[0][1])/k) * k;
                ans = mx < target;
            }
            printf("%s\n", ans ? "YES" : "NO");
        }




    }

    return 0;
}