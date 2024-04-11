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

int n;
int a[200005];
int b[200005];
int freq[200005];
vector<int> graph[200005];
int indeg[200005];
int f[200005];
bool hasin[200005], hasout[200005];

void cleanup()
{
    for (int i = 1; i <= n; i++) {
        freq[i] = 0; graph[i].clear();
        indeg[i] = 0; hasin[i] = hasout[i] = false;
    }
}

void work()
{
    scanf("%d", &n);
    int maxfreq = 0, freqval = 0, freqcnt = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", b + i);
        freq[a[i]]++;
        maxfreq = max(maxfreq, freq[a[i]]);
    }
    for (int i = 1; i <= n; i++) {
        if (freq[i] == maxfreq) {
            freqval = i; freqcnt++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] != freqval && b[i] != freqval) {
            graph[a[i]].push_back(b[i]);
            indeg[b[i]]++;
        }
        if (a[i] == freqval && b[i] == freqval && freqcnt > 1) {
            printf("WA\n"); return;
        }
        if (a[i] == freqval) {
            hasin[b[i]] = true;
        }
        if (b[i] == freqval) {
            hasout[a[i]] = true;
        }
    }
    queue<int> topo;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) topo.push(i);
    }
    vector<int> result;
    while (!topo.empty()) {
        int x = topo.front();
        result.push_back(x);
        topo.pop();
        for (int i = 0; i < graph[x].size(); i++) {
            int nxt = graph[x][i];
            indeg[nxt]--;
            if (indeg[nxt] == 0) topo.push(nxt);
        }
    }
    if (result.size() < n) {
        printf("WA\n"); return;
    }
    for (int i = 1; i <= n; i++) {
        f[i] = 10000000;
    }
    int mincnt = 10000000;
    for (int idx = 0; idx < n; idx++) {
        int i = result[idx];
        if (i == freqval) continue;
        if (hasin[i]) {
            f[i] = min(f[i], (freq[i] == maxfreq ? 1 : 0));
        }
        for (int j = 0; j < graph[i].size(); j++) {
            int nxt = graph[i][j];
            if (freq[nxt] == maxfreq) {
                f[nxt] = min(f[nxt], f[i] + 1);
            } else {
                f[nxt] = min(f[nxt], f[i]);
            }
        }
        if (hasout[i]) {
            mincnt = min(mincnt, f[i]);
        }
    }
    /*printf("! %d\n", freqval);
    for (int i = 1; i <= n; i++) {
        printf("%d ", f[i]);
    }*/
    if (mincnt < freqcnt - 1) {
        printf("WA\n");
    } else {
        printf("AC\n");
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        work(); cleanup();
    }
    return 0;
}