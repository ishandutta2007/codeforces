#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, M, K, i, j, u, v;
int bel[20001][11];
int ans[20001], cnt[11];

int main()
{
    scanf("%d%d%d", &N, &M, &K);
    fortodo(i, 1, N) ans[i] = 0;
    fortodo(i, 1, M) cnt[i] = 0;
    fortodo(i, 1, N)
        fortodo(j, 1, M)
            scanf("%d", &bel[i][j]);
    fortodo(i, 1, K)
        {
            scanf("%d%d", &u, &v);
            ans[u]--; 
            cnt[v]++;
        }
    fortodo(i, 1, N)
        fortodo(j, 1, M)
            if (bel[i][j])
                ans[i] += cnt[j];
    fortodo(i, 1, N)
        printf("%d%s", ans[i], (i == N) ? "\n" : " ");
}