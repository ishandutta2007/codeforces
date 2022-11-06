#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int s = 1000000;
const int h = s / 2;

int N, i, j, u, p[500001], cf;
int ans[500001], M;

int main()
{
    scanf("%d", &N);
    fortodo(i, 1, h) p[i] = 0;
    fortodo(i, 1, N)
        {
            scanf("%d", &u);
            if (u <= h)
                p[u] |= 1;
            else
                p[s + 1 - u] |= 2;
        }
    cf = 0;
    fortodo(i, 1, h)
        if (p[i] == 3)
            cf++;
    M = 0;
    fortodo(i, 1, h)
        {
            if (p[i] == 1) ans[++M] = s + 1 - i;
            if (p[i] == 2) ans[++M] = i;
            if ((cf) && (p[i] == 0))
                {
                    ans[++M] = s + 1 - i;
                    ans[++M] = i;
                    cf--;
                }
        }
    sort(ans + 1, ans + M + 1);
    printf("%d\n", M);
    fortodo(i, 1, M)
        printf("%d%s", ans[i], (i == M) ? "\n" : " ");
}