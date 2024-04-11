#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

#define ll long long

int n, k;
int ans = 2000000000;
int graph[85][85];
vector<int> bestmid[85][85];
int from, to;
int choice[10];

bool cmp(int a, int b)
{
    return graph[from][a] + graph[a][to] < graph[from][b] + graph[b][to];
}

void search(int idx)
{
    if (idx == k / 2) {
        choice[0] = choice[idx] = 1;
        int curans = 0;
        for (int i = 0; i < idx; i++) {
            vector<int>& bm = bestmid[choice[i]][choice[i+1]];
            int bestlen = 2000000000;
            for (int j = 0; j < bm.size(); j++) {
                int midpt = bm[j]; bool good = true;
                for (int x = 0; x < idx; x++) {
                    if (choice[x] == midpt) {good = false; break;}
                }
                if (good) {
                    bestlen = graph[choice[i]][midpt] + graph[midpt][choice[i+1]];
                    break;
                }
            }
            if (bestlen == 2000000000) return;
            curans += bestlen;
        }
        ans = min(ans, curans);
    } else {
        for (int i = 1; i <= n; i++) {
            choice[idx] = i;
            search(idx + 1);
        }
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &(graph[i][j]));
        }
    }
    if (k == 2) {
        for (int i = 2; i <= n; i++) {
            ans = min(ans, graph[1][i] + graph[i][1]);
        }
        printf("%d", ans);
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int mid = 1; mid <= n; mid++) {
                if (mid == i || mid == j) continue;
                bestmid[i][j].push_back(mid);
            }
            from = i, to = j;
            sort(bestmid[i][j].begin(), bestmid[i][j].end(), cmp);
        }
    }
    search(1);
    printf("%d", ans);
    return 0;
}