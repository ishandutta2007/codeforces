#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int MAXN = 100010;
const int MAXE = MAXN << 1;

int N, i, j, A[MAXN];
int e[MAXE][2], enxt[MAXE], head[MAXN], ec;

void regi(int a, int b)
{
    ec++;
    e[ec][0] = a; e[ec][1] = b;
    enxt[ec] = head[a]; head[a] = ec;
}

i64 uni[MAXN], sum[MAXN];

i64 Euclid(i64 a, i64 b)
{
    return (b) ? Euclid(b, a % b) : a;
}

i64 lcm(i64 a, i64 b)
{
    return a / Euclid(a, b) * b;
}

void dfs(int cur, int fid)
{
    sum[cur] = A[cur]; uni[cur] = 1;
    vector<int> s;
    s.clear();
    for (int E = head[cur]; E; E = enxt[E])
        if (e[E][1] != fid)
            {
                dfs(e[E][1], cur);
                s.push_back(e[E][1]);
            }
    if (s.empty()) return;
    int i, ss = s.size();
    fortodo(i, 0, ss - 1)
        if (sum[s[i]] == 0)
            {
                sum[cur] = 0;
                return;
            }
    i64 glo = 1, mininum = 0x3FFFFFFFFFFFFFFFll;
    fortodo(i, 0, ss - 1)
        {
            glo = lcm(glo, uni[s[i]]);
            mininum = min(mininum, sum[s[i]]);
        }
    uni[cur] = glo * ss;
    sum[cur] = (mininum / glo) * uni[cur];
}

int main()
{
    scanf("%d", &N);
    fortodo(i, 1, N) scanf("%d", &A[i]);
    fortodo(i, 1, N) head[i] = 0; ec = 0;
    fortodo(i, 2, N)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            regi(u, v); regi(v, u);
        }
    dfs(1, 0);
    i64 ret = - sum[1];
    fortodo(i, 1, N) ret += A[i];
    cout << ret << endl;
}