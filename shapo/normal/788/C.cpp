#include <bits/stdc++.h>

using namespace std;

typedef vector< int > vi;

const int SHIFT = 1111;

int dist[SHIFT * 2 + 1], q[SHIFT * 2 + 1];
int qh, qt;
int cnt[SHIFT];

int
compute(const vi &vols)
{
    memset(dist, -1, sizeof(dist));
    qh = qt = 0;
    for (int x : vols) {
        dist[x + SHIFT] = 1;
        q[qt++] = x;
    }
    while (qh < qt) {
        int p = q[qh++];
        for (int x : vols) {
            int np = p + x;
            if (np >= -SHIFT && np <= SHIFT && dist[np + SHIFT] == -1) {
                dist[np + SHIFT] = dist[p + SHIFT] + 1;
                q[qt++] = np;
            }
        }
    }
    return dist[0 + SHIFT];
}

int
main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; ++i) {
        int a;
        scanf("%d", &a);
        cnt[a] = 1;
    }
    vi vols;
    for (int i = 0; i < SHIFT; ++i) {
        if (cnt[i]) {
            vols.push_back(i - n);
        }
    }
    int ret = compute(vols);
    printf("%d\n", ret);
    return 0;
}