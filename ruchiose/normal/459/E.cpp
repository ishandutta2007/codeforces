// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

typedef pair<int,int> PII;
const int MAXN = 300010;

vector<PII> dp[MAXN];
pair<int,PII> E[MAXN];
int N, M;

void Add(int u, int v, int w)
{
    int r;
    if (dp[u].back().first == w)
        r = dp[u][dp[u].size() - 2].second + 1;
    else
        r = dp[u].back().second + 1;
    if (dp[v].back().first == w)
        dp[v].back().second = max(dp[v].back().second, r);
    else
        dp[v].push_back(make_pair(w, max(dp[v].back().second, r)));
}

bool operator < (pair<int,PII> lhs, pair<int,PII> rhs)
{
    return lhs.first < rhs.first;
}

int main()
{
    scanf("%d%d", &N, &M);
    int i;
    fortodo(i, 1, M) scanf("%d %d %d", &E[i].second.first, &E[i].second.second, &E[i].first);
    fortodo(i, 1, N)
        {
            dp[i].clear();
            dp[i].push_back(make_pair(0, 0));
        }
    sort(E + 1, E + M + 1);
    fortodo(i, 1, M)
        Add(E[i].second.first, E[i].second.second, E[i].first);
    int ans = 0;
    fortodo(i, 1, N)
        ans = max(ans, dp[i].back().second);
    cout << ans << endl;
}