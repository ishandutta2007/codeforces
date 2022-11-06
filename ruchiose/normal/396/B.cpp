#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int P[20001];
bool isp[50001];

void Ersieve()
{
    int i, j;
    int n = 50000;
    fortodo(i, 2, n) isp[i] = true;
    P[0] = 0;
    fortodo(i, 2, n)
        if (isp[i])
            {
                P[++P[0]] = i;
                for (j = i * 2; j <= n; j += i) isp[j] = false;
            }
}

bool primejudge(int v)
{
    for (int i = 1; P[i] * P[i] <= v; i++)
        if (v % P[i] == 0)
            return false;
    return true;
}

i64 Euclid(i64 a, i64 b)
{
    return (b) ? Euclid(b, a % b) : a;
}

int main()
{
    Ersieve();
    int _;
    for (scanf("%d", &_); _; _--)
        {
            int N;
            scanf("%d", &N);
            int pre, suc;
            for (pre = N; !primejudge(pre); pre--);
            for (suc = N + 1; !primejudge(suc); suc++);
            // 1/2 - 1/pre + (n - pre + 1) * (1/pre*suc)
            i64 Up = (i64)pre * suc - 2ll * suc + 2ll * (N - pre + 1);
            i64 Down = 2ll * pre * suc;
            i64 E = Euclid(Up, Down);
            Up /= E; Down /= E;
            printf("%I64d/%I64d\n", Up, Down);
        }
}