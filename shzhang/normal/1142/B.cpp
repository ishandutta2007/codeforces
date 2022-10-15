#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[200005];
int p[200005];
int perm_nxt[200005];
int perm_end[200005][18];
int nxt[200005][18];
vector<int> idx[200005];
int log_2[200005];

int n, m, q;

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++) scanf("%d", p + i);
    for (int i = 2; i <= n; i++) {
        perm_nxt[p[i-1]] = p[i];
    }
    perm_nxt[p[n]] = p[1];
    //for (int i = 1; i <= n; i++) printf("%d ", perm_nxt[i]);
    for (int i = 1; i <= m; i++) scanf("%d", a + i);
    for (int i = m; i >= 1; i--) {
        if (idx[perm_nxt[a[i]]].size()) {
            nxt[i][0] = idx[perm_nxt[a[i]]][idx[perm_nxt[a[i]]].size()-1];
        } else {
            nxt[i][0] = 0;
        }
        idx[a[i]].push_back(i);
    }
    for (int pwr = 1; pwr < 18; pwr++) {
        for (int i = 1; i <= m; i++) {
            nxt[i][pwr] = nxt[nxt[i][pwr-1]][pwr-1];
        }
    }
    for (int i = 1; i <= m; i++) {
        int cur = i;
        for (int j = 0; (1 << j) <= (n-1); j++) {
            if ((n-1) & (1 << j)) cur = nxt[cur][j];
        }
        if (cur == 0) {
            perm_end[i][0] = 100000000;
        } else {
            perm_end[i][0] = cur;
        }
    }
    //for (int i = 1; i <= m; i++) printf("%d ", nxt[i][1]);
    for (int pwr = 1; pwr < 18; pwr++) {
        for (int i = 1; i <= m; i++) {
            perm_end[i][pwr] = min(perm_end[i][pwr-1],
                i + (1<<(pwr-1)) <= m ? perm_end[i + (1<<(pwr-1))][pwr-1] : 100000000);
        }
    }
    for (int i = 1; i <= m; i++) {
        while ((1 << log_2[i]) <= i) log_2[i]++;
        log_2[i]--;
    }
    for (int i = 1; i <= q; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        int l2 = log_2[r-l+1];
        int rmq = min(perm_end[l][l2], perm_end[r-(1<<l2)+1][l2]);
        if (rmq <= r) {
            printf("1");
        } else {
            printf("0");
        }
    }
    return 0;
}