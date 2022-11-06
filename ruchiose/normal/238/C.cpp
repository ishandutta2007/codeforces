#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int MAXN = 3010;
const int MAXE = MAXN << 1;

int N, i, j;
int e[MAXE][3], enxt[MAXE], head[MAXN], ec;

void regi(int u, int v, int w)
{
    ec++;
    e[ec][0] = u; e[ec][1] = v; e[ec][2] = w;
    enxt[ec] = head[u]; head[u] = ec;
}

int up[MAXN], down[MAXN], f[MAXN], snr[MAXN], sib[MAXN], c[MAXN];
int dfl[MAXN], d0;

void dfs(int cur, int fid, int co)
{
    dfl[++d0] = cur;
    f[cur] = fid;
    sib[cur] = snr[fid];
    snr[fid] = cur;
    c[cur] = co;
    for (int E = head[cur]; E; E = enxt[E])
        if (e[E][1] != fid)
            dfs(e[E][1], cur, e[E][2]);
}

int subprocess(int a_root)
{
    int i;
    d0 = 0;
    fortodo(i, 0, N) snr[i] = 0;
    dfs(a_root, 0, 0);
    for (i = N; i; i--)
        {
            int cur = dfl[i];
            up[cur] = 0;
            for (j = snr[cur]; j; j = sib[j])
                up[cur] += c[j] + up[j];
        }
    for (i = N; i; i--)
        {
            int cur = dfl[i];
            down[cur] = up[cur];
            for (j = snr[cur]; j; j = sib[j])
                down[cur] = min(down[cur], up[cur] - (up[j] + c[j]) + (1 - c[j]) + down[j]);
        }
    int ans = min(up[a_root], down[a_root]);
    fortodo(i, 2, N)
        ans = min(ans, down[i] + up[a_root] - (up[i] + c[i]));
    return ans;
}

int main()
{
    scanf("%d", &N);
    fortodo(i, 1, N) head[i] = 0; ec = 0;
    fortodo(i, 2, N)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            regi(u, v, 0);
            regi(v, u, 1);
        }
    int ans = N;
    fortodo(i, 1, N) ans = min(ans, subprocess(i));
    printf("%d\n", ans);
}