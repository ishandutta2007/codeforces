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

int n, k;
char s[300005];
int subset1[300005];
int subset2[300005];

vector<int> black[300005];
vector<int> white[300005];
int black_wt[300005];
int white_wt[300005];

bool isblack[300005];
int leader[300005];
int weight[300005];

int ans = 0;

void un(int a, int b, bool same)
{
    int a_isblack = isblack[a];
    int b_isblack = isblack[b];
    a = leader[a]; b = leader[b];
    if (a == b) return;
    //printf("working %d %d %d\n", a, b, same);
    if (black[a].size() + white[a].size() > black[b].size() + white[b].size()) {
        int t = a; a = b; b = t;
    }
    ans -= min(black_wt[a], white_wt[a]);
    ans -= min(black_wt[b], white_wt[b]);
    if (((int)a_isblack) ^ ((int)b_isblack) ^ (1 - (int)same)) {
        //printf("PATH A\n");
        for (int i = 0; i < black[a].size(); i++) {
            white[b].push_back(black[a][i]); isblack[black[a][i]] = false;
            white_wt[b] += weight[black[a][i]];
        }
        for (int i = 0; i < white[a].size(); i++) {
            black[b].push_back(white[a][i]); isblack[white[a][i]] = true;
            black_wt[b] += weight[white[a][i]];
        }
    } else {
        //printf("PATH B\n");
        for (int i = 0; i < black[a].size(); i++) {
            black[b].push_back(black[a][i]);
            black_wt[b] += weight[black[a][i]];
        }
        for (int i = 0; i < white[a].size(); i++) {
            white[b].push_back(white[a][i]);
            white_wt[b] += weight[white[a][i]];
        }
    }
    for (int i = 0; i < black[a].size(); i++) {
        leader[black[a][i]] = b;
    }
    for (int i = 0; i < white[a].size(); i++) {
        leader[white[a][i]] = b;
    }
    //printf("new wts %d: %d %d\n", b, black_wt[b], white_wt[b]);
    black[a].clear(); white[a].clear();
    ans += min(black_wt[b], white_wt[b]);
}

int main()
{
    scanf("%d%d", &n, &k);
    scanf("%s", s + 1);
    weight[0] = 1000000000;
    for (int i = 1; i <= k; i++) {
        weight[i] = 1;
        int c;
        scanf("%d", &c);
        for (int j = 1; j <= c; j++) {
            int member; scanf("%d", &member);
            if (subset1[member]) {
                subset2[member] = i;
            } else {
                subset1[member] = i;
            }
        }
    }
    for (int i = 0; i <= k; i++) {
        leader[i] = i; black[i].push_back(i); isblack[i] = true;
        black_wt[i] = 1;
    }
    black_wt[0] = 1000000000;
    for (int i = 1; i <= n; i++) {
        if (subset1[i]) un(subset1[i], subset2[i], s[i] - '0');
        printf("%d\n", ans);
    }
    return 0;
}