#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[200005];

struct Trap {
    int l, r, d;
};

vector<Trap> traps[200005];
vector<Trap> rs[200005];
int maxdanger[200005];

int m, n, k, t;

bool cmp(int A, int b)
{
    return A > b;
}

bool check(int cnt)
{
    int minv = a[cnt];
    int curpos = 0;
    int tim = 0;
    int mypos = 0;
    int maxmypos = 0;
    while (1) {
        while (curpos <= n) {
             bool good = true;
             for (int i = 0; i < traps[curpos+1].size(); i++) {
                 if (traps[curpos+1][i].r > maxmypos && traps[curpos+1][i].d > minv) good = false;
             }
             if (!good) break;
             curpos++, mypos++, tim++;
        }
        if (curpos >= n + 1) break;
        /*int remaining = 0;
        mypos++; maxmypos = max(mypos, maxmypos); tim += 2;
        while (mypos <= n) {
            for (int i = 0; i < traps[mypos].size(); i++) {
                if (traps[mypos][i].d > minv) remaining++;
            }
            for (int i = 0; i < rs[mypos].size(); i++) {
                if (rs[mypos][i].d > minv && rs[mypos][i].l > curpos) remaining--;
            }
            if (!remaining) break;
            mypos++; tim += 2;
            maxmypos = max(maxmypos, mypos);
        }
        mypos = curpos;*/
        mypos++;// maxmypos = max(mypos, maxmypos); tim += 2;
        int maxr = 0;
        for (int i = 0; i < traps[mypos].size(); i++) {
            if (traps[mypos][i].d > minv) maxr = max(maxr, traps[mypos][i].r);
        }
        while (mypos < maxr) {
            mypos++;
            for (int i = 0; i < traps[mypos].size(); i++) {
                if (traps[mypos][i].d > minv) maxr = max(maxr, traps[mypos][i].r);
            }
        }
        tim += 2 * (mypos - curpos);
        maxmypos = max(maxmypos, mypos);
        mypos = curpos;
    }
    //printf("%d: %d\n", cnt, tim);
    return tim <= t;
}

int main()
{
    scanf("%d%d%d%d", &m, &n, &k, &t);
    for (int i = 1; i <= m; i++) {
        scanf("%d", a + i);
    }
    for (int i = 1; i <= k; i++) {
        int l, r, d; Trap tr;
        scanf("%d%d%d", &l, &r, &d);
        tr.l = l;
        tr.r = r;
        tr.d = d;
        traps[l].push_back(tr);
        maxdanger[l] = max(maxdanger[l], d);
        rs[r].push_back(tr);
    }
    a[0] = 1000000000;
    sort(a + 1, a + m + 1, cmp);
    int l = 0, r = m;
    while (l < r) {
        int mid = (l + r) / 2 + 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    printf("%d", l);
    return 0;
}