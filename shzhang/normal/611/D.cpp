
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <utility>

using namespace std;

#define ll long long

int n;
int score[5005][5005];
int f[5005][5005];
char str[5005];
int seq[5005];

#define MOD 1000000007

/* - -> less, 0 -> equal, + -> greater */

int cmp(pair<int, int> a, pair<int, int> b)
{
    /*if (a.second - a.first != b.second - b.first) {
        return a.second - a.first - (b.second - b.first);
    }
    int siz = a.second - a.first;*/
    if (score[a.first][a.second - 1] != score[b.first][b.second - 1]) {
        return score[a.first][a.second - 1] - score[b.first][b.second - 1];
    }
    return seq[a.second] - seq[b.second];
}

bool cmp2(pair<int, int> a, pair<int, int> b)
{
    return cmp(a, b) < 0;
}

int scmax = 0;

int main()
{
    scanf("%d", &n);
    scanf("%s", str + 1);
    for (int i = 1; i <= n; i++) seq[i] = str[i] - '0';
    for (int siz = 1; siz <= n; siz++) {
        vector<pair<int, int> > prs;
        for (int i = 1; i + siz - 1 <= n; i++) {
            prs.push_back(make_pair(i, i + siz - 1));
        }
        sort(prs.begin(), prs.end(), cmp2);
        for (int i = 0; i < prs.size(); i++) {
            if (i == 0 || cmp(prs[i-1], prs[i]) < 0) scmax++;
            score[prs[i].first][prs[i].second] = scmax;
        }
    }
    for (int i = 0; i < 5005; i++) f[0][i] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            f[i][j] = f[i][j-1];
            if (seq[i-j+1] == 0) continue;
            if (i - 2*j >= 0 && score[i-2*j+1][i-j] < score[i-j+1][i]) {
                f[i][j] += f[i-j][j];
            } else {
                f[i][j] += f[i-j][j-1];
            }
            if (f[i][j] >= MOD) f[i][j] -= MOD;
        }
        for (int j = i + 1; j < 5005; j++) f[i][j] = f[i][j-1];
    }
    printf("%d", f[n][5004]);
    return 0;
}